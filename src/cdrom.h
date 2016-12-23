#ifndef __CDROM_H__
#define __CDROM_H__

/*CD-ROM stuff*/
typedef struct CDROM
{
        int (*ready)(void);
        int (*medium_changed)(void);
        int (*readtoc)(uint8_t *b, uint8_t starttrack, int msf, int maxlen, int single);
        int (*readtoc_session)(uint8_t *b, int msf, int maxlen);
        int (*readtoc_raw)(uint8_t *b, int maxlen);
        uint8_t (*getcurrentsubchannel)(uint8_t *b, int msf);
        void (*read_capacity)(uint8_t *b);
	void (*read_header)(uint8_t *in_cdb, uint8_t *b);
        void (*read_disc_information)(uint8_t *b);
	int (*sector_data_type)(int sector, int ismsf);
        void (*readsector_raw)(uint8_t *b, int sector, int ismsf);
        void (*playaudio)(uint32_t pos, uint32_t len, int ismsf);
        void (*seek)(uint32_t pos);
        void (*load)(void);
        void (*eject)(void);
        void (*pause)(void);
        void (*resume)(void);
        uint32_t (*size)(void);
		int (*status)(void);
		int (*is_track_audio)(uint32_t pos, int ismsf);
        void (*stop)(void);
        void (*exit)(void);
} CDROM;

extern CDROM *cdrom;

#endif