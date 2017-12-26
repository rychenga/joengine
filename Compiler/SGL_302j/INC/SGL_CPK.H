/*******************************************************************
*
*                       Cinepak for SATURN Player 
*                                by SOJ
*
*                      Copyright(c) 1994,1995 SEGA
*
*   Comment: ���p�җp�w�b�_
*   File   : SEGA_CPK.H
*   Date   : 1995-10-05
*   Version: 1.20
*   Author : Y.T
*
*******************************************************************/
#ifndef SEGA_CPK_H
#define SEGA_CPK_H


/*-------------------------- �s�����I���t --------------------------*/

/* �R�[�h�u�b�N�A�h���X�e�[�u�����g�p����
 * �@�����L���ɂ���ꍇ�́Acpk_ra15.src cpk_er15.src �������ɂP��
 *   �錾���邱��
 */
/* #define CPK_USE_CBTBL */


/*-------------------- �s�C���N���[�h�t�@�C���t --------------------*/
#include <sega_xpt.h>
#if 0
#include <sega_gfs.h>
#include <sega_stm.h>
#else
#include <sgl_cd.h>
#endif


/*------------------------- �s�}�N���萔�t -------------------------*/

/* �o�[�W���� */
#define CPK_VERSION				("CPK Version 1.20 1995-10-05")
							/*	           1         2         3         4	*/
							/*	  1234567890123456789012345678901234567890	*/
							/*	  ++++++++++++++++++++++++++++++++			*/
#define CPK_VERSION_LEN			(32)

/* �n���h������ */
#define CPK_HN_MAX				(32)

/* �G���[�R�[�h	*/
typedef enum {
	CPK_ERR_OK					= 0x00000000,/* �G���[�͔������Ă��Ȃ�		*/

	/* CPK_Create �̃G���[ */
	CPK_ERR_OUT_OF_HANDLE		= 0x00000101,/* �n���h������؂� 			*/
	CPK_ERR_TOO_SMALL_BUF		= 0x00000102,/* �ݸ��ޯ̧���ނ�����������	*/
	CPK_ERR_NO_INIT				= 0x00000103,/* �������֐�����ق���ĂȂ� 	*/

	/* CPK_Destroy �̃G���[ */
	CPK_ERR_INVALID_HN			= 0x00000201,/* �s���ȃn���h���ŏ���		*/
	CPK_ERR_ILL_CREATE_MODE		= 0x00000202,/* Create ���̃��[�h�ƈႤ		*/

	/* cpk_HeaderProcess �̃G���[ */
	CPK_ERR_TOO_SMALL_FLOP		= 0x00000301,/* FLOP�����l������������		*/
	CPK_ERR_TOO_LARGE_HEADER	= 0x00000302,/* �w�b�_�����傷����			*/
											/* (�ݸ��ޯ̧���ނ�����������)	*/
	CPK_ERR_HEADER_DATA			= 0x00000303,/* �w�b�_�f�[�^�G���[ 			*/
	CPK_ERR_TOO_SMALL_PCMBUF	= 0x00000304,/* PCM�ޯ̧���ނ�����������	*/
	CPK_ERR_ILL_SIZE_PCMBUF		= 0x00000305,/* PCM�ޯ̧���ޕs�� 4096*2�`16	*/

	/* cpk_VideoSample �̃G���[ */
	CPK_ERR_SAMPLE_ID			= 0x00000401,/* ���ʎq�G���[�B00h,01h �ȊO���*/
	CPK_ERR_SAMPLE_DATA			= 0x00000402,/* �s���f�[�^�B				*/

	/*  */
	CPK_ERR_ILLEGAL_PARA		= 0x00000503,/* �������̎w�肪�Ԉ���Ă��� 	*/
	CPK_ERR_ILLEGAL_HANDLE		= 0x00000504,/* �n���h�����ُ� 				*/

	/* �A���Đ��Ɋւ���G���[ */
	CPK_ERR_NEXT_MOVI_STATUS	= 0x00000601,/* �A���Đ�Ѱ�ް�̏�Ԉُ� 	*/
	CPK_ERR_NEXT_MOVI_AUDIO		= 0x00000602,/* �I�[�f�B�I�̏�������v���Ȃ� */
	CPK_ERR_NEXT_MOVI_SCALE		= 0x00000603,/* �^�C���X�P�[������v���Ȃ� 	*/
	CPK_ERR_CHANGE_NO_DATA		= 0x00000604,/* �f�[�^�����s����ԂŃ`�F���W */
	CPK_ERR_CHANGE_NO_ENTRY		= 0x00000605,/* �G���g�����Ȃ���ԂŃ`�F���W */

	/* �|�[�Y�Ɋւ���G���[ */
	CPK_ERR_PAUSE_STATUS		= 0x00000701,/* CPK_STAT_PLAY_TIME, �܂��́A
											 * CPK_STAT_PLAY_PAUSE �ȊO��
											 * ��ԂŃ|�[�Y�֐����R�[�������B
											 */

	/* DMA�]���Ɋւ���G���[ */
	CPK_ERR_DMA_MODE			= 0x00000801,/* ���Ή��̓]������ 			*/
	CPK_ERR_DMA_CPU_PCM			= 0x00000802,/* CPUDMA���ُ�I�� 			*/

	/* �t�@�C���ǂݍ��݃G���[ */
	CPK_ERR_GFS_READ			= 0x00000901,/* �f�e�r�̓ǂݍ��݂Ŏ��s 		*/
	CPK_ERR_STM_FAD				= 0x00000902,/* STM�]���֐���,fad������ 	*/
	CPK_ERR_STM_HN				= 0x00000903,/* STM�]���֐���,STM����وُ� 	*/

	/* CPK_DecodeFrame�Ɋւ���G���[ */
	CPK_ERR_DF_NO_DATA			= 0x00000A01,/* �w�b�_���̃f�[�^�������Ȃ� 	*/
	CPK_ERR_DF_IS_NOT_VIDEO		= 0x00000A02,/* �r�f�I�T���v���łȂ� 		*/


	CPK_ERR_END
} CpkErrCode;

