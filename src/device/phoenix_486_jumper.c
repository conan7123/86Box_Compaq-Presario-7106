/*
 * 86Box	A hypervisor and IBM PC system emulator that specializes in
 *		running old operating systems and software designed for IBM
 *		PC systems and compatibles from 1981 through fairly recent
 *		system designs based on the PCI bus.
 *
 *		This file is part of the 86Box distribution.
 *
 *		Implementation of the Phoenix 486 Jumper Readout
 *
 *		Copyright 2020 Tiseno100
 */


#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#define HAVE_STDARG_H
#include <86box/86box.h>
#include "cpu.h"
#include <86box/timer.h>
#include <86box/io.h>
#include <86box/device.h>
#include <86box/chipset.h>

/*
Bit 7 = Super I/O
Bit 6 = ???
Bit 5 = ???
Bit 4 = ???
Bit 3 = ???
Bit 2 = ???
Bit 1 = ???
Bit 0 = ???
*/

typedef struct
{
    uint8_t	jumper;
} phoenix_486_jumper_t;

#ifdef ENABLE_PHOENIX_486_JUMPER_LOG
int phoenix_486_jumper_do_log = ENABLE_PHOENIX_486_JUMPER_LOG;
static void
phoenix_486_jumper_log(const char *fmt, ...)
{
    va_list ap;

    if (phoenix_486_jumper_do_log) {
	va_start(ap, fmt);
	pclog_ex(fmt, ap);
	va_end(ap);
    }
}
#else
#define phoenix_486_jumper_log(fmt, ...)
#endif

static void
phoenix_486_jumper_write(uint16_t addr, uint8_t val, void *priv)
{
    phoenix_486_jumper_t *dev = (phoenix_486_jumper_t *) priv;
    phoenix_486_jumper_log("Phoenix 486 Jumper: Write %02x\n", val);
    dev->jumper = val;
}

static uint8_t
phoenix_486_jumper_read(uint16_t addr, void *priv)
{
    phoenix_486_jumper_t *dev = (phoenix_486_jumper_t *) priv;
    phoenix_486_jumper_log("Phoenix 486 Jumper: Read %02x\n", dev->jumper);
    return dev->jumper;
}


static void
phoenix_486_jumper_close(void *priv)
{
    phoenix_486_jumper_t *dev = (phoenix_486_jumper_t *) priv;

    free(dev);
}

static void *
phoenix_486_jumper_init(const device_t *info)
{
    phoenix_486_jumper_t *dev = (phoenix_486_jumper_t *) malloc(sizeof(phoenix_486_jumper_t));
    memset(dev, 0, sizeof(phoenix_486_jumper_t));

    dev->jumper = info->local;

    io_sethandler(0x0078, 0x0001, phoenix_486_jumper_read, NULL, NULL, phoenix_486_jumper_write, NULL, NULL, dev);

    return dev;
}

const device_t phoenix_486_jumper_device = {
    "Phoenix 486 Jumper Readout",
    0,
    0,
    phoenix_486_jumper_init, phoenix_486_jumper_close, NULL,
    NULL, NULL, NULL,
    NULL
};
