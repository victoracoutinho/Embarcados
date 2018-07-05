#define PIC_NAME "img"
#define PIC_LOCATION "imgs/img.jpg"

#define CMD_CHDK_PTP "./chdkptp-r795_raspi/chdkptp.sh"
#define CMD_CONNECT_CAMERA (CMD_CHDK_PTP " -e\"c\"")
#define CMD_DISCONNECT_CAMERA (CMD_CHDK_PTP " -c -e\"dis\"")
#define CMD_TAKE_PHOTO (CMD_CHDK_PTP " -c -e\"rs imgs/img\"")
#define CMD_ENTER_REC_MODE (CMD_CHDK_PTP " -c -e\"rec\"")
#define CMD_ENTER_PLAY_MODE (CMD_CHDK_PTP " -c -e\"play\"")

#define TESS_LANG_POR "por"

#define TESS_OUT_FILE "saida"
#define TESS_OUT_FILE_NAME (TESS_OUT_FILE ".txt")

#define ESPEAK_VOICE_PTBR0 "pt-br"
#define ESPEAK_VOICE_PTBR1 "mb-br1"