/* �Đ��X�e�[�^�X */
typedef enum {
	CPK_STAT_PLAY_ERR_STOP		= -1,		/* �ُ��~					*/
	CPK_STAT_PLAY_STOP			= 0,		/* ��~(�N���G�C�g) 		*/
	CPK_STAT_PLAY_PAUSE			= 1,		/* �ꎞ��~		 			*/
	CPK_STAT_PLAY_START			= 2,		/* �J�n						*/
	CPK_STAT_PLAY_HEADER		= 3,		/* �w�b�_�����@				*/
	CPK_STAT_PLAY_TIME			= 4,		/* �Đ���(�^�C�}�X�^�[�g)	*/
	CPK_STAT_PLAY_END			= 5			/* �Đ����� 				*/
} CpkPlayStatus;

/* �ꎞ��~�̐���R�}���h */
typedef enum {
	CPK_PAUSE_ON_AT_ONCE,					/* �����ꎞ��~ 			*/
	CPK_PAUSE_ON_KEYFRAME,					/* �L�[�t���[���҂��ꎞ��~	*/
	CPK_PAUSE_OFF							/* �ꎞ��~���� 			*/
} CpkPauseCmd;

/* �\���F��[bit] */
typedef enum {
	CPK_COLOR_24BIT				= 24,		/* 1600���F 				*/
	CPK_COLOR_15BIT				= 15		/* 32000�F 					*/
} CpkColorType;

/* �����؂�ւ��\���`�F�b�N�l */
typedef enum {
	CPK_CHANGE_OK_AT_ONCE		= 0,	/* �����؂�ւ��\�B			*/
	CPK_CHANGE_NO_DATA			= 1,	/* �f�[�^�����s���B				*/
	CPK_CHANGE_NO_ENTRY			= 2,	/* �G���g���������B				*/
	CPK_CHANGE_TOO_LARGE_HEADER	= 3		/* �w�b�_�����傷����B			*/
										/* (�o�b�t�@�T�C�Y������������)	*/
} CpkChangeStatus;

/* �摜�L���^�C�~���O�̐ݒ�l */
typedef enum {
	CPK_DEC_TIMING_DECODE_IN_HASTE = 0,	/* ��肠�����L�����Ă���		*/
	CPK_DEC_TIMING_WAIT_AND_DECODE = 1	/* �\��������҂��ĐL������		*/
} CpkDecTiming;

/* �f�[�^�̓]������ */
typedef enum {
	CPK_TRMODE_CPU = 0,					/* �\�t�g�E�F�A�]�� 			*/
	CPK_TRMODE_SDMA,					/* �c�l�`�T�C�N���X�`�[�� 		*/
	CPK_TRMODE_SCU,						/* �r�b�t�̂c�l�`				*/
	CPK_TRMODE_SCUDSPDMA				/* �r�b�t�|�c�r�o�̂c�l�`		*/
} CpkTrMode;

/* [����1] �]�������̐ݒ�ɂ͎��̕\�Ɏ�������������܂��B
 *�@�@�@�@�@�@�@�@�@�@�@�f�[�^�]�������̐ݒ�̐���
 *  ====================+=================================================
 *     �����@�_�@����   |  ��ĳ���]��  CPU��DMA  SCU��DMA  SCU-DSP��DMA
 *  ====================+=================================================
 *    CPK_SetTrModeCd   |      ��         ��        ��          �~
 *    CPK_SetTrModePcm  |      ��         ��        �~          ��
 *  ====================+=================================================
 * [����2] �]�������� CPK_TRMODE_SCUDSPDMA ���w�肳��Ă���ƁA������ԂƂ��āA
 *  SCU-DSP �̎g�p���� Cinepakײ���� �ɂ���܂��BSCU-DSP �� Cinepakײ���� �� 
 *  ���ع���� �̗����ŗ��p����ꍇ�ɂ� CPK_AllocScuDsp, CPK_FreeScuDsp ���g��
 *  �܂��B
 */

/* �S�a�x�s�d�����R�[�h�� Uint32 �^�ŕ\������B
 *   ('cvid'�ȂǂƏ�����ܰ�ݸނ��o�Ă��܂��̂ŁA�����������邽�߂�)
 */
