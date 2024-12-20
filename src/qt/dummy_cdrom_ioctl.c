/*
 * 86Box    A hypervisor and IBM PC system emulator that specializes in
 *          running old operating systems and software designed for IBM
 *          PC systems and compatibles from 1981 through fairly recent
 *          system designs based on the PCI bus.
 *
 *          This file is part of the 86Box distribution.
 *
 *          Win32 CD-ROM support via IOCTL.
 *
 *
 *
 * Authors: TheCollector1995, <mariogplayer@gmail.com>,
 *          Miran Grca, <mgrca8@gmail.com>
 *
 *          Copyright 2023 TheCollector1995.
 *          Copyright 2023 Miran Grca.
 */
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#define HAVE_STDARG_H
#include <86box/86box.h>
#include <86box/scsi_device.h>
#include <86box/cdrom.h>
#include <86box/plat_unused.h>
#include <86box/plat_cdrom.h>

/* The addresses sent from the guest are absolute, ie. a LBA of 0 corresponds to a MSF of 00:00:00. Otherwise, the counter displayed by the guest is wrong:
   there is a seeming 2 seconds in which audio plays but counter does not move, while a data track before audio jumps to 2 seconds before the actual start
   of the audio while audio still plays. With an absolute conversion, the counter is fine. */
#define MSFtoLBA(m, s, f) ((((m * 60) + s) * 75) + f)

static int toc_valid             = 0;

#ifdef ENABLE_DUMMY_CDROM_IOCTL_LOG
int dummy_cdrom_ioctl_do_log = ENABLE_DUMMY_CDROM_IOCTL_LOG;

void
dummy_cdrom_ioctl_log(const char *fmt, ...)
{
    va_list ap;

    if (dummy_cdrom_ioctl_do_log) {
        va_start(ap, fmt);
        pclog_ex(fmt, ap);
        va_end(ap);
    }
}
#else
#    define dummy_cdrom_ioctl_log(fmt, ...)
#endif

static int
plat_cdrom_open(void)
{
    return 0;
}

static int
plat_cdrom_load(void)
{
    return 0;
}

static void
plat_cdrom_read_toc(void)
{
    if (!toc_valid)
        toc_valid = 1;
}

int
plat_cdrom_is_track_audio(uint32_t sector)
{
    plat_cdrom_read_toc();

    const int ret = 0;

    dummy_cdrom_ioctl_log("plat_cdrom_is_track_audio(%08X): %i\n", sector, ret);

    return ret;
}

int
plat_cdrom_is_track_pre(uint32_t sector)
{
    plat_cdrom_read_toc();

    const int ret = 0;

    dummy_cdrom_ioctl_log("plat_cdrom_is_track_audio(%08X): %i\n", sector, ret);

    return ret;
}

uint32_t
plat_cdrom_get_track_start(uint32_t sector, uint8_t *attr, uint8_t *track)
{
    plat_cdrom_read_toc();

    return 0x00000000;
}

uint32_t
plat_cdrom_get_last_block(void)
{
    plat_cdrom_read_toc();

    return 0x00000000;
}

int
plat_cdrom_ext_medium_changed(void)
{
    int       ret  = 0;

    dummy_cdrom_ioctl_log("plat_cdrom_ext_medium_changed(): %i\n", ret);

    return ret;
}

void
plat_cdrom_get_audio_tracks(int *st_track, int *end, TMSF *lead_out)
{
    plat_cdrom_read_toc();

    *st_track       = 1;
    *end            = 1;
    lead_out->min   = 0;
    lead_out->sec   = 0;
    lead_out->fr    = 2;

    dummy_cdrom_ioctl_log("plat_cdrom_get_audio_tracks(): %02i, %02i, %02i:%02i:%02i\n",
                          *st_track, *end, lead_out->min, lead_out->sec, lead_out->fr);
}

/* This replaces both Info and EndInfo, they are specified by a variable. */
int
plat_cdrom_get_audio_track_info(UNUSED(int end), int track, int *track_num, TMSF *start, uint8_t *attr)
{
    plat_cdrom_read_toc();

    if ((track < 1) || (track == 0xaa)) {
        dummy_cdrom_ioctl_log("plat_cdrom_get_audio_track_info(%02i)\n", track);
        return 0;
    }

    start->min = 0;
    start->sec = 0;
    start->fr  = 2;

    *track_num = 1;
    *attr      = 0x14;

    dummy_cdrom_ioctl_log("plat_cdrom_get_audio_track_info(%02i): %02i:%02i:%02i, %02i, %02X\n",
                          track, start->min, start->sec, start->fr, *track_num, *attr);

    return 1;
}

/* TODO: See if track start is adjusted by 150 or not. */
int
plat_cdrom_get_audio_sub(UNUSED(uint32_t sector), uint8_t *attr, uint8_t *track, uint8_t *index, TMSF *rel_pos, TMSF *abs_pos)
{
    *track = 1;
    *attr = 0x14;
    *index = 1;

    rel_pos->min = 0;
    rel_pos->sec = 0;
    rel_pos->fr  = 0;
    abs_pos->min = 0;
    abs_pos->sec = 0;
    abs_pos->fr  = 2;

    dummy_cdrom_ioctl_log("plat_cdrom_get_audio_sub(): %02i, %02X, %02i, %02i:%02i:%02i, %02i:%02i:%02i\n",
                          *track, *attr, *index, rel_pos->min, rel_pos->sec, rel_pos->fr, abs_pos->min, abs_pos->sec, abs_pos->fr);

    return 1;
}

int
plat_cdrom_get_sector_size(UNUSED(uint32_t sector))
{
    dummy_cdrom_ioctl_log("BytesPerSector=2048\n");

    return 2048;
}

int
plat_cdrom_read_sector(uint8_t *buffer, int raw, uint32_t sector)
{
    plat_cdrom_open();

    if (raw) {
        dummy_cdrom_ioctl_log("Raw\n");
        /* Raw */
    } else {
        dummy_cdrom_ioctl_log("Cooked\n");
        /* Cooked */
    }
    plat_cdrom_close();
    dummy_cdrom_ioctl_log("ReadSector status=%d, sector=%d, size=%" PRId64 ".\n", status, sector, (long long) size);

    return -1;
}

void
plat_cdrom_eject(void)
{
    plat_cdrom_open();
    plat_cdrom_close();
}

void
plat_cdrom_close(void)
{
}

int
plat_cdrom_set_drive(const char *drv)
{
    plat_cdrom_close();

    toc_valid = 0;

    plat_cdrom_load();
    return 1;
}
