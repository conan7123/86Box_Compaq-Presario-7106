/* Copyright holders: Sarah Walker, Tenshi
   see COPYING for more details
*/
#define IDM_FILE_RESET     40000
#define IDM_FILE_HRESET    40001
#define IDM_FILE_EXIT      40002
#define IDM_FILE_RESET_CAD 40003
#define IDM_DISC_1         40010
#define IDM_DISC_2         40011
#define IDM_EJECT_1        40012
#define IDM_EJECT_2        40013
#define IDM_HDCONF         40014
#define IDM_DISC_1_WP      40015
#define IDM_DISC_2_WP      40016
#define IDM_CONFIG         40020
#define IDM_CONFIG_LOAD    40021
#define IDM_CONFIG_SAVE    40022
#define IDM_STATUS         40030
#define IDM_VID_RESIZE     40050
#define IDM_VID_REMEMBER   40051
#define IDM_VID_DDRAW      40060
#define IDM_VID_D3D        40061
#define IDM_VID_FULLSCREEN 40070
#define IDM_VID_FS_FULL    40071
#define IDM_VID_FS_43      40072
#define IDM_VID_FS_SQ      40073
#define IDM_VID_FS_INT     40074
#define IDM_VID_FORCE43    40075
#define IDM_VID_OVERSCAN   40076
#define IDM_VID_FLASH      40077
#define IDM_VID_SCREENSHOT 40078
#define IDM_DISC_3         40079
#define IDM_DISC_4         40080
#define IDM_EJECT_3        40081
#define IDM_EJECT_4        40082
#define IDM_DISC_3_WP      40083
#define IDM_DISC_4_WP      40084
#define IDM_CDROM_ISO	   40100
#define IDM_CDROM_EMPTY    40200
#define IDM_CDROM_REAL     40200
#define IDM_CDROM_ENABLED  40300
#define IDM_CDROM_SCSI     40400
#define IDM_SCSI_ENABLED   40500
#define IDM_SCSI_BASE130   40501
#define IDM_SCSI_BASE134   40502
#define IDM_SCSI_BASE230   40503
#define IDM_SCSI_BASE234   40504
#define IDM_SCSI_BASE330   40505
#define IDM_SCSI_BASE334   40506
#define IDM_SCSI_IRQ9      40507
#define IDM_SCSI_IRQ10     40508
#define IDM_SCSI_IRQ11     40509
#define IDM_SCSI_IRQ12     40510
#define IDM_SCSI_IRQ14     40511
#define IDM_SCSI_IRQ15     40512
#define IDM_SCSI_DMA5      40513
#define IDM_SCSI_DMA6      40514
#define IDM_SCSI_DMA7      40515