#define CPK_4BYTE_CHAR(a,b,c,d)					\
	(	((Uint32)((a) & 0x000000FF) << 24) | 	\
		((Uint32)((b) & 0x000000FF) << 16) | 	\
		((Uint32)((c) & 0x000000FF) <<  8) | 	\
		 (Uint32)((d) & 0x000000FF)				\
	)

/* ���k���� */
typedef enum {
	CPK_CTYPE_NOVIDEO 	= 0,								/* �摜�Ȃ� 	*/
	CPK_CTYPE_NONE 		= CPK_4BYTE_CHAR('r','a','w',' '),	/* �񈳏k 		*/
	CPK_CTYPE_CVID 		= CPK_4BYTE_CHAR('c','v','i','d'),	/* Cinepak���k 	*/
	CPK_CTYPE_END
} CpkCType;

/* �b�o�t�g�p���� */
typedef enum {
	CPK_CPU_MAIN 		= 1, 		/* main cpu only (default)			*/
	CPK_CPU_SLAVE 		= 2, 		/* slave cpu only (Not supported) 	*/
	CPK_CPU_DUAL 		= 3, 		/* dual cpu 						*/
	CPK_CPU_END
} CpkCpu;
/* [����] 
 *  �b�o�t�g�p������ CPK_CPU_DUAL ���w�肳��Ă���ƁAslave cpu �� Cinepak
 *  ײ���� ����L���܂��B���ع���݂� slave cpu �𗘗p���邱�Ƃ͂ł��܂���B
 */


/*---------------------- �s�e��f�t�H���g�l�t ----------------------*/

/* �N���}�L�[�J�b�g�I�t�̃f�t�H���g�l */
#define CPK_DEFAULT_CKEY_CUTOFF_15		(3 * 7)
#define CPK_DEFAULT_CKEY_CUTOFF_24		(CPK_DEFAULT_CKEY_CUTOFF_15 * 8)

/* �������̃f�t�H���g�l [1/s] */
#define CPK_DEFAULT_SILENCE_RATE	(8)

/* �Đ����x�̃f�t�H���g�l(�ʏ�̍Đ����x) */
#define CPK_SPEED_ORIGINAL		(0)

/* �Đ����x�̐ݒ�P�� */
#define CPK_SPEED_UNIT			(1024)

/* �f�o�b�O���̏o�͊J�n�A�h���X�i�f�t�H���g�l�j */
#define CPKD_START_ADDR			(0x04000000)

/* �f�o�b�O���̏o�͏I���A�h���X�i�f�t�H���g�l�j */
#define CPKD_END_ADDR			(0x047FFFF0)

/* �f�o�b�O���̏o�͊J�n�ʒu�̃}�[�W��[dword] */
#define CPKD_HEAD_MARGIN		(4)

/* CPKD�V�X�e���\���̂̎��ʕ����� [dword], [byte] */
#define CPKD_STRING_LEN			(4)
#define CPKD_STRING_LEN_BYTE	(4 * CPKD_STRING_LEN)


/*------------------------- �s�����}�N���t -------------------------*/
/* �쐬�p�����[�^�ւ̃A�N�Z�X�}�N�� */
#define	CPK_PARA_WORK_ADDR(para)	((para)->work_addr)
#define	CPK_PARA_WORK_SIZE(para)	((para)->work_size)
#define	CPK_PARA_BUF_ADDR(para)		((para)->buf_addr)
#define	CPK_PARA_BUF_SIZE(para)		((para)->buf_size)
#define	CPK_PARA_PCM_ADDR(para)		((para)->pcm_addr)
#define	CPK_PARA_PCM_SIZE(para)		((para)->pcm_size)

/* �n���h���A�N�Z�X */
#define	CPK_HN_DONT_DEC_VIDEO(hn) ((*(CpkWork **)(hn))->status.dont_dec_video)

/* Code1Book�̃T�C�Y [byte],[dbyte] */
#define CPK_BSIZE_CODE1BOOK				(0x800)
#define CPK_BSIZE_CODE1BOOK_FUL			(2 * CPK_BSIZE_CODE1BOOK)
#define CPK_DSIZE_CODE1BOOK				(CPK_BSIZE_CODE1BOOK     / 4)
#define CPK_DSIZE_CODE1BOOK_FUL			(CPK_BSIZE_CODE1BOOK_FUL / 4)

/* �Q�S�������t���J���[�p�̃��[�N�o�b�t�@�T�C�Y */
#define	CPK_24WORK_BSIZE	sizeof(CpkWork)
#define	CPK_24WORK_DSIZE	((CPK_24WORK_BSIZE + 3) / 4)

/* �P�T�������J���[�p�̃��[�N�o�b�t�@�T�C�Y */
#define	CPK_15WORK_BSIZE	(sizeof(CpkWork) - (4 * CPK_BSIZE_CODE1BOOK))
#define	CPK_15WORK_DSIZE	((CPK_15WORK_BSIZE + 3) / 4)

/* CPKD�V�X�e���\���̃A�N�Z�X */
#define CPKD_SYS_STRING			(cpkd_sys.string)
#define CPKD_SYS_MODE			(cpkd_sys.mode)
#define CPKD_SYS_START_ADDR		(cpkd_sys.start_addr)
#define CPKD_SYS_END_ADDR		(cpkd_sys.end_addr)
#define CPKD_SYS_PRINT_ADDR		(cpkd_sys.print_addr)
#define CPKD_SYS_RETURN_CNT		(cpkd_sys.return_cnt)


/*-------------------------- �s�f�[�^�^�t --------------------------*/
/* ���[�r�n���h�� */
typedef void *CpkHn;

/* �쐬�p�����[�^ */
typedef struct {
	Uint32		*work_addr;		/* ���[�N�̐擪�A�h���X */
								/* �{���C�u���������[�r���Đ����鎞�̍�Ɨ̈�*/
	Uint32		work_size;		/* ���[�N�̃o�C�g�� */
								/* CPK_BSIZE_WORK ���w�肷�� */
	Uint32		*buf_addr;		/* Ѱ��̧�ق��i�[����o�b�t�@�̐擪�A�h���X */
								/* �������̃��[�r�t�@�C���̎��͂��̃A�h���X */
								/* CD�̃��[�r�t�@�C���̎����ݸ��ޯ̧�̱��ڽ */
	Uint32		buf_size;		/* �o�b�t�@�T�C�Y */
								/* �������̃��[�r�t�@�C���̎��̓t�@�C���T�C�Y*/
								/* CD�̃��[�r�t�@�C���̎����ݸ��ޯ̧�̃T�C�Y */
	Uint16		*pcm_addr;		/* �T�E���h��������PCM�o�b�t�@�A�h���X 		*/
	Uint32		pcm_size;		/* �T�E���h��������PCM�o�b�t�@�T�C�Y		*/
								/* (1ch���̃T���v����(4096*1..4096*16))		*/
} CpkCreatePara;


/* �t�B�����T���v���e�[�u������ */
typedef struct {
	Uint32		offset;				/* ���f�B�A�J�n�ʒu����̃I�t�Z�b�g */
	Sint32		size;				/* �T���v���T�C�Y 					*/
	Sint32		time;				/* �t���[���\�������A-1:���ި������ */
	Sint32		duration;			/* �t���[���\���������� 			*/
} CpkFilmSample;


/* �t�B�����w�b�_ */
typedef struct {
	/* FilmHeader */
	Uint32		film;				/* "FILM" 								*/
	Uint32		size_header;		/* �w�b�_�T�C�Y(���f�B�A�J�n�ւ̵̾��)	*/
	Uint32		version;			/* �o�[�W���� 							*/
	Uint32		reserved;			/* �\�� 								*/
	/* FrameDescription */
	Uint32		fdsc;				/* "FDSC" 								*/
	Uint32		size_fdsc;			/* FDSC�T�C�Y 0x0000001C = 7*4[byte]	*/
	CpkCType	c_type;				/* ���k���� "cvid" 						*/
	Uint32		height;				/* ���ĕ�[pixel]						*/
	Uint32		width;				/* �悱��[pixel] 						*/
	Uint8		color;				/* �\���F��[bit] 						*/
	Uint8		sound_channel;		/* �`���l���� 							*/
	Uint8		sound_smpling_bit;	/* �T���v�����O�r�b�g��[bit] 			*/
	Uint8		sound_compress;		/* ���k 00h:���� 01h:ADPCM 				*/
	Uint32		sound_smpling_rate;	/* �����ݸ�ڰ�[Hz] ���ʂQbyte�͏��� 	*/
	Uint32		ckey;				/* �N���}�L�[���	 					*/
	/* FilmSampleTable */
	Uint32		stab;				/* "STAB" 								*/
	Uint32		size_stab;			/* STAB�T�C�Y (������ِ�+1)*16[byte] 	*/
	Uint32		time_scale_film;	/* �^�C���X�P�[�� 						*/
	Uint32		sample_total;		/* ���T���v���� 						*/
	CpkFilmSample sample[1];		/* �T���v���e�[�u�� �C�ӃT�C�Y 			*/
} CpkHeader;

/* �G���[�o�^�֐� */
typedef void (*CpkErrFunc)(void *obj, Sint32 err_code);


/* �p�����[�^ */
typedef struct {
	Uint32		AddrBuf;		/* �o�b�t�@�J�n�ʒu�B�V���̏ꍇ 0x4000000 	*/
	Uint32		SizeBuf;		/* �o�b�t�@�T�C�Y�B�@�V���̏ꍇ 0x1000000 	*/
	Uint32		size_trigger;	/* �Đ��J�n�g���K�T�C�Y						*/
	Uint32		AddrVram;		/* �摜�o�̓A�h���X 						*/
	Uint32		SizeVramLine;	/* �摜�o�̓o�b�t�@�s�T�C�Y[byte]			*/
	/* �T�E���h�h���C�o�֘A */
	Uint32		play_pcm;		/* PCM�Đ��t���O 0:���̏����Ȃ� 1:�Đ�		*/
	Uint32		command_blk_no;	/* �T�E���h�h���C�o�R�}���h�u���b�N�ԍ� 	*/
	Uint32		pcm_stream_no;	/* PCM�X�g���[���Đ��ԍ� 					*/
	Uint16		*addr_pcmbuf;	/* �������؂�PCM�o�b�t�@�A�h���X 			*/
	Uint32		size_pcmbuf;	/* �������؂�PCM�o�b�t�@�T�C�Y[sample/1ch] 	*/
	Uint32		pcm_pan;		/* 0..31	*/
	Uint32		pcm_level;		/* 0..7		*/
	Uint32		frequency_vbl;	/* CPK_VblIn()���R�[��������g��[256*Hz] 	*/
} CpkPara;