#define IDC_COMBO1 1000
#define IDC_COMBOVID 1001
#define IDC_COMBO3 1002
#define IDC_COMBO4 1003
#define IDC_COMBO5 1004
#define IDC_COMBO386 1005
#define IDC_COMBO486 1006
#define IDC_COMBOSND 1007
#define IDC_COMBONET 1008
#define IDC_COMBOCPUM 1060
#define IDC_COMBOSPD  1061
#define IDC_COMBODR1  1062
#define IDC_COMBODR2  1063
#define IDC_COMBOJOY  1064
#define IDC_COMBOWS  1065
#define IDC_COMBOMOUSE 1066
#define IDC_COMBODR3  1067
#define IDC_COMBODR4  1068
#define IDC_CHECK1 1010
#define IDC_CHECK2 1011
#define IDC_CHECK3 1012
#define IDC_CHECKGUS 1013
#define IDC_CHECKSSI 1014
#define IDC_CHECKVOODOO 1015
#define IDC_CHECKDYNAREC 1016
#define IDC_STATIC 1020
#define IDC_CHECKSYNC 1024
#define IDC_EDIT1  1030
#define IDC_EDIT2  1031
#define IDC_EDIT3  1032
#define IDC_EDIT4  1033
#define IDC_EDIT5  1034
#define IDC_EDIT6  1035
#define IDC_COMBOHDT	1036
#define IDC_TEXT1  1040
#define IDC_TEXT2  1041
#define IDC_EDITC  1050
#define IDC_CFILE  1051
#define IDC_CNEW   1052
#define IDC_EDITD  1053
#define IDC_DFILE  1054
#define IDC_DNEW   1055
#define IDC_EJECTC 1056
#define IDC_EJECTD 1057
#define IDC_EDITE  1058
#define IDC_EFILE  1059
#define IDC_ENEW   1060
#define IDC_EDITF  1061
#define IDC_FFILE  1062
#define IDC_FNEW   1063
#define IDC_EJECTE 1064
#define IDC_EJECTF 1065
#define IDC_EDITG  1066
#define IDC_GFILE  1067
#define IDC_GNEW   1068
#define IDC_EDITH  1069
#define IDC_HFILE  1070
#define IDC_HNEW   1071
#define IDC_EJECTG 1072
#define IDC_EJECTH 1073
#define IDC_MEMSPIN 1070
#define IDC_MEMTEXT 1071
#define IDC_CHDD   1080
#define IDC_CCDROM 1081
#define IDC_DHDD   1082
#define IDC_DCDROM 1083
#define IDC_EHDD   1084
#define IDC_ECDROM 1085
#define IDC_FHDD   1086
#define IDC_FCDROM 1087
#define IDC_GHDD   1088
#define IDC_GCDROM 1089
#define IDC_HHDD   1090
#define IDC_HCDROM 1091
#define IDC_STEXT1 1100
#define IDC_STEXT2 1101
#define IDC_STEXT3 1102
#define IDC_STEXT4 1103
#define IDC_STEXT5 1104
#define IDC_STEXT6 1105
#define IDC_STEXT7 1106
#define IDC_STEXT8 1107
#define IDC_STEXT_DEVICE 1108
#define IDC_TEXT_MB 1120

#define IDC_EDIT_C_SPT  1200
#define IDC_EDIT_C_HPC  1201
#define IDC_EDIT_C_CYL  1202
#define IDC_EDIT_D_SPT  1203
#define IDC_EDIT_D_HPC  1204
#define IDC_EDIT_D_CYL  1205
#define IDC_EDIT_E_SPT  1206
#define IDC_EDIT_E_HPC  1207
#define IDC_EDIT_E_CYL  1208
#define IDC_EDIT_F_SPT  1209
#define IDC_EDIT_F_HPC  1210
#define IDC_EDIT_F_CYL  1211
#define IDC_EDIT_G_SPT  1212
#define IDC_EDIT_G_HPC  1213
#define IDC_EDIT_G_CYL  1214
#define IDC_EDIT_H_SPT  1215
#define IDC_EDIT_H_HPC  1216
#define IDC_EDIT_H_CYL  1217
#define IDC_TEXT_C_SIZE 1220
#define IDC_TEXT_D_SIZE 1221
#define IDC_TEXT_E_SIZE 1222
#define IDC_TEXT_F_SIZE 1223
#define IDC_TEXT_G_SIZE 1224
#define IDC_TEXT_H_SIZE 1225
#define IDC_EDIT_C_FN   1230
#define IDC_EDIT_D_FN   1231
#define IDC_EDIT_E_FN   1232
#define IDC_EDIT_F_FN   1233
#define IDC_EDIT_G_FN   1234
#define IDC_EDIT_H_FN   1235

#define IDC_CONFIGUREVID 1200
#define IDC_CONFIGURESND 1201
#define IDC_CONFIGUREVOODOO 1202
#define IDC_CONFIGUREMOD 1203
#define IDC_CONFIGURENET 1204
#define IDC_JOY1 1210
#define IDC_JOY2 1211
#define IDC_JOY3 1212
#define IDC_JOY4 1213

#define IDC_CONFIG_BASE 1200

#define WM_RESETD3D WM_USER
#define WM_LEAVEFULLSCREEN WM_USER + 1

#define C_BASE 6		/* End at 38. */
#define D_BASE 60		/* End at 92. */
#define E_BASE 114		/* End at 146. */
#define F_BASE 168		/* End at 200. */
#define G_BASE 222		/* End at 254. */
#define H_BASE 276		/* End at 308. */
#define CMD_BASE 334
#define DLG_HEIGHT 366