/* DMA�]����� */
typedef struct {
	Uint32		dst;				/* �]����A�h���X 						*/
	Uint32		src;				/* �]�����A�h���X 						*/
	Uint32		cnt;				/* �]���� 							*/
} CpkDmaStock;

/* �e���� */
typedef struct {
	/* �S�̐����� */
	Sint32		stat_start;			/* �X�e�[�^�X�̊J�n						*/
	Sint32		play;				/* �Đ���� 							*/
	Uint32		RequestDispFrame;	/* �t���[���\���v���t���O 				*/
	Uint32		CntSample;			/* �T���v���J�E���^ 					*/
	Uint32		CntFrame;			/* �t���[���J�E���^ 					*/
	Uint32		offset_media;		/* ���f�B�A�J�n�ʒu�ւ̃I�t�Z�b�g		*/
	Uint32		display_keyframe;	/* �\���摜�L�[�t���[���t���O 			*/
	Uint32		standby_keyframe;	/* �ҋ@�摜�L�[�t���[���t���O 			*/
	Uint32		standby_video_flag;	/* �\���ҋ@�摜����t���O 				*/
	Uint32		standby_time_display;/* �ҋ@�摜�̕\������					*/
	Uint32		standby_time_duration;/* �ҋ@�摜�̕\����������				*/
	Uint32		only_audio;			/* flag that only audio sample 			*/
	Uint32		only_video;			/* flag that only video sample 			*/
	Uint32		color;				/* �o�͐F��[bit]�B15 or 24				*/
	Uint32		wait_keyframe_to_pause;/* �ꎞ��~�����p���ڰё҂��t���O 	*/
	Uint32		wait_and_decode;	/* 1:�\��������҂��Ă���L������		*/
	Sint32		flag_prohibit_komaotoshi;/* 1:�R�}���Ƃ�kinnshi�t���O		*/
	Sint32		ckey_cutoff;		/* chroma key cutoff level 				*/
	Sint32		final_audio_sample;	/* �Ō�̃I�[�f�B�I�T���v�� 			*/
	Sint32		silence_rate;		/* ������ [1/s]							*/
	
	/* �����O�o�b�t�@������ */
	Sint32		ring_start;			/* �̊J�n								*/
	Uint32		OffsetWrite;		/* �o�b�t�@�ǂ݁E�����ʒu[byte]			*/
	Uint32		OffsetRead;			/* (�t�@�C���擪����̃I�t�Z�b�g)		*/
	Uint32		AddrWrite;			/* �o�b�t�@�ǂ݁E�����ʒu(�A�h���X)		*/
	Uint32		AddrRead;			/* 										*/
	Uint32		AddrRing;			/* �����O�o�b�t�@�J�n�A�h���X 			*/
	Uint32		AddrRingEnd;		/* �����O�o�b�t�@�I���A�h���X 			*/
	Sint32		SizeHead;			/* �w�b�_�o�b�t�@�T�C�Y [byte] ��������{ */
	Uint32		SizeRing;			/* �����O�o�b�t�@�T�C�Y [byte] ��������{ */
	Uint32		SizeFlop;			/* �e�k�n�o�o�b�t�@�T�C�Y [byte] 		*/
	
	/* PCM�Đ���� */
	Sint32		audio_start;		/* �̊J�n								*/
	Uint32		play_pcm;			/* PCM�Đ��t���O 0:���̏����Ȃ� 1:�Đ�	*/
	Uint32		bsize_pcmbuf;		/* �������؂�PCM�o�b�t�@�T�C�Y[byte/1ch]*/
	Uint16		*addr_pcmbuf_end;	/* PCM�o�b�t�@�I���A�h���X 				*/
	Uint16		*addr_pcm_write;	/* PCM�o�b�t�@�������݃A�h���X 			*/
	Uint32		smpling_rate;		/* �����ݸ�ڰ�[Hz] ���ʂPbyte�͏��� 	*/
	Uint32		cnt_4ksample;		/* PCM play address 4k����ْP�ʍX�V���� */
	Sint32		flag_fill_silence;	/* �����ݒ�ς݃t���O					*/
	Sint32		sample_write;		/* �����T���v����[sample]				*/
									/* (�擪̨�т���̌��݂܂ł̑�������)	*/
	Sint32		sample_film_start;	/* �t�B�����J�n���T���v����[sample]		*/
									/* (�擪̨�т��猻��̨�ъJ�n���_�܂ł�)	*/
	Sint32		sample_pause;		/* �|�[�Y���T���v����[sample]			*/
									/* (�擪̨�т���ŋ߂̃|�[�Y���_�܂ł�)	*/
	Sint32		count_start;		/* �b�o�t�N���b�N�^�C�}�J�n���� 		*/
									/* 						[CPU�ۯ�>>15] 	*/
	Sint32		clock_scale;		/* �b�o�t�N���b�N�^�C�}�̃X�P�[�� 		*/
	Sint32		dont_stop_pcm;		/* �I������PCM�X�g�b�v���Ȃ��t���O 		*/

	/* �����[�r�[�Ǘ���� */
	Sint32		next_start;			/* �̊J�n								*/
/*	CpkHn		hn_next;*/			/* ���n���h��(���o�^�C�J�n��� NULL) 	*/
	CpkHn		hn_next_start;		/* ���n���h��(�J�n��) 					*/
	Sint32		dont_dec_video;		/* �I������PCM�X�g�b�v���Ȃ��t���O 		*/
	
	
	/* PCM�f�[�^�̂c�l�`�]���Ɋւ����� */
	Sint32		cppcm_start;		/* �̊J�n								*/
	CpkTrMode	copy_mode_pcm;		/* �f�[�^�̓]������ 					*/
	Uint32		flag_dma_hold;		/* 1:���̃��[�r�[��DMA������ێ����Ă���*/
	Uint32		pcm_renew_size;		/* DMA�I����pcm�ޯ̧���������߲���X�V����*/
	Uint32		buf_renew_size;		/* DMA�I�����ޯ̧�ǂݎ���߲���X�V���� 	*/
	Uint32		idx_dma_pcm_tbl;	/* dma_pcm_tbl �̃C���f�b�N�X 			*/
	CpkDmaStock	dma_pcm_tbl[4];		/* DMA�]�����G���g���e�[�u�� 			*/
	
	/* ���ԊǗ����(�r�f�I�̂݃��[�r�[�p) */
	Sint32		time_start;			/* �̊J�n								*/
									/* 95-08-17 Y.T : CPK_SetSpeed �Ή� 	*/
									/*   Vbl����������ٖ��Ɏ���				*/
	Sint32		cnt_vbl_in;			/* Vlb-In ���荞�݃J�E���^[vbl]			*/
	Sint32		vblcnt_regulator;	/* Vlb-In �J�E���^�Đ����x���ߊ�		*/
	Sint32		vbl_film_start;		/* �t�B�����J�n����[vbl] 				*/
	Sint32		vbl_pause;			/* �|�[�Y�J�n����[vbl] 					*/
	Sint32		vbl_pcm_start;		/* PCM�J�n����[vbl]
									 * �ŏ��̍��� cnt_4ksample ������Ķ���
									 * ���߂��Ȃ��悤�ɁB
									 */
	Sint32		time_frame;			/* �\�������t���[���̕\�������{��������	*/

	/* �Đ����x�Ǘ���� */
	Sint32		speed;				/* �Đ����x[�Γ�����~1024] 			*/
	Bool		audio_sw;			/* �Đ����x�ύX���̵��ި��o�ͽ���		*/

	/* �G���[��� */
	Uint32		err_start;			/* �G���[���̊J�n                     */
	Uint32		CntLossFrame;		/* �R�}�����J�E���^ 					*/
	Uint32		CntPcmLoadMiss;		/* PCM���[�h�~�X�J�E���^ 				*/
	Uint32		CntCallTask;		/* �^�X�N�R�[���J�E���^ 				*/
	Uint32		CntOverCallTask;	/* �ߏ�^�X�N�R�[���J�E���^ 			*/
	Uint32		cnt_buf_empty;		/* �o�b�t�@��^�X�N�J�E���^ 			*/
	Uint32		max_late_time;		/* �ő�x�ꎞ��[�t�B�������ԒP��] 		*/
	Uint32		max_late_frame;		/* �ő�x��t���[���ԍ�					*/
} CpkStatus;


/* �t�@�C���A�N�Z�X�֌W */
typedef struct {
	GfsHn		gfs;			/* �t�@�C���n���h�� */
	Sint32		load_sect;		/* �]���ő�Z�N�^�� */
	Bool		called_cdread;	/* GFS_NwCdRead ���R�[�������� TRUE */
	Bool		exec_one_state;	/* ExecOne ���s���Ȃ� TRUE */
	Sint32		exec_load_size;	/* ExecOne �œǂݍ��ރo�C�g�� */
	Sint32		now_load_size;	/* ExecOne �œǂݍ���ł���o�C�g�� */
	Sint32		load_total_sect;/* �ǂݍ��ݑ��Z�N�^�� */
	Sint32		file_sect;		/* �t�@�C���̃Z�N�^�� */
	Sint32		tr_mode;		/* �]�����[�h */
} CpkFileGfsPara;

typedef struct {
	StmHn		stm;			/* �X�g���[���n���h�� */
	Sint32		load_sect;		/* �]���ő�Z�N�^�� */
	Sint32		old_cd_buf_num;	/* �O��̂b�c�o�b�t�@�̐� */
	Bool		dma_state;		/* �c�l�`�]�����Ă���Ȃ� TRUE */
	Sint32		dma_sect;		/* �c�l�`�]������Z�N�^�� */
	Uint32		*write_addr;	/* �������ރA�h���X */
	Sint32		buf_bsize;		/* �󂫃o�b�t�@�̃o�C�g�� */
	Sint32		write_bsize;	/* �]�������o�C�g�� */
	Sint32		load_total_sect;/* �ǂݍ��ݑ��Z�N�^�� */
	StmTrFunc	load_func;		/* �]���֐� */
} CpkFileStmPara;

typedef struct {
	Sint32		faccess_type;		/* �t�@�C���A�N�Z�X�^�C�v */
	/* �t�@�C�����[�J���f�[�^ */
	union	{
		CpkFileGfsPara	gfs;
		CpkFileStmPara	stm;
	} data;
} CpkFilePara;

/* ���s�֐� */
typedef struct {
	void	(*start)(CpkHn cpk);
	void	(*task)(CpkHn cpk);
	Sint32	(*preload_movie)(CpkHn cpk, Sint32 size);
	void	(*set_load_num)(CpkHn cpk, Sint32 load_sct);
	void	(*set_trmode)(CpkHn cpk, CpkTrMode mode);
	void	(*get_stock_size)(CpkHn cpk, Sint32 *ring_bsize, Sint32 *all_bsiz);
	void	(*get_stock_time)(CpkHn cpk, Sint32 *ring_time, Sint32 *all_time);
} CpkExecFunc;


typedef struct {
	Sint32		work_start;				/* ���[�N�̊J�n					*/
	CpkPara 	para;					/* �b�������������N���p�����[�^ */
	CpkStatus 	status;					/* �e���ԁi���J�����j 		*/
	CpkHeader 	*header;				/* �t�B�����t�@�C���w�b�_ 		*/
	CpkFilePara	filepara;				/* �t�@�C���A�N�Z�X�p�����[�^	*/
	CpkExecFunc	execfunc;				/* ���s�֐�						*/
#ifdef CPK_USE_CBTBL
	Uint32		*cbtblp[4];				/* �����ޯ����ڽð��ْ����߲�� 	*/
	Uint32		cbtbl1a[256];			/* �����ޯ����ڽð��� 			*/
	Uint32		cbtbl2a[256];			/* 								*/
	Uint32		cbtbl1b[256];			/* 								*/
	Uint32		cbtbl2b[256];			/* 								*/
#endif
	Uint32 		code_book[4 * CPK_DSIZE_CODE1BOOK_FUL];
										/* ��i code1book, code2book	*/
										/* ���i code1book, code2book	*/
} CpkWork;


/* CPKD�V�X�e���\���� */
typedef struct {
	Sint32 string[CPKD_STRING_LEN];	/* ���ʕ����� */
	Sint32 mode;					/* �o�̓��[�h �O�F�o�͂��Ȃ�(�f�t�H���g) */
	Sint32 *start_addr;				/* �o�̓A�h���X�̐擪 */
	Sint32 *end_addr;				/* �o�̓A�h���X�̖��� */
	Sint32 *print_addr;				/* ���݂̏o�̓A�h���X */
	Sint32 return_cnt;				/* �܂�Ԃ��J�E���^ */
} CpkdSys;


/*------------------------ �s�f�o�b�O�p�錾�t ------------------------*/

/* CPKD�V�X�e���\���� */
extern CpkdSys cpkd_sys;

/* �f�o�b�O�o�̓��[�h�̐ݒ�@0N:�o�͂���, OFF:�o�͂��Ȃ�(��̫��) */
void CPKD_SetMode(Bool mode);

/* �f�o�b�O�o�̓A�h���X�̐ݒ� */
void CPKD_SetPrintAddr(Sint32 *start, Sint32 *end);

/* �f�o�b�O������̏o��(�����񒷂͂S�̐����{�ɋK�i�������) */
void CPKD_PrintStr(char *str);

/* �f�o�b�O�f�[�^�̏o��(�S�o�C�g) */
void CPKD_PrintData(Sint32 data);


/*-------------------------- �s�֐��錾�t --------------------------*/

/* ���C�u�����̏����� */
Bool CPK_Init(void);

/* ���C�u�����̏I������ */
void CPK_Finish(void);

/* �n���h���̍쐬�i�������j */
CpkHn CPK_CreateMemMovie(CpkCreatePara *para);

/* �n���h���̏����i�������j */
void CPK_DestroyMemMovie(CpkHn cpk);

/* �n���h���̍쐬�i�t�@�C���V�X�e���j */
CpkHn CPK_CreateGfsMovie(CpkCreatePara *para, GfsHn gfs);

/* �n���h���̏����i�t�@�C���V�X�e���j */
void CPK_DestroyGfsMovie(CpkHn cpk);

/* �n���h���̍쐬�i�X�g���[���V�X�e���j */
CpkHn CPK_CreateStmMovie(CpkCreatePara *para, StmHn stm);

/* �n���h���̏����i�X�g���[���V�X�e���j */
void CPK_DestroyStmMovie(CpkHn cpk);

/* �Đ��^�X�N */
void CPK_Task(CpkHn cpk);

/* �\���^�C�~���O�̔��� */
Bool CPK_IsDispTime(CpkHn cpk);

/* �\���t���[����ʂ̔��� */
Bool CPK_IsKeyframe(CpkHn cpk);

/* �\�������̒ʒm */
void CPK_CompleteDisp(CpkHn cpk);

/* �u�u�����N�h�m�����֐� */
void CPK_VblIn(void);

/* �Đ��J�n */
void CPK_Start(CpkHn cpk);

/* �Đ���~ */
void CPK_Stop(CpkHn cpk);

/* �ꎞ��~ */
Bool CPK_Pause(CpkHn cpk, CpkPauseCmd cmd);

/* ���ɍĐ����郀�[�r�̓o�^ */
void CPK_EntryNext(CpkHn cpk);

/* ���[�r�̋����؂�ւ� */
void CPK_Change(void);

/* ���[�r�̐؂�ւ���Ԃ̎擾 */
CpkChangeStatus CPK_CheckChange(void);

/* �w��t���[���̓W�J */
void CPK_DecodeFrame(CpkHn cpk, Sint32 sample_no);

/* �w��t���[���̓W�J(�����t���[���ۏ�) */
void CPK_DecodeFrameSafety(CpkHn cpk, Sint32 sample_no);

/* �W�J��A�h���X�̐ݒ� */
void CPK_SetDecodeAddr(CpkHn cpk, void *dec_addr, Sint32 dec_line_size);

/* �\���F���̐ݒ� */
void CPK_SetColor(CpkHn cpk, CpkColorType color);

/* �ő�]���Z�N�^���̐ݒ� */
void CPK_SetLoadNum(CpkHn cpk, Sint32 read_sct);

/* �Đ��o�`�m�̐ݒ� */
void CPK_SetPan(CpkHn cpk, Sint32 pan);

/* �Đ��{�����[���̐ݒ� */
void CPK_SetVolume(CpkHn cpk, Sint32 volume);

/* �Đ����x�̐ݒ� */
void CPK_SetSpeed(CpkHn cpk, Sint32 speed, Bool audio_sw);

/* �o�b�l�R�}���h�u���b�N�ԍ��̐ݒ� */
/* void CPK_SetPcmCmdBlockNo(CpkHn cpk, Sint32 blk_no); */

/* �o�b�l�X�g���[���ԍ��̐ݒ� */
void CPK_SetPcmStreamNo(CpkHn cpk, Sint32 stream_no);

/* �L�[�A�E�g�i�����ɂ���F�j�͈͂̐ݒ� */
void CPK_SetKeyOutRange(CpkHn cpk, Sint32 range);

/* �������̐ݒ� */
void CPK_SetSilenceRate(CpkHn cpk, Sint32 silence_rate);

/* �f�[�^�̓]�������̐ݒ�i�b�c�u���b�N�������O�o�b�t�@�j */
void CPK_SetTrModeCd(CpkHn cpk, CpkTrMode mode);

/* �f�[�^�̓]�������̐ݒ�i�����O�o�b�t�@���o�b�l�o�b�t�@�j */
void CPK_SetTrModePcm(CpkHn cpk, CpkTrMode mode);

/* �Đ��J�n�g���K�T�C�Y�̐ݒ� [byte] */
void CPK_SetStartTrgSize(CpkHn cpk, Sint32 bsize);

/* �^�C���X�P�[���̎擾 */
Sint32 CPK_GetTimeScale(CpkHn cpk);

/* �Đ������̎擾 [timescale] */
Sint32 CPK_GetTime(CpkHn cpk);

/* �Đ��X�e�[�^�X�̎擾 */
CpkPlayStatus CPK_GetPlayStatus(CpkHn cpk);

/* �t�B�����w�b�_�̃A�h���X�̎擾 */
CpkHeader *CPK_GetHeader(CpkHn cpk);

/* �������݃o�b�t�@�A�h���X�̎擾 */
Uint32 *CPK_GetWriteBuf(CpkHn cpk, Sint32 *free_size, Sint32 *free_total);

/* �o�b�t�@�ւ̏������݃T�C�Y�̒ʒm */
void CPK_NotifyWriteSize(CpkHn cpk, Sint32 write_size);

/* �������Ƀ��[�r��ǂݍ��� */
Sint32 CPK_PreloadMovie(CpkHn cpk, Sint32 size);

/* �������Ƀt�B�����w�b�_��ǂݍ��� */
Sint32 CPK_PreloadHeader(CpkHn cpk);

/* �G���[�֐��̓o�^ */
void CPK_SetErrFunc(CpkErrFunc func, void *obj);

/* �G���[���̎擾 */
CpkErrCode CPK_GetErr(void);

/* SCU-DSP�����̊m�� */
Sint32 CPK_AllocScuDsp(void);

/* SCU-DSP�����̉�� */
void CPK_FreeScuDsp(void);

/* �b�o�t�g�p�����̐ݒ� */
void CPK_SetCpu(CpkCpu cpu);

/* �X�g���[���T�[�o�֐��̃R�[���̐ݒ� */
void CPK_SetStmServerCall(Bool mode);

/* �f�[�^���~�ʂ̎擾 [byte] */
/* �r�f�k�̂f�e�r�̃o�[�W�������������P�D�Q�P�ȏ�̏ꍇ�̂ݎg�p�\ */
void CPK_GetStockSize(CpkHn cpk, Sint32 *ring_bsize, Sint32 *all_bsize);

/* �f�[�^���~�ʂ̎擾 [timescale] */
/* �r�f�k�̂f�e�r�̃o�[�W�������������P�D�Q�P�ȏ�̏ꍇ�̂ݎg�p�\ */
void CPK_GetStockTime(CpkHn cpk, Sint32 *ring_time, Sint32 *all_time);

#endif /* SEGA_CPK_H */