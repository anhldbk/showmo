
/*
* @file
*
* @path $(cspclient)
*
* @desc
*
* Copyright (c) Yesod Inc. 9.03.2009
*
* Use of this software is controlled by the terms and conditions found
* in the license agreement under which this software has been supplied
*
*

*
*/


#ifndef __PROTO_H__NjjnddeuiuiuiooiioBJHSDMNMNwhduhqwdBCNASAKDJK78710230909KW_____
#define __PROTO_H__NjjnddeuiuiuiooiioBJHSDMNMNwhduhqwdBCNASAKDJK78710230909KW_____

#include "uu_types.h"

#if defined(_WIN32)
#pragma warning(disable : 4200)
#endif

//For protocol version 
#define   PROTOCOL_VERSION_MAJOR		105
#define   PROTOCOL_VERSION_REVISION      "$Rev: 4831 $"
#define   PROTOCOL_SET_HEADER_VER(pheader)   \
	do{  \
	unsigned short  maj=PROTOCOL_VERSION_MAJOR;\
	unsigned long  rev=0;\
	struct msg_header* __p_header__=(struct msg_header*)pheader;\
	__p_header__->ver=(maj<<16);\
	sscanf(PROTOCOL_VERSION_REVISION,"$Rev: %d", (int*)&rev);\
	__p_header__->ver|=(unsigned int)rev;\
}while(0)
////////////////////////////////////
#define MAX_GET_PARTNER_COUNT 10
#define MAX_CAMERA_NAME_SIZE		64
#define MAX_NICK_NAME_SIZE 32
#define LF_FACESIZE         32

#define SERVER_BROADCAT_ALIVE_TIMEOUT 3
/////////////////////////////////
//right mask defines security_center_admin
//////////////////////////////////////////////
#define		RIGHT_MASK_COMPANY_ADMIN				(1<<0)
#define		RIGHT_MASK_SECURITY_CENTER_ADMIN		(1<<1) 
#define		RIGHT_MASK_OPEN_VOICE					(1<<2) 
#define		RIGHT_MASK_PUBLIC_TALK					(1<<3) 
#define		RIGHT_MASK_PRIVATE_TALK					(1<<4)         

//by 20120802 ������̨����Ȩ��
#define		RIGHT_MASK_CONTROL_DOME					(1<<5)
//by 20210802 ���Ӷ���ʷ��������Ƶ��������Ȩ��
#define		RIGHT_MASK_HISTORY_VIEW					(1<<6)		
/////////////////////////////////////////////
///////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//by 20121205 ����·������
enum PEER_NAT_TYPE
{
	FINE_NAT,	//���ڴ򶴳ɹ���NAT
	BAD_NAT = 10,	//�����ڴ򶴳ɹ���NAT
};
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//by 20121221
enum ORDER_TYPE
{
	SNAP = 1,	//����
};
//////////////////////////////////////////////////////////////////////////

enum PEER_TYPE
{
	CAMERA_PEER,
	USER_PEER,//��ͨ�û�����
	USER_SUPER_PEER,//�û������ڵ�����
	MASTER_SERVER_SUPER_PEER,//�������������ڵ�����
	SLAVE_SERVER_SUPER_PEER,//�������������ڵ�����
	SERVER_BRIDGE_PEER,//������˫���Ž�����
};

enum NET_TYPE
{
	NET_UNKNOWN,//δ֪
	NET_TEL,//����
	NET_CNC,//��ͨ
	NET_EDU,//������
	NET_CHIWALL,//����
	NET_TV,//����ͨ
};


enum FRAME_TYPE
{
	IFRAME,
	PFRAME,
	BFRAME,
	FRAME_TYPE_G711A=3,
	FRAME_JPEG = 4,
	FRAME_TYPE_PCMU =10,			
	FRAME_TYPE_PCMA =18,			
	FRAME_TYPE_G7231 =14,		
	FRAME_TYPE_G722 =19,			
	FRAME_TYPE_G728 =25,			
	FRAME_TYPE_G729 =28,			
	FRAME_TYPE_RAWAUDIO =29,	
	FRAME_TYPE_ADPCM =30,		
	FRAME_TYPE_ADPCM_HISI =31,
	FRAME_TYPE_AUDIO_HAIK = 32,	
	FRAME_TYPE_ALARM_JPEG =61,
	FRAME_TYPE_MP3 =106
};

enum CSP_ERRORS
{
	RESPONSE_OK =0,
	RESPONSE_FAILED=1,

	CSP_ERROR_SUCCESS,
	//user  			[100,200)
	CSP_ERROR_NAME_REPEATED = 100,
	CSP_ERROR_GET_USER_DETAIL,
	CSP_ERROR_USER_NAME_NOTEXIST,
	CSP_ERROR_UESR_NAME_NULL,
	CSP_ERROR_USER_KEY_WRONG,
	CSP_ERROR_USER_GET_DEVICE_LIST,

	CSP_ERROR_USER_TYPE_WRONG,	 //�û����ʹ���	��������˺�,�����˺Ż���
	CSP_ERROR_USER_NO_DEMO_USER, //���޲����˺�	��������˺�

	//custom  			[200,300)
	CSP_ERROR_GET_CUSTOMER_DETAIL = 200,
	CSP_ERROR_GET_CUSTOMER_GROUPS,
	CSP_ERROR_GET_CUSTOMER_LIST,
	CSP_ERROR_CUSTOM_GET_DEVICE_LIST,
	CSP_ERROR_CUSTOM_GET_USER_LIST,
	//register,login  	[300,400)
	CSP_ERROR_REGISTER_MSG_NULL = 300,
	CSP_ERROR_RESETKEY_MSG_NULL,
	CSP_ERROR_LOGIN_FAILED,
	//device     		[400,500)
	CSP_ERROR_GET_DEVICE_ID = 400,
	CSP_ERROR_ADD_DEVICE,
	CSP_ERROR_GET_DEVICE,
	CSP_ERROR_DEL_DEVICE,
	CSP_ERROR_GET_DEVICE_DETAIL,
	CSP_ERROR_DEVICE_GET_CAMERA_LIST,
	CSP_ERROR_DEVICE_GET_CUSTOM,
	CSP_ERROR_DEVICE_STATUS_NOTEXIST,
	CSP_ERROR_DEVICE_STATUS_ADDED,
	CSP_ERROR_DEVICE_STATUS_ABANDONED,
	CSP_ERROR_DEVICE_STATUS_WRONG,
	//camera   			[500,600)
	CSP_ERROR_GET_CAMERA_DETAIL = 500,
	CSP_ERROR_CAMERA_GET_CUSTOM,
	//terminaldevice   	[600,700)
	CSP_ERROR_TERMINAL_DEVICE_NULL = 600,
	CSP_ERROR_TERMINAL_DEVICE_EXISTED,
	CSP_ERROR_TERMINAL_DEVICE_NOTEXIST,
	CSP_ERROR_GET_TERMINAL_DEVICE,
	//terminalexception [700,800)
	CSP_ERROR_ADD_TERMINAL_EXCEPTION = 700,
	//verifycode  		[800,900)
	CSP_ERROR_SEND_VERIFYCODE = 800,
	CSP_ERROR_VERIFYCODE_NULL,
	CSP_ERROR_VERIFYCODE_WRONG,
	//app  				[900,1000)
	CSP_ERROR_GET_APPVERSION = 900,
	//MOD 2014.12.8

	//old				[1000,1100)
	CSP_ERROR_JOIN_DEPARTMENT = 1000,
	CSP_ERROR_GET_DEPARTMENTS,
	CSP_ERROR_DEL_EMPLOYEE,
	CSP_ERROR_GET_AUTH_CAMERAS,
	CSP_ERROR_GET_RIGHTS,
	CSP_ERROR_UPDATE_USER,
	CSP_ERROR_GET_ADMIN_FAILED,
	CSP_ERROR_ADMIN_NOT_ONLINE,
	CSP_ERROR_QUERY_FROM_STATUS_FAILED,

	//״̬������		[1100,1200)
	CSP_STATE_START_LOOK_CAMERA_OK = 1100,
	CSP_STATE_GET_PARTNERS_FAILED,
	CSP_STATE_ASK_BAKFRAME_FAILED,
	CSP_STATE_ASK_INIT_BUF_FAILED,
	CSP_STATE_MGR_SIGN_IN_OK,
	CSP_STATE_MGR_SIGN_IN_FAILED,
	CSP_STATE_VD_SIGN_IN_OK,
	CSP_STATE_VD_SIGN_IN_FAILED,
	CSP_STATE_MGR_CLIENT_ONLINE_OK,
	CSP_STATE_MGR_CLIENT_ONLINE_FAILED,

	//other 			[1200,1300)
	CSP_ERROR_INVALID_SESSION_ID = 1200,
	
	CSP_ERROR_DOMAIN = 1250,
    CSP_ERROR_NO_INIT = 1500,
	CSP_ERROR_MGR_NOLINK = 1501,
	CSP_ERROR_VIDEO_NOLINK = 1502,
	CSP_ERROR_IPC_NOLINK = 1503,
	CSP_ERROR_LOGIN_NOLINK = 1504,
	CSP_ERROR_IPC_NOIP = 1505,
	CSP_ERROR_IPC_CONN = 1506,
	CSP_ERROR_LOGIN_CONN = 1507,

	CSP_ERROR_SOCKET_CREATE = 2000,
	CSP_ERROR_SOCKET_CONNECT = 2001,
	CSP_ERROR_SOCKET_BIND = 2002,
	CSP_ERROR_SEND_FAILED = 2003,
	CSP_ERROR_MEMORY_ERROR = 2004,
	CSP_ERROR_DEVICE_OFFLINE = 2005,
	CSP_ERROR_DATA_NOMATCH = 3000, 
	CSP_ERROR_ILLEGAL_PARAM = 4000,
	CSP_ERROR_TIMEOUT = 5000,
	CSP_ERROR_PICDOWNING = 6000,
	CSP_ERROR_LOGIN_REPEAT,
};

enum CSP_CAMERA_VISIBLE_LEVEL
{
	CSP_CAMERA_PUBLIC,
	CSP_CAMERA_PROTECTED,
	CSP_CAMERA_PRIVATE
};

enum CSP_CAMERA_ERRORS
{
	CSP_ERROR_NO_FRAME,
};

enum CONNECT_VIDEO_TYPE
{
	CONNECT_VIDEO_NORMAL,
	CONNECT_VIDEO_REALTIME,
	CONNECT_VIDEO_HISTORY,
	CONNECT_VIDEO_DOWNLOADFILE,	//�����ļ�
	CONNECT_VIDEO_REALTIME_ALARM,
};

enum PIC_PARAM_TYPE
{
	PIC_BRIGHTNESS = 0,
	PIC_CONTRAST,
	PIC_HUE,
	PIC_SATURATION,
};

enum VIDEO_FLOW_TYPE
{
	FLOW_VIDEO = 0,						//video flow
	FLOW_MUTI,							//multiple flow(both video and audio)
};

enum VIDEO_BITRATE_TYPE
{
	VIDEO_BITRATE_FIXED = 0,					//fixed bit rate
	VIDEO_BITRATE_VARIABLE,					//variable bit rate
};

enum VIDEO_BITRATE
{
	VIDEO_BITRATE_64 = 64,					//64kbps
	VIDEO_BITRATE_128 = 128,					//128kbps
	VIDEO_BITRATE_256 = 256,					//256kbps
	VIDEO_BITRATE_384 = 384,					//384kbps
	VIDEO_BITRATE_512 = 512,					//512kbps
	VIDEO_BITRATE_768 = 768,					//768kbps
	VIDEO_BITRATE_1024 = 1024,				//1Mbps
	VIDEO_BITRATE_1536 = 1536,				//1.5Mbps
	VIDEO_BITRATE_2048 = 2048,				//2Mbps
};

enum VIDEO_QUALITY
{
	VIDEO_QUALITY_BEST = 0,				//best video quality
	VIDEO_QUALITY_BETTER,				//better video quality
	VIDEO_QUALITY_GOOD,					//good video quality
	VIDEO_QUALITY_NORMAL,				//normal video quality
	VIDEO_QUALITY_BAD,					//bad video quality
	VIDEO_QUALITY_WORSE,				//worse video quality
};

enum VIDEO_FRAMERATE
{
	VIDEO_FRAMERATE_25 = 25,					//25f/s
	VIDEO_FRAMERATE_20 = 20,					//20f/s
	VIDEO_FRAMERATE_15 = 15,					//15f/s
	VIDEO_FRAMERATE_10 = 10,					//10f/s
	VIDEO_FRAMERATE_5 = 5,					//5f/s
	VIDEO_FRAMERATE_2 = 2,					//2f/s
	VIDEO_FRAMERATE_1 = 1,					//1f/s
};

enum HIST_LOOK_TYPE
{
	HISTORY_LOOK_NORMAL = 0,			//����������ʷ��Ƶ
	HISTORY_LOOK_FORCE,				//ǿ�ƿ���ʷ
};

enum HIST_DOWNLOAD_TYPE
{
	HISTORY_DOWNLOAD_NORMAL = 0,			//��������������ʷ��Ƶ
	HISTORY_DOWNLOAD_FORCE,					//ǿ������������ʷ
};

enum HIST_LOOK_REPONSE
{
	HISTORY_LOOK_RESPONSE_SUCCESS = 0,			//����ɹ�
	HISTORY_LOOK_RESPONSE_ALREADY_OPEN,			//�Ѿ������ڿ���ʷ����һ����ͬһcamera��
    HISTORY_LOOK_RESPONSE_HASREALTIME,			//�����ڿ�ʵʱ��Ƶ
	HISTORY_LOOK_RESPONSE_HASDOWNLOAD,			//������������Ƶ
	HISTORY_LOOK_RESPONSE_VS_UNREACHABLE,		//��Ƶ����������ʧ��
	HISTORY_LOOK_RESPONSE_HASALARM,				//�б�����Ƶ
};

enum CLOSE_VIDEO_REASON
{
	CLOSE_VIDEO_NORMAL = 0,			 //�����ر�
	CLOSE_VIDEO_HAS_HISTORY,		 //����Ҫ����ʷ
	CLOSE_VIDEO_HAS_DOWNLOAD,		 //����Ҫ������ʷ
	CLOSE_VIDEO_HAS_ALARM,			//�б�����Ƶ
};

enum PUSH_DATA_RESPONSE
{
	PUSH_DATA_RESPONSE_NORMAL = 0,			 //�����ر�
	PUSH_DATA_RESPONSE_HAS_HISTORY,		 //����Ҫ����ʷ
	PUSH_DATA_RESPONSE_HAS_DOWNLOAD,		 //����Ҫ������ʷ
	PUSH_DATA_RESPONSE_HAS_ALARM,			//�б�����Ƶ
};

enum CONNECT_VIDEO_RESPONSE
{
	CONNECT_VIDEO_RESPONSE_SUCCESS = 0,			 //�ɹ�
	CONNECT_VIDEO_RESPONSE_MORE_SONNODE,		 //�ӽڵ�̫���ˣ�
	CONNECT_VIDEO_RESPONSE_NOCAMERA,		 //camera������
	CONNECT_VIDEO_RESPONSE_HAS_HISTORY,		//�����ڿ���ʷ��Ƶ
	CONNECT_VIDEO_RESPONSE_HAS_DOWNLOAD,	//������������Ƶ
	CONNECT_VIDEO_RESPONSE_HAS_ALARM,	//�б�����Ƶ
};

enum ULUCU_DEVICE_TYPE
{
	DEVICE_TYPE_ULUCU = 0,
	DEVICE_TYPE_HAIS = 10,
	DEVICE_TYPE_FUHAN = 20,
	DEVICE_TYPE_HAIK = 30,
	DEVICE_TYPE_DAHUA = 40,
	DEVICE_TYPE_WEIQ = 50,	//by
	DEVICE_TYPE_HANB = 60,	//by 20120420
	DEVICE_TYPE_SZ100 = 70,	//by MZW 20120420
};

enum ULUCU_HTTP_FUNC_TYPE
{
	HTTP_QUERY_MEM = 0,		//�ռ�ѯ��
	HTTP_FILE_UP,			//�ļ��ϴ�
	HTTP_FILE_DOWN,			//�ļ�����
};

//////////////////////////////////////////////////////////////////////////
//by 20121225
//msg_header�ṹ���ver����
//by 20130530 ����汾����
enum ULUCU_VERSION_TYPE
{
	SZ_100 = 100,
	PC_ENP_CLIENT = 200,	//��ҵ��PC��	
	PC_HOME_CLIENT = 201,	//��ͥ��PC��
	WEB_CLIENT = 250,

	IOS_CLIENT = 300,
	IOS_CLIENT_2 = 301,
	IOS_CLIENT_3 = 302,
	IOS_CLIENT_4 = 303,
	IOS_CLIENT_5 = 304,
	IOS_CLIENT_6 = 305,
	IOS_CLIENT_7 = 306,
	IOS_CLIENT_8 = 307,
	IOS_CLIENT_9 = 308,
	IOS_CLIENT_10 = 309,

	ANDROID_CLIENT = 350,
	ANDROID_CLIENT_2 = 351,
	ANDROID_CLIENT_3 = 352,
	ANDROID_CLIENT_4 = 353,
	ANDROID_CLIENT_5 = 354,
	ANDROID_CLIENT_6 = 355,
	ANDROID_CLIENT_7 = 356,
	ANDROID_CLIENT_8 = 357,
	ANDROID_CLIENT_9 = 358,
	ANDROID_CLIENT_10 = 359,

	IPAD_CLIENT = 400,
	IPAD_CLIENT_2 = 401,
	IPAD_CLIENT_3 = 402,
	IPAD_CLIENT_4 = 403,
	IPAD_CLIENT_5 = 404,
	IPAD_CLIENT_6 = 405,
	IPAD_CLIENT_7 = 406,
	IPAD_CLIENT_8 = 407,
	IPAD_CLIENT_9 = 408,
	IPAD_CLIENT_10 = 409,
};
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//by 20121226
//�ļ�����
//////////////////////////////////////////////////////////////////////////

#pragma pack(4)
///ͨѶ���õ������ṹ��
typedef struct active_member_s
{
	uint32 user_id;
	uint32 right_mask;
	uint32 manage_server_ip;
}active_member_s;

typedef struct active_camera_s
{
	uint32 camera_id;
	uint32 visible_level;
	uint32 manage_server_ip;
}active_camera_s;

typedef struct msg_p2p_s
{
	uint32 client_id;
	uint32 device_id;
	uint32 session[4];	//���ھ�������½
}msg_p2p_client_2_device_signin;

typedef struct custom_s
{
	uint32 custom_id;
	char br_name[64];
}custom_s;

typedef struct client_s
{
	uint32 client_id;					//�ڵ��ʶ
	uint32 manager_server_ip;			//�����ӵĹ��������ip
	uint16 peer_type;
	uint16 net_type;
}client_s;

typedef struct camera_s
{
	uint32 camera_id;					//camera��ʶid
	uint32 group_id;					//camera��������id
	uint32	online;								//camera����״̬
	uint32 manage_server_ip;			//���ڹ����������ַ
	uint16 manage_server_port;		//���ڹ���������˿�
	uint32 status_server_ip;			//����״̬��������ַ
	uint16 status_server_port;		//����״̬�������˿�
	uint32 video_server_ip;			//������Ƶ��ת��������ַ
	uint16 video_server_port;		//������Ƶ�������˿�
	uint16 visible;							//�ɼ���
	uint16 history_support;						//�Ƿ�֧����ʷ//�Ƿ���Ӳ��
	uint16 realtime_support;					//�Ƿ�֧��ʵʱ
	uint16 ptctrl_support;					//�Ƿ�֧����̨����
	char camera_name[MAX_CAMERA_NAME_SIZE];	//Camera����ʾ����
	uint16 pickup_support;					//�Ƿ�֧��ʵʱͨ��
	uint16 speaker_support;					//�Ƿ�֧��ʵʱͨ��
	uint16 device_type;//�豸����           use_ipc
}camera_s;

struct query_device_id_req
{
	char device_sn[64];
};

struct query_device_id_ret
{
	uint32 device_id;			//�豸ID��
};

struct client_device_query_isadded_req
{ 	
	uint32 custom_id;	    //�û�id
	char device_sn[64];    //����ͷuuid
};

struct client_device_query_isadded_ret
{
	uint32 status;   //0δ���û���1�ѱ����û��󶨣�2�������û���     
};

struct client_device_query_isadded_ret_v2
{
	uint32 status;  	 //0δ���û���1�ѱ����û��󶨣�2�������û���     
	char user_name[64];   //������ԭ�û�
};

typedef struct camera_group_s
{
	uint32 group_id;					//����id
	uint32 custom_id;				//
	uint32 parent_id;					//������id
	uint16 level;								//����㼶
	char group_name[64];					//��������
}camera_group_s;


typedef struct user_s
{
	uint32 user_id;					//�û���ʶid
	uint32 depart_id;					//��������id
	uint32 custom_id;				//
	uint32 right_mask;				//�û�ӵ�е�Ȩ��
	char user_name[32];						//�û���
	char real_name[64];						//��ʵ����
	char nick_name[32];						//�û��ǳ�
}user_s;

typedef struct right_s
{
	char right_name[96];
}right_s;



typedef struct admin_s
{
	uint32 admin_id;					//����Ĺ���Ա��ʶid
	uint32 manage_server_ip;			//�������Ա���ڹ����������ip
}admin_s;

typedef struct _PROBE
{
	int packet_id;
	unsigned int send_time;
	unsigned int recv_time;
	int is_send;
	char data[1024];
}PROBE;


typedef struct _ISPTYPE
{
	unsigned int nettype;
	char ipstr[20];
}ISPTYPE;

//by ֪ͨ�ͻ�����ʷ��Ƶ�����֡��С֡
typedef struct camera_seq_param_s
{
	uint32 i_min_seq;					//����Ĺ���Ա��ʶid
	uint32 i_max_seq;			//�������Ա���ڹ����������ip
}camera_seq_param_s;

typedef struct tagUUFont
{
	uint32				m_clrColor;				//������ɫ
	uint16				m_bSize;				//�����С
	uint16				m_bStyle;				//������
	char				m_szName[LF_FACESIZE];	//��������
}font_s;


typedef struct  tag_alarm_record_s
{
	uint32    id;
	uint32 	 camera_id;
	uint32    alarm_type;
	uint32	 alarm_level;
	char	 alarm_msg[32];
	char	 alarm_time[32];
	uint32	 has_process;
	char	 process_time[32];
	uint32	 process_id;
	char	 process_result[64];
}alarm_record_s;

//by 20120710 ���͸�camera�Ľ��ձ���
struct msg_p2p_data_report
{
	uint32 camera_id;
	uint32 father_id;	//�������ݷ�
	uint32 start_block_seq; //��ʼ��¼��С����
	uint32 data_report;     //32��С���Ľ���״̬
};

#define PACKET_HEAD_FLAG 0xFFEEDDCC

//��Ϣ���Ͷ���
enum msgType
{
	MSG_BEGIN =0,

	KEEP_ALIVE_MSG =1,
	ERROR_MSG =2,
	KEEP_ALIVE_ACK_MSG =3,
	KEEP_ALIVE_CLUSTER_MSG= 4,

	SERVER_BROADCAST_ALIVE_MSG=500,
	SERVER_FORWARD_MSG        =501,
	///��¼��Ϣ
	/***************************************************************************/
	MSG_LOGIN_BEGIN = 10000,
	
	CLIENT_LOGIN_MSG =10001,
	CAMERA_LOGIN_MSG =10002,
	LOGIN_CHALLENGE_MSG =10003,
	LOGIN_CHALLENGE_ACK_MSG =10004,
	DEVICE_LOGIN_MSG =10005,
	DEVICE_LOGIN_NEW_MSG =10006,

	//////////////////////////////////////////////////////////////////////////
	//by 20121227 
	//�°汾������Ϣ
	QUERY_NEW_VERSION_MSG =10007,
	QUERY_NEW_VERSION_ACK_MSG =10008,
	//////////////////////////////////////////////////////////////////////////

	/*************login server and status server ****************/
	QUERY_LOGIN_SERVER_MSG = 10009,
	LOGIN_DI_SERVER_MSG = 10010,
	CLIENT_REGISTER_MSG = 10011,
	SEND_VERIFYCODE_MSG = 10012,
	RESET_PASSWORD_MSG = 10013,
	RESET_PASSWORD_BYVERIFY_MSG = 10014,
	QUERY_IPC_ONLINE_MSG = 10015,
	ADD_TERMINAL_DEVICE_MSG = 10016,
	QUERY_TERMINAL_DEVICE_MSG = 10017,
	ADD_TERMINAL_EXCEPTION_MSG = 10018,
	CLIENT_DEVICE_ADD_MSG = 10019,
	CLIENT_DEVICE_QUERY_MSG =10020,
	CLIENT_DEVICE_QUERY_2_MSG =10021,
	QUERY_APP_VERSION_MSG = 10022,
	CLIENT_DEVICE_UNBUNDLE_MSG = 10023,
	CLIENT_DEVICE_ID = 10024,
	CLIENT_DEVICE_ADD_2_MSG = 10025,
	CLIENT_DEVICE_QUERY_ISADDED_MSG = 10027,
	CLIENT_APPLY_TEST_ACCOUNT_MSG= 10028,
	CLIENT_APPLY_TEST_ACCOUNT_CTL_MSG = 10029,
	CLIENT_APPLY_SALT_MSG  =  10030,
	CLIENT_REGISTER_CHECK_MSG = 10031,
	CLIENT_MOD_DEVICENAME_MSG = 10032,

	CLIENT_CHECK_VERIFYCODE_MSG = 10038,
	/****************************************************************************/


	MSG_MGR_SERVER_BEGIN = 20000,
	/******************************����״̬����������������֮����Ϣ************/


	II_MGR_CLIENT_ONLINE_MSG = 20001,
	II_MGR_CLIENT_OFFLINE_MSG = 20002,
	II_MGR_CAMERA_ONLINE_MSG =20003,
	II_MGR_CAMERA_OFFLINE_MSG = 20004,
	II_MGR_GET_PARTNER_LIST_MSG = 20005,
	II_MGR_ACTIVE_CAMERA_LIST_MSG = 20006,
	II_MGR_ACTIVE_USER_LIST_MSG = 20007,
	II_MGR_CLIENT_ADD_TO_CAMERA_GROUP_MSG = 20008,
	II_MGR_CLIENT_DEL_FROM_CAMERA_GROUP_MSG = 20009,
	II_MGR_GET_PARTNER_LIST_COUNT_MSG = 20010,
	II_MGR_UPDATE_MANAGE_SERVER_ADDR_MSG = 20011,
	II_MGR_QUERY_ADMIN_MSG = 20012,
	II_MGR_JOIN_DEPARTMENT_MSG = 20013,
	II_MGR_AUTH_OF_CAMERA_FOR_USER_MSG = 20014,
	II_MGR_CHECK_RIGHT_OF_USER_FOR_CAMERA_MSG = 20015,
	II_MGR_MGR_ONLINE_MSG = 20016,
	II_LOGIN_QUERY_SERVER_MSG = 20017,
	MSG_II_MGR_END = 20018,
	/***************************************************************************/


	/****************************�ڵ�����������֮���ͨѶ��Ϣ ***************/

	PEER_MGR_SIGN_IN_MSG = 20200,						//ǩ��
	CLIENT_MGR_SIGN_OUT_MSG = 20201,

	PEER_MGR_PARTNERS_MSG = 20202,					//���ڵ�ID
	PEER_MGR_P2P_CALL_MSG = 20203,
	PEER_MGR_P2P_CALL_ACK_MSG = 20204,

	CLIENT_MGR_PARTNER_LIST_COUNT_MSG = 20205,		//��ȡ����ͷ�Ĺۿ���Ϣ(������Ϣ)


	CLIENT_MGR_CAMERA_OFFLINE_MSG = 20206,
	CLIENT_MGR_CAMERA_ONLINE_MSG = 20207,
	CLIENT_MGR_CLIENT_OFFLINE_MSG = 20208,
	CLIENT_MGR_CLIENT_ONLINE_MSG = 20209,
	CLIENT_MGR_ACTIVE_CAMERA_LIST_MSG = 20210,	//�õ����ߵ�camera��Ϣ
	CLIENT_MGR_ACTIVE_USER_LIST_MSG = 20211,
	CLIENT_MGR_JOIN_DEPARTMENT_MSG = 20212,
	CLIENT_MGR_JOIN_DEPARTMENT_ACK_MSG = 20213,
	CLIENT_MGR_MEMBER_JOIN_DEPARTMENT_BROADCAST_MSG = 20214,
	CLIENT_MGR_REQUEST_AUTH_OF_CAMERA_MSG = 20215,
	CLIENT_MGR_REQUEST_AUTH_OF_CAMERA_ACK_MSG = 20216,
	CLIENT_MGR_ADD_FRIEND_COMPANY_MSG = 20217,
	CLIENT_MGR_ADD_FRIEND_COMPANY_ACK_MSG = 20218,
	CLIENT_MGR_STOP_LOOK_CAMERA_MSG = 20219,
	CAMERA_MGR_SIGN_IN = 20220,
	CLIENT_MGR_START_LOOK_CAMERA_MSG = 20221,

	WANT_LOOK_RT_VIDEO_MSG = 20222, //�ۿ�ʵʱ��ƵЭ��Э��
	WANT_LOOK_RT_VIDEO_ACK_MSG = 20223,//�ۿ�ʵʱ��ƵЭ�̻ظ�Э��

	PEER_MGR_SIGN_OUT_MSG = 20224,						//ǩ
	CAMERA_MGR_SIGN_OUT = 20225,

	GET_HIST_VIDEO_FILE_LIST_MSG = 20226, //��ȡ��ʷ��Ƶ�ļ��б�
	HIST_VIDEO_FILE_LIST_MSG = 20227, //��ʷ��Ƶ�ļ��б�
	WANT_LOOK_HIST_VIDEO_MSG = 20228, //�ۿ���ʷ��ƵЭ��Э��
	WANT_LOOK_HIST_VIDEO_ACK_MSG = 20229,//�ۿ���ʷ��ƵЭ�̻ظ�Э��
	PT_MOVE_LEFT_MSG = 20230,//��̨����
	PT_MOVE_RIGHT_MSG = 20231,//��̨����
	PT_MOVE_UP_MSG = 20232,//��̨����
	PT_MOVE_DOWN_MSG = 20233,//��̨����
	PT_FOCUS_NEAR_MSG = 20234,//����
	PT_FOCUS_FAR_MSG = 20235,//Զ��
	PT_MOVE_STOP_MSG = 20236, //ֹͣ�ƶ�
	MGR_CLIENT_VD_HIST_START_LOOK_VIDEO_MSG = 20237,//�����м̷��������ùۿ���ʷ��Ƶ׼��
	MGR_CLIENT_VD_HIST_STOP_LOOK_VIDEO_MSG = 20238,//�����м�ֹͣ�ۿ���ʷ��Ƶ
	//MGR_CAMERA_VD_ASK_PUSH_HIST_VIDEO_MSG = 20239,
 	HIST_VIDEO_CAMERA_ACK_MSG = 20240,
	MGR_CLIENT_VD_HIST_CONTROL_VIDEO_MSG = 20241,
	///////For download file
	WANT_DOWNLOAD_HIST_FILE_MSG = 20242,
	WANT_DOWNLOAD_HIST_FILE_ACK_MSG = 20243,
	/////////For security center 
	MGR_GET_CAMERA_NETINFO_MSG = 20244,
	MGR_GET_CAMERA_NETINFO_ACK_MSG = 20245,
	MGR_SET_CAMERA_NET_ISPTYPE_MSG = 20246,
	MGR_GET_DEVICE_INFO_MSG = 20247,
	MGR_GET_DEVICE_INFO_ACK_MSG = 20248,
	CLIENT_MGR_SET_LM_PARAM=20249,
	MGR_GET_MOTION_DETECTION_PARAM_MSG = 20250,
	MGR_GET_MOTION_DETECTION_PARAM_ACK_MSG =20251,
	MGR_SET_MOTION_DETECTION_PARAM_MSG = 20252,
	MGR_GET_LOST_VIDEO_PARAM_MSG = 20253,
	MGR_GET_LOST_VIDEO_PARAM_ACK_MSG = 20254,
	MGR_SET_LOST_VIDEO_PARAM_MSG = 20255,
	MGR_GET_MASK_VIDEO_PARAM_MSG = 20256,
	MGR_GET_MASK_VIDEO_PARAM_ACK_MSG = 20257,
	MGR_SET_MASK_VIDEO_PARAM_MSG = 20258,
	MGR_SET_PRESET_POINT_MSG = 20259,
	MGR_SET_CRUISE_PATH_MSG = 20260,
	MGR_GET_CRUISE_PATH_MSG = 20261,
	MGR_GET_CRUISE_PATH_ACK_MSG = 20262,
	MGR_START_CRUISE_PATH_MSG = 20263,
	MGR_STOP_CRUISE_PATH_MSG = 20264,
	MGR_SET_YUANTAI_MODE_MSG = 20265,
	MGR_GET_YUANTAI_MODE_MSG = 20266,
	MGR_GET_YUANTAI_MODE_ACK_MSG = 20267,
	MGR_GET_SYSTEM_TIME_MSG =20268,
	MGR_GET_SYSTEM_TIME_ACK_MSG = 20269,
	//MGR_SET_ALARM_UPLOAD_MSG = 20270,
	
	MGR_SET_REALTIME_STREAM_MSG = 20271,
	MGR_GET_REALTIME_STREAM_MSG = 20272,
	MGR_GET_REALTIME_STREAM_ACK_MSG = 20273,

	MGR_CAMERA_REBOOT_MSG = 20274,

	MGR_GET_RUNTIME_AUDIO_MSG = 20275,
	MGR_GET_RUNTIME_AUDIO_ACK_MSG = 20276,
	MGR_SET_RUNTIME_AUDIO_MSG   = 20277,
	////////////////////////////////////////////
	//Add messages for vca purpose
	//////////////////////////////////////////////
	CAMERA_2_MGR_VCA_DATA_REPORT = 20278,
	CAMERA_2_MGR_VCA_DATA_REPORT_ACK = 20279,
	
	DEVICE_MGR_SIGN_IN = 20280,
	DEVICE_MGR_SIGN_OUT = 20281,
	
	CLIENT_MGR_GET_LM_PARAM  =20282,
	CLIENT_MGR_LM_PARAM_ACK_MSG  =20283,
	MGR_STOP_TALK_MSG  =20284,
	/////////////////////////////////////////////////////
	//switch alarm param 
	/////////////////////////////////////////////////////
	MGR_SET_SWITCH_ALARM_PARAM_MSG  =20285,
	MGR_GET_SWITCH_ALARM_PARAM_MSG  =20286,
	MGR_GET_SWITCH_ALARM_PARAM_ACK_MSG  =20287,
	MGR_SET_SWITCH_DEVICE_MSG  =20288,
	MGR_GET_SWITCH_DEVICE_PARAM_MSG  =20289,
	MGR_GET_SWITCH_DEVICE_PARAM_ACK_MSG  =20290,
	/////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	//by 20121212
	CLIENT_2_MGR_SNAPSHOT_MSG =20291,
	MGR_2_CAMERA_SNAPSHOT_MSG =20292,
	CAMERA_2_HTTP_QUERY_FILE_UP_MSG =20293,
	HTTP_2_CAMERA_QUERY_FILE_UP_ACK_MSG =20294,
	CAMERA_2_MGR_FILE_UP_ACK_MSG =20295,
	MGR_2_CLIENT_SNAPSHOT_ACK_MSG =20296,
	CLIENT_MGR_GET_CLOUD_HOME_FILE_LIST_ACK_MSG =20297,
	CLIENT_MGR_SET_CAMERA_TIMING_RECORD_PARA_MSG =20298,
	//CLIENT_MGR_SET_CAMERA_ALARM_NOTE_MSG =20299,
	//CLIENT_MGR_GET_CAMERA_ALARM_NOTE_MSG =20300,
	CLIENT_MGR_SET_CAMERA_CRUISE_MODE_MSG =20301,

	PEER_NEW_MGR_P2P_CALL_MSG =20302,

	CLIENT_MGR_SET_CAMERA_RECORD_MSG =20303,

	//////////////////////////////////////////////////////////////////////////
	//alarm msg
	CLIENT_MGR_SET_CAMERA_ALARM_NOTE_MSG =20304,
	CLIENT_MGR_GET_CAMERA_ALARM_NOTE_MSG =20305,
	CLIENT_MGR_GET_CAMERA_ALARM_NOTE_ACK_MSG =20306,
	
	MGR_GET_USER_DISCONN_DEVICE_MSG = 20309,

	MGR_CAMERA_ALARM_ACK_MSG = 20310,

	PEER_MGR_P2P_CALL_LOCAL_MSG =20311,
	PEER_MGR_P2P_CALL_LOCAL_ACK_MSG =20312,
	UPDATE_MOBILE_INVITE_INFO =20313,
	UPDATE_MOBILE_INVITE_ACK =20314,
	UPDATE_DEVICE_FTP_INFO =20315,
	UPDATE_DEVICE_FTP_INFO_ACK =20316,

	CLIENT_MGR_SET_VIDEO_PARAM = 20317,
	
	CAMERA_ALARM_INFO_UPLOAD_MSG =20319,	
	CAMERA_ALARM_INFO_SERVER_UPLOAD_MSG =20320,
	CLIENT_ACK_SERVER_ALARM_INFO_MSG =20321,
	CLIENT_MGR_GET_CAMERA_ALARM_DATA_MSG =20322,
	CAMERA_ALARM_DATA_UPLOAD_MSG =20323,
	CLIENT_MGR_GET_VOL_PARAM = 20324,
	CLIENT_MGR_VOL_PARAM = 20325,
    CLIENT_MGR_GET_DEVICE_MDATA = 20326,
	CLIENT_MGR_DEVICE_MDATA = 20327,
	MGR_DEVICE_RELOGIN = 20328,
	CLIENT_MGR_SET_VOL_PARAM = 20329,


	//////////////////////////////////////////////////////////////////////////

	I_CHAT_CONTENT_MSG = 20400,							//����������Ϣ
	I_CHAT_SHAKE_MSG = 20401,							//��������Ϣ

	/****************************************************************************/




	/*******************************���������֮��ͨѶ��Ϣ **********************/
	MGR_MGR_P2P_CALL_MSG = 20800,
	MGR_MGR_P2P_CALL_ACK_MSG = 20801,
	MGR_MGR_CAMERA_OFFLINE_MSG= 20802,
	MGR_MGR_CLIENT_OFFLINE_MSG= 20803,
	MGR_MGR_CAMERA_ONLINE_MSG= 20804,
	MGR_MGR_CLIENT_ONLINE_MSG= 20805,
	MGR_MGR_ASK_CLIENT_CONNECT_MSG= 20806,
	MGR_MGR_JOIN_DEPARTMENT_MSG= 20807,
	MGR_MGR_JOIN_DEPARTMENT_ACK_MSG= 20808,
	MGR_MGR_JOIN_DEPARTMENT_BROADCAST_MSG= 20809,
	MGR_MGR_REQUEST_AUTH_OF_CAMERA_MSG= 20810,
	MGR_MGR_REQUEST_AUTH_OF_CAMERA_ACK_MSG= 20811,
	MGR_MGR_ADD_FRIEND_COMPANY_MSG= 20812,
	MGR_MGR_ADD_FRIEND_COMPANY_ACK_MSG= 20813,
	MGR_MGR_START_LOOK_CAMERA_MSG= 20814,
	MGR_MGR_STOP_LOOK_CAMERA_MSG= 20815,

	CAMERA_GET_PICTURE_PARAM =20816,
	CAMERA_GET_PICTURE_PARAM_ACK =20817,
	CAMERA_SET_PICTURE_PARAM =20818,

	CAMERA_GET_VIDEO_PARAM =20819,
	CAMERA_GET_VIDEO_PARAM_ACK =20820,
	CAMERA_SET_VIDEO_PARAM =20821,

	/****************************************************************************/
	MSG_MGR_SERVER_END = 21000,


	/******************************�ͻ��������ݷ�����ͨѶ��Ϣ********************/
	MSG_DATA_SERVER_BEGIN = 30000,
	CLIENT_DATA_GET_COMPANY_GROUP_CAMERA_INFO_MSG = 30001,
	CLIENT_DATA_GET_COMPANY_GROUPS_MSG = 30002,
	CLIENT_DATA_GET_COMPANY_CAMERAS_MSG = 30003,
	CLIENT_DATA_GET_DEPARTMENT_USER_INFO_MSG = 30004,
	CLIENT_DATA_GET_DEPARTMENTS_MSG = 30005,
	CLIENT_DATA_GET_DEPART_USERS_MSG = 30006,
	CLIENT_DATA_GET_USER_DETAIL_INFO_MSG = 30007,
	CLIENT_DATA_GET_COMPANY_DETAIL_INFO_MSG = 30008,
	CLIENT_DATA_GET_CAMERA_DETAIL_INFO_MSG = 30009,
	CLIENT_DATA_UPDATE_USER_INFO_MSG = 30010,
	CLIENT_DATA_GET_USER_RIGHT_MSG = 30011,
	CLIENT_DATA_GET_FRIEND_COMPANY_MSG = 30012,
	CLIENT_DATA_DEL_EMPLOYEE_MSG = 30013,
	CLIENT_DATA_DEL_FRIEND_COMPANY_MSG = 30014,
	CLIENT_DATA_GET_AUTH_CAMERAS_MSG = 30015,
	CLIENT_DATA_SEARCH_COMPANY_MSG = 30016,
	CLIENT_DATA_GET_RECOMMEND_COMPANY_MSG = 30017,
	CLIENT_DATA_GET_CUSTOMER_LIST_MSG = 30018,
	CLIENT_DATA_GET_OTHER_COMPANY_GROUPS_MSG = 30019,
	CLIENT_DATA_GET_OTHER_COMPANY_CAMERAS_MSG = 30020,
	CLIENT_DATA_GET_OTHER_COMPANY_GROUP_CAMERA_INFO_MSG =30021,
	CLIENT_DATA_GET_UNPROCESS_ALARM_MSG = 30022,
	CLIENT_DATA_GET_UNPROCESS_ALARM_ACK_MSG = 30023,
	CLIENT_DATA_GET_ALL_ALARM_MSG = 30024,
	CLIENT_DATA_GET_ALL_ALARM_ACK_MSG = 30025,
	CLIENT_DATA_UPDATE_ALARM_PROCESSED_MSG = 30026,
	CLIENT_DATA_GET_SECURITY_CENTER_CAMERA_MSG = 30027,
	CLIENT_DATA_GET_SECURITY_CENTER_CAMERA_ACK_MSG = 30028,
	CLIENT_2_INFOSVR_QUERY_VCA_DATA = 30029,
	CLIENT_DATA_GET_COMPANY_EVENT = 30030,
	CLIENT_DATA_GET_COMPANY_EVENT_ACK = 30031,
	
	//by 20130529 infoserver
	CLIENT_DATA_GET_LOG_CONTENT_MSG =30051, //������һ�β�����¼
	CLIENT_DATA_GET_LOG_CONTENT_MSG_ACK = 30052,
    CLIENT_INFO_SET_CAMERA_ALARM_NOTE_MSG = 30053,
    CLIENT_INFO_GET_CAMERA_ALARM_NOTE_MSG = 30054,
    CLIENT_INFO_GET_CAMERA_ALARM_NOTE_MSG_ACK = 30055,

	//
	MSG_DATA_SERVER_END = 30056,
	/****************************************************************************/

	P2P_BEGIN = 40000,

	P2P_STUN_MSG = 40001,
	P2P_STUN_ACK_MSG = 40002,
	P2P_INIT_PARAM_MSG = 40003,
	P2P_ASK_DATA_MSG =40004,
	P2P_DATA_MSG = 40005,
	P2P_ASK_BUFFERMAP_MSG = 40006,
	P2P_BUFFERMAP_MSG = 40007,
	P2P_ASK_PUSHDATA = 40008,
	P2P_STOP_PUSHDATA = 40009,
	P2P_STUN_ACK_ACK_MSG = 40010,
	P2P_KEEP_ALIVE_MSG	= 40011,
	P2P_KEEP_ALIVE_ACK_MSG	= 40012,
	P2P_CONNECT_VIDEO_MSG	= 40013,
	P2P_CONNECT_VIDEO_ACK_MSG	= 40014,
	P2P_CLOSE_VIDEO_MSG	= 40015,
	P2P_GET_INIT_PARAM_MSG = 40016,
	P2P_HIST_INIT_PARAM_MSG = 40017,
	P2P_ASK_HIST_DATA_MSG =40018,
	P2P_HIST_DATA_MSG = 40019,
	P2P_DATA_ACK_MSG = 40020,
	P2P_ASK_MULTIPLE_DATA_MSG = 40021,

	P2P_ASK_PUSHDATA_ACK = 40022,
	P2P_AUDIO_DATA_MSG = 40023,
	
	P2P_ASK_MULTIPLE_HIST_DATA_MSG = 40024,

	P2P_DATA_REPORT = 40026,		//by 20120710 ���͸�camera�Ľ��ձ���
	P2P_SET_PUB_AUDIO_MSG = 40027,
	P2P_CLIENT_DEVICE_SIGNIN = 40028,

	P2P_END = 40030,

	/***************************************************************************/
	PEER_PUNCH_GET_PUBLIC_ADDR = 50000,
	UDP_EXPLORESERVER = 50001,
	UDP_EXPLORESERVER_ACK = 50002,
	STATE_RESPONSE_MSG = 51000,
	NET_TYPE_PROBE_MSG = 52000,

	PEER_VD_BEGIN_MSG = 60000,
	/***************************************************************************/
	PEER_VD_SIGN_IN_MSG = 60001,
	CLIENT_VD_RT_START_LOOK_CAMERA_MSG = 60002,//�ͻ��˸����м����ùۿ�ʵʱ��Ƶ׼��
	CLIENT_VD_RT_STOP_LOOK_CAMREA_MSG = 60003,//�����м�ֹͣ�ۿ�ʵʱ��Ƶ
	CAMERA_VD_ASK_PUSH_VIDEO_MSG = 60004,//�м�Ҫcamera����ʵʱ��Ƶ��
	CAMERA_VD_ASK_STOP_VIDEO_MSG = 60005,//�м���cameraֹͣ������Ƶ
 	CLIENT_VD_HIST_START_LOOK_VIDEO_MSG = 60006,//�����м̷��������ùۿ���ʷ��Ƶ׼��
 	CLIENT_VD_HIST_STOP_LOOK_VIDEO_MSG = 60007,//�����м�ֹͣ�ۿ���ʷ��Ƶ
 	CAMERA_VD_ASK_PUSH_HIST_VIDEO_MSG = 60008,//�м�Ҫ��camera������ʷ��Ƶ��
 	CAMERA_VD_ASK_STOP_HIST_VIDEO_MSG = 60009,//�м�Ҫ��cameraͣ����ʷ��Ƶ��
 	CLIENT_VD_PAUSE_PUSH_VIDEO_MSG = 60010,//�м�Ҫ��camera��ͣ����ʵʱ��Ƶ
	CLIENT_VD_RESTART_PUSH_VIDEO_MSG = 60011,//�м�Ҫ��camera���·���ʵʱ��Ƶ
	HIST_VIDEO_MSG = 60012,//��ʷ��Ƶ������
	CLIENT_VD_CAMERA_RT_HELLO_MSG = 60013,
	HIST_INIT_PARAM_MSG		=  60014,        // Init param for history video
	HIST_SKIP_VIDEO_MSG = 60015,
	/***************************************************************************/
	/************ For download  hist file*************************/
	CAMERA_VD_DOWNLOAD_HIST_DATA_MSG  = 60016,
	CAMERA_VD_DOWNLOAD_HIST_DATA_ACK_MSG  = 60017,
	CAMERA_VD_DOWNLOAD_HIST_FILE_FINISHED_MSG	= 60018,
	
    PEER_VD_SIGN_OUT_MSG = 60019,

	PEER_VD_END_MSG = 60020,

//	CAMERA_SEQ_PARAM_MSG = 60019,

	ID_BEGIN_MSG = 70000,
	PEER_GET_RAND_ID_MSG = 70001,

	ID_END_MSG = 70008,

	CAMERA_CONTROL_BEGIN_MSG = 71000,
	CAMERA_REBOOT_MSG = 71001,
	CAMERA_REMOTE_LOG_START_MSG = 71002,
	CAMERA_REMOTE_LOG_STOP_MSG = 71003,
	CAMERA_CONTROL_END_MSG = 71004,

	//track
	TK_BEGIN_MSG = 80000,
	/**************************************************************************/
	CLIENT_TK_START_LOOK_CAMERA_MSG = 80001,
	CLIENT_TK_STOP_LOOK_CAMERA_MSG = 80002,
	CLIENT_TK_GET_PARTNERS_MSG = 80003,
	CLIENT_TK_GET_PARTNER_COUNT_MSG = 80004,
	CLIENT_TK_P2P_CALL_MSG = 80005,
	CLIENT_TK_P2P_CALL_ACK_MSG = 80006,
	/***************************************************************************/
	TK_END_MSG = 80007,
	MGR_OUTLINE = 80008,

	MSG_END
};

///ͨѶ��ͷ������Ķ���

typedef struct msg_header
{
	uint32 tag;						//��ͷ��־
	uint32 cmd_id;					//��������id
	uint32 ver;						//Э��汾��
	uint32 len;						//���ĳ���
	uint32 state;					//���ڷ��ذ�����ʾ�������Կͻ��˵ĸ�����Ӧ״̬
}msg_header;

struct msg_status
{
	int32 err_code;
	char err_msg[128];
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//client��camera�͵�¼������
//client��camera�͵�¼����������tcp�Ķ�����

struct client_mgr_set_lm_param
{
	uint32 device_id;
	uint32 user_id;
	uint32 luminous;   //0--100
	uint32 reserver;
};


struct msg_keep_alive
{
	uint32 peer_id;
	uint32 camera_id;	//by
};

struct msg_keep_alive_ack
{
	uint32 src_peerid;
	uint32 camera_id;	//by
};

// msg between login and status ; 
struct msg_login_server_info
{
	int magic;
	int mgrs;
	
};

//register ;
struct client_register_2_login
{
	char user_name[64];
	char pass[64];
	char verifycode[64];    //��֤��
	char device_sn[64];
	uint16 user_type;  //�û�����
};

struct client_register_check_ret
{
	uint32 status;  //1����;0������
};

//
struct login_2_client_reg_ret
{
        uint32 device_id;
        uint32 camera_id;
};

//online query;
struct client_online_query_2_login
{
	uint32 custom_id;
	uint32 user_id;
	uint32 device_id;
	uint32 camera_id;
};


///�ͻ��˵�¼�������������

struct login_challenge_ack
{
	char	challenge[20];
};

struct client_2_login_req
{
	char user_name[64];
	char pass[64];
	uint32 net_type;
	uint32 padding; // 0:Android   1: ios
};

struct client_2_login_req_v2
{
	char user_name[64];
	char pass[128];
	uint32 net_type;
	char session_id[128];
	uint32 mgrsvr_addr;
	uint32 public_cnc_ip;
	uint32 public_tel_ip;
};

struct login_2_client_ret_ver101
{
        uint32 user_id;
        uint32 custom_id;
};

///�ͻ��˵�¼�������ķ��ذ�
struct login_2_client_ret
{
	uint32 user_id;
	uint32 manage_server_ip;
	uint16 manage_server_port;
	uint32 custom_id;
	uint32 right_mask;//Ȩ�ޱ�
	uint16 custom_type;
	uint16 net_type; //�������ͣ�������ţ���ͨ�������
	char session_id[128];
	uint32 is_admin;
};

//QUERY_NEW_VERSION_MSG
struct query_new_version_ret
{
	//by �汾������ʾ
	char ver_NO[20];
	char ver_detail[200];
};

///�ͻ��˵�¼�������ķ��ذ�
struct login_2_client_ver_ret
{
	uint32 user_id;
	uint32 manage_server_ip;
	uint16 manage_server_port;
	uint32 custom_id;
	uint32 right_mask;//Ȩ�ޱ�
	uint16 custom_type;
	uint16 net_type; //�������ͣ�������ţ���ͨ�������
	char session_id[128];
	uint32 is_admin;
	//by �汾������ʾ
	char ver_NO[20];
	char ver_detail[200];
};

///camera��¼�������������
struct camera_2_login_req
{
	uint32 camera_id;
	uint16 net_type;//���ؼ�������������
};

struct device_2_login_req
{
	uint32 device_id;
	uint16 net_type;//���ؼ�������������
	char   device_sn[64];
};

///camera��¼�������������
struct login_2_camera_ret
{
	uint32 custom_id;
	uint32 manage_server_ip;
	uint16 manage_server_port;	
	uint16 net_type;//�������ͣ�������ţ���ͨ�������
	char session_id[128];
};

//add by chengweishan 2014.11.17 ����ָ����ܰ���
//������֤��
struct send_verifycode_req
{
	char user_name[64];
};

struct client_check_verifycode_req
{
	char user_name[64];
	char verifycode[64];    //��֤��
	char notused[32];	   //��ʱδ�õ�
};

struct client_check_verifycode_ret
{
	uint32 status;	  //  0:��֤����ȷ   1:��֤�벻����  2: ��֤����� 
};

//������������
struct reset_password_req
{
 	char user_name[64];
 	char oldpass[64];
 	char newpass[64];
};
//������֤��������������
struct reset_password_byverify_req
{
	char user_name[64];
 	char verifycode[64];
	char newpass[64];
};

//add by chengweishan 2014.11.19 �ն��豸����
//�ն��豸���
struct terminal_device_add_req
{ 
	uint32 user_id;
	char dev_uuid[256];
 	char dev_model[256];
 	char dev_osversion[256];
};

//�ն��豸��ѯ
struct terminal_device_query_req
{ 	
	uint32 user_id;
 	char dev_uuid[256];
};

//�ն��豸��ѯ����
struct terminal_device_query_ret
{ 
	uint32 dev_id;
};

//�ն��豸�쳣��Ϣ���
struct terminal_exception_add_req
{ 
	uint32 dev_id;
 	char exception[256];
};

//�û�����豸
struct client_device_add_req
{ 	
	uint32 custom_id;	
	char device_sn[64];  //����ͷuuid
	char device_name[64];  // add
	char device_passwd[64];  //add
};

//����Ϊ�ɹ�ʱ�İ��壺
struct client_device_add_ret
{
   uint32 device_id;      //��redis����camera��
   uint32 camera_id;
};


struct device_sn_name_passwd
{
	char device_sn[12];
	char device_name[64];
	char device_passwd[64];
};
//�û���ѯ�豸
struct client_device_query_req
{ 	
	uint32 user_id;	 //moded
};

struct client_device_query_v2_req
{ 	
	uint32 user_id;
	uint32 device_type;	//�����豸��������   0:ipc365,1:showmo
};

struct device_id_sn_name_passwd
{
	uint32 device_id;     
	char device_sn[12];    //����ͷuuid
	char device_name[32];  
	char device_passwd[32];
};

//����Ϊ�ɹ�ʱ�İ��壺(device_id)
struct client_device_query_ret
{
    device_id_sn_name_passwd device[0]; 
};
//����Ϊ�ɹ�ʱ�İ��壺(device_sn)
struct client_device_query_2_ret
{ 
	struct device_sn_name_passwd device_info[0];  //����
};

//�û��豸���
struct client_device_unbundle_req
{ 	
	uint32 custom_id;	
	char device_sn[64];  //����ͷuuid  
};

//app�汾��ѯ
struct query_app_version_req
{ 	
	uint16 user_type;	// 0 ��ʾipc365; 1��ʾiup365
};

struct query_app_version_ret
{ 	
	char version[32];
	char feature[256];	
};
//////////////////////////////

//////////////////////////////////////////////////////////////////////////
//http������ҵ������
struct  http_fuction
{
	uint32 func_type;		//http������ҵ������
	char http_url[50];		//http������ҳ���ַ
};
//by 20121214 �µ�camera��¼�������������
struct login_2_camera_ver_100_ret
{
	uint32 custom_id;
	uint32 manage_server_ip;
	uint32 status_server_ip;
	uint32 video_server_ip;
	uint16 net_type;//�������ͣ�������ţ���ͨ�������
	char session_id[128];
	uint32 http_server_ip;		//http������ip
	uint16 http_server_port;	//http������port
	uint16 func_count;   //�豸�ܽ����camera ��Ŀ
	struct http_fuction http_func_list[0];		
};
//////////////////////////////////////////////////////////////////////////

struct  device_camera_port
{
	uint32   camera_id;
	uint32   port_id;
};

struct login_2_device_ret
{
	uint32 custom_id;
	uint32 group_id;			//����ID��
	uint32 device_id;			//�豸ID��
	uint32 manage_server_ip;
	uint32 video_server_ip;
	uint16 net_type;//�������ͣ�������ţ���ͨ�������
	uint16 camera_num;   //�豸�ܽ����camera ��Ŀ
	struct device_camera_port camera_id_list[0];
};

struct new_login_2_device_ret
{
	uint32 custom_id;
	uint32 group_id;			//����ID��
	uint32 device_id;			//�豸ID��
	uint32 manage_server_ip;
	uint32 video_server_ip;
	uint16 net_type;//�������ͣ�������ţ���ͨ�������
	uint16 camera_num;   //�豸�ܽ����camera ��Ŀ
	//by �����ļ����������ϴ���ַ��port
	uint32 file_server_ip;
	uint16 file_server_port;

	struct device_camera_port camera_id_list[0];
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//���߹����������ȫ��������Ϣ������
//���߹��������ȫ��������Ϣ����������tcp�ĳ����ӣ����߹��������ת���ͻ�����������Ϣ���������������


///�ͻ�������
struct mgr_2_ii_client_offline
{
	uint32 custom_id;				//�û������ͻ�id
	uint32 client_id;					//�û���ʶid
	uint32 camera_id;					//������ڹۿ���Ƶ������ֶ���ֵ
	uint32 peer_type;
	uint32 net_type;
};

///�ͻ�������
struct mgr_2_ii_client_online
{
	uint32 custom_id;				//�û������ͻ�id
	uint32 client_id;					//�û���ʶid
	uint32 manage_server_ip;			//�ͻ������ڹ����������ַ
	uint32 right_mask;				//Ȩ��
	uint16 net_type;
	uint16 peer_type;
};

struct mgr_2_ii_camera_offline
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//camera��ʶid
};

struct mgr_2_ii_camera_online
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//camera��ʶid
	uint32 manage_server_ip;			//camera���ڹ����������ַ
	uint32 net_type;
	uint32 group_id;                    //camera��������
	uint16 visible_level;						//�ɼ�����
};


///��������camera�б�
struct mgr_2_ii_active_camera_list
{
	uint32 custom_id;				//id
	uint32 camera_id;					//����ͷid
	uint32 cfd;								//�ͻ�������������������������
};

///����ͬһ���ͻ��µ�����camera�б�
struct ii_2_mgr_active_camera_list
{
	uint32 cfd;								//�ͻ�������������������������
	uint32 custom_id;				//id
	uint16 camera_count;			//Camera�ĸ���
	active_camera_s camera_arr[0];					//Camera�б�����
};


///����ͬһ���ͻ��µ�����user�б�
struct mgr_2_ii_active_user_list
{
	uint32 cfd;								//�ͻ�������������������������
	uint32 custom_id;				//�ͻ�id
};

///����ͬһ���ͻ��µ�����user�б�
struct ii_2_mgr_active_user_list
{
	uint32 cfd;								//�ͻ�������������������������
	uint32 custom_id;				//�ͻ�id
	uint16 user_count;				//Camera�ĸ���
	active_member_s user_arr[0];				//Camera�б�����
};

///��ȡcamera��ص��б�������
struct mgr_2_ii_partner_list
{
	uint32 camera_id;					//Ŀ��camera_id
	uint32 client_count;				//����ĸ���
	uint32 net_type;
	uint32 peer_type;
	uint32 cfd;								//�ͻ��˵�socket������
	uint32 mgr_svr_ip;
};


///����camera��ص�client �б�ķ��ذ�
struct ii_2_mgr_partner_list
{
	uint32 cfd;								//�ͻ��˵�socket������
	uint32 camera_custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//��ص�camera�ı�ʶId
	uint16 client_count;				//�ͻ��˵ĸ���
	client_s client_array[0];				//�ͻ���������׵�ַ
};


///�������߹ۿ�camera�ķ���������
struct mgr_2_ii_client_add_to_camera_group
{
	uint32 camera_id;//ϣ���ۿ���camera_id
	uint32 client_id;
	uint16 net_type;
	uint16 peer_type;
	uint32 camera_stat_svr_ip;
	uint32 mgr_svr_ip;
};

///��camera�����ɾ���������
struct mgr_2_ii_del_client_from_camera_group
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//Ŀ��camera_id
	uint32 client_id;					//��ɾ����clientid
	uint16 net_type;
	uint16 peer_type;
};

///��ȡ���ڲ鿴ͬһ��camera�������������
struct mgr_2_ii_partner_list_count
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//Ŀ��camera_id
	uint32 cfd;								//�ͻ��˵�socket������
};

///�������ڲ鿴ͬһ��camera�������������
struct ii_2_mgr_partner_list_count
{
	uint32 camera_custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//��ص�camera�ı�ʶId
	uint32 client_list_count;			//�鿴ͬһ��camera������
	uint32 cfd;								//�ͻ��˵�socket������
};

///ɾ��������������ָ����camera����
struct mgr_2_ii_del_camera_group
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;				//����camera_id
};

///������������������һ��camera����
struct mgr_2_ii_add_camera_group
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//����camera id
	uint32 manage_server_ip;
};

///���½ڵ��������������д洢�����߹����������ַ
struct mgr_2_ii_update_manage_server_addr
{
	uint32 new_ip;					//Ŀ�������ip
	uint16 new_port;				//Ŀ��������˿�
	uint32 client_id;				//Client�ڵ��ʶ
	uint32 camera_id;				//Client���ڹۿ���camera��ʶ
};

///������������δ����camera���飬����Ϊcamera���ߣ�����camera���߰������������
struct ii_2_mgr_camera_offline
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//����camera�ı�ʶid
};


///�������������������������ͻ����ض��û���Ϣ
struct mgr_2_ii_query_admin
{
	uint32 custom_id;				//����Ŀͻ��ı�ʶid
	uint32 right_mask;				//����Ĺ���ԱȨ��ֵ
};

// mgr to status , inform online ; clm ;
struct mgr_2_status_online
{
	uint32 public_cnc_ip;
	uint32 public_tel_ip;
	uint32 local_ip;
	uint32 padding;
};

///״̬���������ظ��������������Ĺ���Ա
struct ii_2_mgr_admin
{
	uint16 count;
	admin_s arr[0];
};


///�û����벿�ųɹ�����״̬��������ע���
struct mgr_2_ii_join_department
{
	client_s me;
};


///��״̬�������Ǽ�Ϊĳ�û���Ȩ�ɹ��ۿ�ĳ����ͷ����Ϣ��
struct mgr_2_ii_add_auth_of_camera_for_user
{
	uint32 custom_id;				//����ͷ�����ͻ�id
	uint32 camera_id;					//����ۿ���camera id
	uint32 user_id;					//����ۿ����û�id
};

///��״̬������ɾ��ĳ�û��ۿ�ĳ����ͷ��Ȩ����Ϣ��
struct mgr_2_ii_del_auth_of_camera_for_user
{
	uint32 custom_id;				//����ͷ�����ͻ�id
	uint32 camera_id;					//����ۿ���camera id
	uint32 admin_id;					//ִ��ɾ���������û�id
	uint32 user_id;					//����ۿ����û�id
};

///�������������û��Ƿ���Ȩ�޲鿴����ͷ
struct mgr_2_ii_check_right_of_user_for_camera
{
	uint32 custom_id;				//camera�����ͻ���id
	uint32 camera_id;					//camera id
	uint32 user_id;					//�����û���id
};

///״̬���������ظ�������������û��Ƿ���Թۿ�����ͷ
struct ii_2_mgr_right_of_user_for_camera
{
	uint16 is_can_look;						//�Ƿ�ɿ���־
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//�ͻ��������߹��������
///�ڵ㣨client���������߹����������
//CLIENT_MGR_SIGN_IN_MSG,
struct peer_2_mgr_sign_in
{
	uint16 net_type;
	uint16 peer_type;
	uint32 custom_id;				//�����ͻ�id
	uint32 client_id;					//�ڵ�ı�ʶid
	uint32 right_mask;
	uint32 company_stat_server_ip;	//�����ͻ�����״̬������ip
	char session_id[128];					//��֤session��ʶid
};

struct peer_2_mgr_sign_out
{
	uint16 net_type;
	uint16 peer_type;
	uint32 custom_id;				//�����ͻ�id
	uint32 client_id;					//�ڵ�ı�ʶid
	uint32 company_stat_server_ip;	//�����ͻ�����״̬������ip
	char session_id[128];					//��֤session��ʶid
};

//��ȡ���ڵ��б������
struct msg_ask_partner_list
{
//	uint32 camera_custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//Ŀ��camera_id
	uint32 camera_status_server_ip;	//camera���ڵ�״̬��������ַ
	uint16 net_type;
	uint32 partner_count;				//����ĸ���
};

///���ذ�
struct msg_partner_list_ack
{
	uint32 camera_custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//camera id
	uint32 client_count;				//�ͻ��˵ĸ���
	client_s client_array[0];				//�ͻ���������׵�ַ
};

//ͨ������������ڵ�֮�佨��p2p���ӵ�Э���
struct msg_p2p_call
{
	uint16 net_type;			//�������ͣ�������ţ���ͨ�������
	uint16 peer_type;
	uint32 camera_id;
	uint32 father_id;		//�Է��ڵ�id
	uint32 son_id;	//���ڵ�id
	uint32 son_public_udp_ip;			//�Լ��Ĺ���ip
	uint16 son_public_udp_port;		//�Լ�����port
	uint32 son_local_ip;				//�Լ�˽��ip
	uint16 son_local_port;			//�Լ�˽��port

	//���������ֶ����Թ��������֮����Ϣת��
	uint32 father_manage_server_ip;	//���ڵ����ڵ�managerserver ip
	uint32 son_manage_server_ip;		//�ڷ�������д
};

//PEER_MGR_P2P_CALL_LOCAL_MSG
struct msg_p2p_call_local
{
	uint16 net_type;			//�������ͣ�������ţ���ͨ�������
	uint16 peer_type;
	uint32 camera_id;
	uint32 father_id;		//�Է��ڵ�id
	uint32 son_id;	//���ڵ�id
	uint32 son_public_udp_ip;			//�Լ��Ĺ���ip
	uint16 son_public_udp_port;		//�Լ�����port
	uint32 son_local_ip;				//�Լ�˽��ip
	uint16 son_local_port;			//�Լ�˽��port

	//���������ֶ����Թ��������֮����Ϣת��
	uint32 father_manage_server_ip;	//���ڵ����ڵ�managerserver ip
	uint32 son_manage_server_ip;		//�ڷ�������д
};


//PEER_NEW_MGR_P2P_CALL_MSG
struct msg_new_p2p_call
{
	uint16 net_type;			//�������ͣ�������ţ���ͨ�������
	uint16 peer_type;
	uint32 camera_id;
	uint32 father_id;		//�Է��ڵ�id
	uint32 son_id;	//���ڵ�id
	uint32 son_public_udp_ip;			//�Լ��Ĺ���ip
	uint16 son_public_udp_port;		//�Լ�����port
	uint32 son_local_ip;				//�Լ�˽��ip
	uint16 son_local_port;			//�Լ�˽��port

	//���������ֶ����Թ��������֮����Ϣת��
	uint32 father_manage_server_ip;	//���ڵ����ڵ�managerserver ip
	uint32 son_manage_server_ip;		//�ڷ�������д
	uint32 nat_type;	//·��������
};

//��Ŀ��ڵ����Լ��򶴵ķ��ذ�
struct msg_p2p_call_ack
{
	uint16 net_type;//�������ͣ�������ţ���ͨ�������
	uint16 peer_type;
	uint32 camera_id;
	uint32 father_id;					//�Է��ڵ�id
	uint32 son_id;					//���ڵ�id
	uint32 father_public_udp_ip;		//�Է��Ĺ���ip
	uint16 father_public_udp_port;	//�Է�����port
	uint32 father_local_ip;			//�Է�˽��ip
	uint16 father_local_port;		//�Է�˽��port
	uint32 son_manage_server_ip;		//son �ڵ����ڵ�manage server ip
	uint32 father_manage_server_ip; //�ڷ�������д
};

//PEER_MGR_P2P_CALL_LOCAL_ACK_MSG =20312
struct msg_p2p_call_local_ack
{
	uint16 net_type;//�������ͣ�������ţ���ͨ�������
	uint16 peer_type;
	uint32 camera_id;
	uint32 father_id;					//�Է��ڵ�id
	uint32 son_id;					//���ڵ�id
	uint32 father_public_udp_ip;		//�Է��Ĺ���ip
	uint16 father_public_udp_port;	//�Է�����port
	uint32 father_local_ip;			//�Է�˽��ip
	uint16 father_local_port;		//�Է�˽��port
	uint32 son_manage_server_ip;		//son �ڵ����ڵ�manage server ip
	uint32 father_manage_server_ip; //�ڷ�������д
	
	uint32 session[4];	//���ھ�������½
};

struct client_mod_devicename_req
{ 
	uint32 user_id; 
	uint32 device_id;
	char   device_name[32]; 
};



/*----------------------------------------------------------------------*/

///֪ͨ��ؿͻ���camera���ߵİ�
struct mgr_2_client_camera_offline
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//����camera id
};

///֪ͨ��ؿͻ���camera���ߵİ�
struct mgr_2_client_camera_online
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;				//����camera id
};
///֪ͨͬ��һ���ͻ��Ŀͻ���client���ߵİ�
struct mgr_2_client_client_offline
{
	uint32 custom_id;				//client�����ͻ�id
	uint32 client_id;					//����client id
};
///֪ͨ��ؿͻ���camera���ߵİ�
struct mgr_2_client_client_online
{
	uint32 custom_id;				//client�����ͻ�id
	uint32 client_id;					//����client id
};
///��ȡ���ڲ鿴ͬһ��camera�������������
struct client_2_mgr_partner_list_count
{
	uint32 camera_custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//Ŀ��camera_id
	uint32 camera_status_server_ip;	//camera���ڵ�״̬��������ַ
};
///�������ڲ鿴ͬһ��camera�������������
struct mgr_2_client_partner_list_count
{
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//�鿴��cameraid
	uint32 client_list_count;			//�鿴ͬһ��camera������
};

///����ͬһ���ͻ��µ�����camera�б�
struct client_2_mgr_active_camera_list
{
	uint32 custom_id;				//�ͻ�id
	uint32 company_status_server_ip;	//�ͻ�����״̬��������ַ
};

///����ͬһ���ͻ��µ�����camera�б�
struct mgr_2_client_active_camera_list
{
	uint32 custom_id;				//�ͻ�id
	uint16 camera_count;			//Camera�ĸ���
	active_camera_s camera_arr[0];					//Camera�б�����
};
///����ͬһ���ͻ��µ�����user�б�
struct client_2_mgr_active_user_list
{
	uint32 custom_id;				//�ͻ�id
	uint32 company_status_server_ip;	//�ͻ�����״̬��������ַ
};

///����ͬһ���ͻ��µ�����user�б�
struct mgr_2_client_active_user_list
{
	uint32 custom_id;				//�ͻ�id
	uint16 user_count;				//Camera�ĸ���
	active_member_s user_arr[0];				//Camera�б�����
};

struct client_mgr_get_lm_param
{
	uint32 device_id;
	uint32 user_id;
	uint32 type;   
	uint32 reserver;
};

struct client_mgr_lm_param_ack
{
	uint32 device_id;
	uint32 user_id;
	uint32 luminous;   //0--100
	uint32 reserver;
};





struct client_mgr_start_look_camera
{
	uint32 camera_id;//ϣ���ۿ���camera_id
	uint32 client_id;
	uint16 net_type;
	uint16 peer_type;
	uint32 camera_stat_svr_ip;
	uint32 mgr_svr_ip;
};

struct client_mgr_stop_look_camera
{
	uint32 camera_custom_id;
	uint32 camera_status_svr_ip;
	uint32 camera_id;
	uint32 client_id;
};

struct client_mgr_want_look_video
{
	uint32 camera_id;
	uint32 client_id;
};

struct client_mgr_want_look_video_ack
{
	uint32 camera_id;
	uint32 client_id;
	uint32 camera_vd_svr_ip;
};

struct client_vd_rt_start_look_camera
{
	uint32 camera_id;//ϣ���ۿ���camera_id
	uint32 client_id;//����ۿ���Ƶ�Ŀͻ���id
};

struct client_vd_rt_stop_look_camera
{
	uint32 camera_id;//���ۿ���camera_id
	uint32 client_id;//����ۿ���Ƶ�Ŀͻ���id
};

struct client_vd_camera_rt_hello
{
	uint32 sour_id;//Դ�ڵ�id
	uint32 dest_id;//Ŀ��ڵ�id
};

struct camera_vd_rt_ask_push_video
{
	uint32 camera_id;
};

struct camera_vd_rt_ask_stop_video
{
	uint32 camera_id;
};



///����ۿ��ض�����ͷ����Ȩ
struct client_mgr_req_auth_of_camera
{
	uint32 custom_id;					//����ͷ�����ͻ�id
	uint32 camera_id;					//����ͷid
	uint32 user_id;					//������û�id
	uint32 status_server_ip;			//�ͻ����Ӧ��״̬��������ַ
	uint32 user_manage_server_ip;		//�û��������������ip
	char req_msg[64];						//������Ϣ��
	char user_name[32];						//������û���
};



///����Ա������Ȩ����İ������������
struct client_mgr_req_auth_of_camera_ack
{
	uint32 custom_id;				//����ͷ�����ͻ�id
	uint32 camera_id;					//����ͷid
	uint32 user_id;					//������û�id
	uint32 status_server_ip;			//�ͻ����Ӧ��״̬��������ַ
	uint32 user_manage_server_ip;		//�����û����������������ַ
	uint16 state;								//�ɹ����ı�־ 0 ʧ�ܣ�1 �ɹ�
	char user_name[32];						//������û���
};

struct client_2_mgr_forbid_auth_of_camera
{
	uint32 user_id;					//�û���ʶid
	uint32 user_manage_server_ip;		//�����û����������������ַ
};


///ɾ������ͷ�ϵ���Ȩ�û�
struct client_2_mgr_del_auth_of_camera
{
	uint32 custom_id;				//����ͷ�����ͻ�
	uint32 camera_id;					//����ͷid
	uint32 admin_id;					//ִ��ɾ�����ܵĹ���Աid
	uint32 user_id;					//������ɾ����Ȩ���û�id
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//camera�����߹��������

///�ڵ㣨camera���������߹����������
struct device_2_mgr_sign_in
{
	uint32 device_id;					//�ڵ�ı�ʶid
	uint32 custom_id;				    //
	uint32 group_id;					//camera��������
	uint16 net_type;
	uint16   visible_level;					//camera�ɼ�����
	char   session_id[128];					//��֤session��ʶid
	int32		camera_num;						//���豸��camera��Ŀ
	uint32  camera_id_list[0];              //���豸camera_id�б�
};

struct device_2_mgr_sign_out
{
	uint32 device_id;					//�ڵ�ı�ʶid
	uint32 custom_id;				    //0 = camera,1 = client
	uint32 group_id;					//camera��������
	uint16 net_type;
	char session_id[128];					//��֤session��ʶid
	int32		camera_num;						//���豸��camera��Ŀ
	uint32  camera_id_list[0];              //���豸camera_id�б�
};

struct camera_2_mgr_sign_in
{
	uint32 camera_id;					//�ڵ�ı�ʶid

	uint32 custom_id;				//0 = camera,1 = client
	uint16 net_type;
	int visible_level;						//camera�ɼ�����
	char session_id[128];					//��֤session��ʶid
};

struct camera_2_mgr_sign_out
{
	uint32 camera_id;					//�ڵ�ı�ʶid
	uint32 custom_id;				//0 = camera,1 = client
	uint16 net_type;
	char session_id[128];					//��֤session��ʶid
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//camera�����߹��������
struct peer_vd_sign_in
{
	unsigned int peer_id;					//�ڵ�ı�ʶid
	char session_id[128];					//	��֤session��ʶid
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//���߹�������������߹��������

///��Ŀ��ڵ����Լ��򶴵ķ��ذ���ת����
//��Ŀ��ڵ����Լ��򶴵������
struct mgr_mgr_p2p_call
{
	uint32 father_id;		//�Է��ڵ�id
	uint32 son_id;	//���ڵ� id
	uint32 son_public_udp_ip;			//�Լ��Ĺ���ip
	uint16 son_public_udp_port;		//�Լ�����port
	uint32 son_local_ip;				//�Լ�˽��ip
	uint16 son_local_port;			//�Լ�˽��port
	uint32 ret_dest_mgr_ip;
	uint32 source_key;							//Դ�ڵ��ʶ��
};

//��Ŀ��ڵ����Լ��򶴵ķ��ذ�
struct mgr_mgr_p2p_call_ack
{
	uint32 father_id;					//�Է��ڵ�id
	uint32 son_id;					//���ڵ� id
	uint32 father_public_udp_ip;		//�Է��Ĺ���ip
	uint16 father_public_udp_port;	//�Է�����port
	uint32 father_local_ip;			//�Է�˽��ip
	uint16 father_local_port;		//�Է�˽��port
	uint32 source_key;							//Դ�ڵ��ʶ��
};

///�����������������CAMERA������Ϣ
struct mgr_mgr_camera_offline
{
	uint32 custom_id;				//�����ͻ��ı�ʶid
	uint32 camera_id;					//���߽ڵ�ı�ʾid
};


///�����������������CLIENT������Ϣ
struct mgr_mgr_client_offline
{
	uint32 camera_id;				//����camera�ı�ʾid
	uint32 client_id;				//����client�ı�ʾid
	uint32 custom_id;			//�ͻ��������ͻ�id
};

struct  device_runtime_audio 
{
	uint32   camera_id;
	uint32   client_id;        
	uint32   type;      //1
	uint32   params[3];       // 0: disable   1: enable 
};

///�����������������CAMERA������Ϣ
struct mgr_mgr_camera_online
{
	uint32 custom_id;			//�����ͻ��ı�ʶid
	uint32 camera_id;				//����camera�ı�ʾid
};


///�����������������CLIENT������Ϣ
struct mgr_mgr_client_online
{
	uint32 client_id;				//����client�ı�ʾid
	uint32 custom_id;				//�ͻ��������ͻ�id
};


///������������������ۿ���Ƶ��Ϣ
struct mgr_mgr_start_look_camera
{
	uint32 client_id;				//�ۿ�camera��client id
	uint32 camera_id;				//���ۿ���camera id
};

///�����������������ֹͣ�ۿ���Ƶ��Ϣ
struct mgr_mgr_stop_look_camera
{
	uint32 client_id;				//ֹͣ�ۿ�camera��client id
	uint32 camera_id;				//ֹͣ���ۿ���camera id
};

///Ҫ�������֪ͨĳЩ�ڵ�����ָ��������
struct mgr_mgr_ask_client_connect
{
	uint32 dest_ip;					//Ŀ�������ip
	uint16 dest_port;				//Ŀ��������˿�
	uint32 client_count;				//֪ͨ�Ľڵ����
	client_s client_arr[0];					//֪ͨ�Ľڵ���ϸ��Ϣ
};



///�ۿ�����ͷ������Ȩת����
struct mgr_mgr_req_auth_of_camera
{
	uint32 user_id;					//�����û���ʶid
	uint32 custom_id;				//camera�����ͻ�id
	uint32 camera_id;					//����ۿ���camera_id
	uint32 user_manage_server_ip;		//�����û����ڹ��������ip
	uint32 status_server_ip;			//�����ͻ��ֲ���״̬������
	uint32 admin_id;					//����Աid
	char req_msg[64];						//������Ϣ��
	char user_name[32];						//�����û����û���
};

///Ϊĳ�û��ۿ�����ͷ��Ȩ�ɹ�����״̬��
struct mgr_mgr_auth_of_camera_status
{
	int16 status;								//״̬
	uint32 user_id;					//�����û���id
	uint32 source_key;							//Դ�ڵ��ʶ��
};



//////////////////////////////////////////////////////////////////////////////////////////////////////
//�ڵ����Ϣ����
// p2pstun,����Ϣ
struct msg_p2p_stun
{
	uint32 camera_id;
	uint32 son_id;
	uint32 father_id;
};

// p2pstunack,��Ӧ����Ϣ
struct msg_p2p_stun_ack
{
	uint32 camera_id;
	uint32 son_id;
	uint32 father_id;
};

// p2pstunack,��Ӧ����Ϣ
struct msg_p2p_stun_ack_ack
{
	uint32 camera_id;
	uint32 son_id;
	uint32 father_id;
};

typedef struct pano_info
{
	long lWidth;
	long lHeight;
	long lCenterX_1024;
	long lCenterY_1024;
	long lRadius_1024;
	long lPanoType;
	long lPanoTilt;
};

//��ʼ������,���ڵ����ӽڵ�������Ϣ
struct msg_init_param //��ʼ���ͻ���buffer �߽���Ϣ
{
	uint32 camera_id;
	uint32 min_block_seq;//֡����С�߽�
	uint32 max_block_seq;//֡�����߽�
	uint32 device_type;		//OEM device type
	uint16 decode_head_size;
	char   decode_head[0];
};// buffermap��Ϣ,������Ϣ

struct msg_buffermap
{
	uint32 camera_id;
	uint32 father_id;//����buffermap�Ľڵ�
	uint32 son_id;//����buffermap�ڵ�
	uint32 begin_block_seq;
	uint32 end_block_seq;
	uint32 map_data_size;
	char   map_data[0];
};

//������������
struct msg_ask_pushdata
{
	uint32 camera_id;
	uint32 peer_id;//�����������ݵĽڵ�id
	int		video_type;   //������������video type
};

struct msg_ask_pushdata_ack
{
	uint32 camera_id;
	uint32 peer_id;//�����������ݵĽڵ�id
	int	   result;  //0: Success  1: Has look history 2: Has dwonload history file 3.has look alarm video
};

struct msg_stop_pushdata
{
	uint32 camera_id;
	uint32 peer_id;
};

//��������
struct msg_ask_data
{
	uint32 camera_id;
	uint32  frm_block_seq;//С�����
	uint32 son_id;//�������ݷ�
};
//����
struct msg_data
{
	uint32 camera_id;
	uint32 father_id;	//�������ݷ�
	uint16 frm_type;			//֡����,0 = i ,1= p
	uint32 frm_seq;
	uint32 frm_block_seq;
	uint16 inner_block_seq;		//��0��ʼ��ŵ�frm_block_count -1
	uint16 frm_block_count;
	uint32 data_size;		   //
	char data[0]; //����
};

struct msg_p2p_data_ack
{
	uint32 camera_id;
	uint32 src_clientid;
	uint32 dst_clientid;
	int	   video_type;
	int	   last_recv_packets;
};
//keepalive
struct  msg_p2p_keepalive
{
	uint32   src_id;
	uint32	 dst_id;
};

//for  P2P_CONNECT_VIDEO_MSG
struct  msg_p2p_connect_video
{
	uint32	 src_peerid;
	uint32   dst_peerid;
	uint16		 net_type;
	uint16		 video_type;               //video type : realtime or history or normal
	uint32   camera_id;
};
//for  P2P_CONNECT_VIDEO_ACK_MSG
struct  msg_p2p_connect_video_ack
{
	uint32	 src_peerid;
	uint32   dst_peerid;
	uint16		 net_type;
	uint32   camera_id;
	uint16		 video_type;			//video type : realtime or history or normal
	int32		 response;             //0 : success  1: failed,more son nodes, 2: failed, no camera video.
};

//for  P2P_CLOSE_VIDEO_MSG
struct  msg_p2p_close_video
{
	uint32	 src_peerid;
	uint32   dst_peerid;
	uint16	 net_type;
	uint32   camera_id;
	uint16	 video_type;			//video type : realtime or history or normal
	int32      close_reason;          // reason for close this video , 0 : normal
};

struct client_mgr_get_vol_param
{
	uint32 device_id;
	uint32 user_id;
};

struct client_mgr_vol_param
{
	uint32 device_id;
	uint32 user_id;
	uint32 options;  // ����ѡ��;
	uint32 values;	 //  &options = 1 ��  0 ��	
	uint32 volume;   // 0-100 ����
	uint32 control;   //���� 
};

struct client_mgr_get_device_mdata
{
	uint32 device_id;
	uint32 user_id;
};

struct client_mgr_device_mdata
{
	unsigned int device_id;
	unsigned int user_id;
	unsigned int wifi_db;
	unsigned int local_ip;
	char   mac[18];
	char   version[16];
	char   currentssid[16];

};

struct mgr_device_relogin
{
	uint32 device_id;
	uint32 user_id;
};

//for P2P_SET_PUB_AUDIO_MSG
struct  msg_p2p_set_audio
{
        uint32   src_peerid;
        uint32   dst_peerid;
        uint16   net_type;
        uint16   type;
        uint32   camera_id;
        uint32   value;
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
//client�����ݷ�����

///��ȡ�ͻ��ͻ��б�
struct client_2_data_customer_list
{
	uint32 read_line_start;//��ȡ����ʼλ��
	uint32 read_line_count;//��ȡ������
};

//���صĿͻ��б�
struct data_2_client_customer_list
{
	uint32 customer_count;
	custom_s customers[0];
};

///����custom_id��ȡ�ͻ�������camera������Ϣ�Լ�camera��Ϣ
struct client_2_data_company_group_camera_info
{
	uint32 custom_id;					//Ŀ��ͻ���ʾid
	uint32 client_id;					//user client id
	uint16 is_recommend;					//�Ƿ��ǻ�ȡ�Ƽ���Ƶ 0 = �Ƽ� 1 = ����
};

///���������Ϳͻ�camera������Ϣ���ͻ���
struct data_2_client_company_groups
{
	uint32 custom_id;				//�ͻ��ı�ʾid
	uint32 status_server_ip;			//�ͻ�����״̬������
	uint16 camera_group_count;					//camera��������
	char brand_name[64];					//Ʒ������
	camera_group_s groups[0];				//������Ϣ����
};

///���������Ϳͻ�camera�б���Ϣ���ͻ���
struct data_2_client_company_cameras
{
	uint32 custom_id;				//�ͻ��ı�ʾid
	uint32 camera_count;						//camera����
	camera_s arr[0];						//camera��Ϣ����
};

struct  client_alarm_process_msg
{
	uint32   record_id;	//add
	uint32   status;    //alarm_msg process(for user)   1:APP�ѽ��ո澯;2:�û�����;3:�û��鿴
};

struct  device_alarm_server_upload_msg
{
	uint32   client_id;	   //custom_id
	uint32   record_id;
	uint32   device_id;
	uint32   camera_id;
	uint32   channel_no;         //
	uint32   alarm_type;         //�������� enum  CAMERA_ALARM_TYPE
	uint32   begin_time;		 //������ʼʱ��
	uint32   end_time;           //��������ʱ�� 
	uint32   alarm_mode;         // 0x01,ͼƬ  0x02 ��Ƶ
	uint32   alarm_code;	     //�������
	uint32   ccid;               //Ӳ�̷���
};

struct client_mgr_set_camera_alarm_param
{
	uint32 	nstate;			// 0:close 1:open
	uint32	reserver[3];    // ��������
};


struct client_mgr_set_camera_alarm_note_msg
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	uint32 alarm_type;
	uint32 channel_no;
	client_mgr_set_camera_alarm_param param;
};

struct client_mgr_get_camera_alarm_note_msg  
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	uint32 alarm_type;
	uint32 channel_no; 
};

struct client_mgr_get_camera_alarm_note_ack_msg 
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	uint32 alarm_type;
	uint32 channel_no;
	client_mgr_set_camera_alarm_param   param;
};

struct client_mgr_get_camera_alarm_data_msg 
{
	uint32   camera_id;
	uint32   client_id;
	uint32   custom_id;
	uint32   device_id;
	uint32   channel_no;
	uint32   alarm_type;
	uint32   begin_time;		//������ʼʱ��
	uint32   end_time;           //��������ʱ�� 
	uint32   alarm_mode;         // 0x01,ͼƬ  0x02 ��Ƶ
	uint32   alarm_code;	//�������
	uint32   ccid;          //Ӳ�̷���
};

struct  device_alarm_upload_msg
{
	uint32   device_id;
	uint32   camera_id;
	uint32   channel_no;         
	uint32   alarm_type;         //�������� enum  CAMERA_ALARM_TYPE
	uint32   begin_time;	     //������ʼʱ��
	uint32   end_time;           //��������ʱ�� 
	uint32   alarm_mode;         //0x01 ͼƬ  0x02 ��Ƶ
	uint32   alarm_code;	     //�������
	uint32   ccid;               //Ӳ�̷���
};

struct alarm_msg_data
{
	uint32 camera_id;
	uint32 father_id;	//�������ݷ�
	uint16 frm_type;			//֡����,0 = i ,1= p  ,����FRAME_TYPE_ALARM_JPEG =61; 
	uint32 frm_seq;
	uint32 frm_block_seq;
	uint16 inner_block_seq;		//��0��ʼ��ŵ�frm_block_count -1
	uint16 frm_block_count;
	uint32 data_size;				//����������ų���;
	uint32 alarm_code;	//�������
	char   data[0]; //����
};


///���ؿͻ�Ա���б����Ϣ��
struct data_2_client_users
{
	uint32 custom_id;				//�ͻ��ı�ʶid
	uint32 user_count;							//�ͻ�Ա������
	user_s	arr[0];							//Ա����Ϣ����
};

///�����û���ϸ��Ϣ��
struct client_2_data_user_detail
{
	uint32 user_id;					//�û���ʶid
	char user_name[32];						//�û���
};


///�����û���ϸ��Ϣ��
struct data_2_client_user_detail
{
	uint32 user_id;					//�û�id
	char user_name[32];						//�û���
	char real_name[64];						//�û���ʵ����
	char phone[20];							//�绰����
	char email[64];							//email��ַ
	char nick_name[32];						//�û��ǳ�
};

///����ͻ���ϸ��Ϣ��
struct client_2_data_company_detail
{
	uint32 custom_id;				//�ͻ��ı�ʶid
};

///���ؿͻ���ϸ��Ϣ��
struct data_2_client_company_detail
{
	uint32 custom_id;				//�ͻ��ı�ʶid
	uint16 is_authorized;						//�Ƿ���Ȩ
	char company_name[128];					//�ͻ�����ҵ����
	char company_code[32];					//��ҵ����
	char brand_name[64];					//Ʒ������
	char addr[128];							//�ͻ���ַ
	char phone[20];							//�ͻ��绰
	char email[64];							//email��ַ
	char coment[500];						//�ͻ�����
};

///����camera��ϸ��Ϣ�İ�
struct client_2_data_camera_detail
{
	uint32 camera_id;					//camera��ʶid
};

///����camera��ϸ��Ϣ�İ�
struct data_2_client_camera_detail
{
	uint32 camera_id;					//camera��ʶid
	uint32 video_rate;							//��Ƶ����
	uint32 custom_id;				//�����ͻ�id
	uint32 group_id;					//������id
	int16 visible;							//������
	uint32 made_date;							//��������
	uint16 online;								//����״̬
	uint16 history_support;						//�Ƿ�֧����ʷ
	uint16 realtime_support;					//�Ƿ�֧��ʵʱ
	uint16 ptctrl_support;					//�Ƿ�֧����̨����
	char position[64];						//cameraλ��
};

///�����û��ĸ�����ϸ��Ϣ��������
struct client_2_data_update_user_info
{
	uint32 user_id;					//�û���ʶid
	char real_name[64];						//��ʵ����
	char passwd[64];						//����
	char phone[20];							//�绰����
	char nick_name[32];						//�ǳ�
};

///���ظ����û��ĳɹ����״̬��
struct data_2_client_update_user_info
{
	uint16 status;								//����״̬
};

///�鿴�û�Ȩ�޵İ�
struct client_2_data_user_right
{
	uint32 user_id;					//�û���ʶid
};

///�����û�Ȩ�ް�
struct data_2_client_user_right
{
	uint16 right_count;						//Ȩ�޸���
	right_s arr[0];							//Ȩ����������
};



struct client_2_data_alarm
{
	uint32	camera_id;
	uint32	client_id;
	uint32  alarm_total_count;			//total alarm count 
	uint32	alarm_count;				//alarm count for this packet
	alarm_record_s  alarm_rec[0];
};

struct client_2_data_get_alarm
{
	uint32	camera_id;
	uint32	client_id;
	uint32  begin_alarm_id;     // First it is 0, 
	uint32  req_count;			//request alarm count per packet
	uint32  only_processed;     //0: all alarm records 1: Only get processed alarm record 
	char	begin_date[32];     //'2011-07-14 14:25:03'  
	char	end_date[32];
};

/////////////////////////////////////////////////////
//////////////////////////////////////////
struct msg_get_public_addr
{
	uint32 peer_id;
};

struct msg_public_addr_ack
{
	uint32 peer_id;
	uint32 public_ip;
	uint16 public_port;
};


//��ȡ���client_id
struct msg_req_client_id
{
	uint16 net_type;
};

struct msg_client_id_ack
{
	uint32 client_id;
	uint32 mgr_svr_ip;
	uint32 stat_svr_ip;
};

//Զ������camera
struct msg_camera_reboot
{
	uint32 camera_id;//��Ҫ������camera
	uint32 client_id;//�����ߵ�id
};

//����Զ����־
struct msg_camera_remote_log_start
{
	uint32 camera_id;//��Ҫ��Զ����־��camera
	uint32 client_id;//������client_id
	uint32 log_svr_ip;//Զ����־��������ip
	uint16 log_svr_port;//Զ����־��������port
};

struct msg_camera_remote_log_stop
{
	uint32 camera_id;//��Ҫ�ر�Զ����־��camera
	uint32 client_id;//������client_id
};

struct msg_want_look_rt_video
{
	uint32 camera_id;
	uint32 client_id;
};

struct msg_want_look_rt_video_ack
{
	uint32 camera_id;
	uint32 client_id;
	uint32 camera_vd_svr_ip;//�����camera�ڵ�¼֮�󷵻ص��м̷�������ַ
};

struct hist_video_file
{
	uint32 file_size;
	uint32 begin_time;
	uint32 end_time;
};


struct msg_want_look_hist_video
{
	uint32 camera_id;
	uint32 client_id;
	uint32 File_begin_time;
	uint32 file_end_time;
	uint16 look_type;              // 0:normal  1: forcely
};


struct msg_want_look_hist_video_ack
{
	uint32 camera_id;
	uint32 client_id;
	uint32 File_begin_time;
	uint32 file_end_time;
	uint16 result;		// 0: success  1: fail, other hist has been open 2: fail,other realtime is looking
};

struct msg_pt_move_left
{
	uint32 camera_id;
	uint32 client_id;
};

struct msg_pt_move_right
{
	uint32 camera_id;
	uint32 client_id;
};


struct msg_pt_move_up
{
	uint32 camera_id;
	uint32 client_id;
};


struct msg_pt_move_down
{
	uint32 camera_id;
	uint32 client_id;
};

struct msg_pt_foucus_near
{
	uint32 camera_id;
	uint32 client_id;
};

struct msg_pt_foucus_far {
	uint32 camera_id;
	uint32 client_id;
};

struct msg_pt_move_stop {
	uint32 camera_id;
	uint32 client_id;
};

struct client_vd_hist_start_look_video
{
	uint32 client_id;
	uint32 camera_id;
	uint32 begin_time;
	uint32 end_time;
	uint32 begin_frame;     //��ʼ֡��
};

struct client_vd_hist_stop_look_video
{
	uint32 client_id;
	uint32 camera_id;
	uint32 begin_time;
	uint32 end_time;
};


struct client_vd_ask_push_hist_video
{
	uint32 camera_id;
	uint32 begin_time;
	uint32 end_time;
	uint32 begin_frame;   //��ʼ֡��
};

struct client_vd_ask_stop_hist_video
{
	uint32 camera_id;
	uint32 begin_time;
	uint32 end_time;
};


struct client_vd_pause_push_video
{
	uint32 client_id;
	uint16 camera_group_count;
	uint32 camera_id[0];
};

struct client_vd_restart_push_video
{
	uint32 client_id;
	uint16 camera_group_count;
	uint32 camera_id[0];
};

struct hist_skip_video
{
	uint32 camera_id;
	uint32 client_id;
	uint32 start_frame;
};

struct msg_hist_video
{
	uint32 camera_id;
	uint32 begin_time;
	uint32 end_time;
	uint32 cur_frame;
	uint32 max_frames;
	uint16 frm_type;			//֡����,0 = i ,1= p
	uint32 frm_seq;
	uint32 frm_block_seq;
	uint16 inner_block_seq;		//��0��ʼ��ŵ�frm_block_count -1
	uint16 frm_block_count;
	uint32 data_size;				//
	char data[0]; //����
};

//���ڵõ�������cameraͼ�����
struct  msg_get_picture_param
{
	uint32 	 camera_id;
	uint32   src_clientid;
	uint32   dst_clientid;
};

//CAMERA_SET_PICTURE_PARAM
struct  msg_picture_param
{
	uint32  camera_id;
	uint32  src_clientid;
	uint32  dst_clientid;
	int		brightness;		//ͼ������
	int		contrast;			//ͼ��Աȶ�
	int		hue;				//ͼ��ɫ��
	int		saturation;		//ͼ�񱥺Ͷ�
	int	acute;				//ͼ����� <---- by 20121211
};

//////////////////////////////////////////////////////////////////////////

struct  msg_get_video_param
{
	uint32 	 camera_id;
	uint32   src_clientid;
	uint32   dst_clientid;
};
//////////////////////////////////////////////////////////////////////////

struct  msg_video_param
{
	uint32    camera_id;
	uint32    src_clientid;
	uint32    dst_clientid;
	int		  flow_type;			//�����ͣ�video������video/audio��
	int    	  bitrate_type;		//�������������ͣ��ɱ�Ļ�̶���
	int   	  bitrate;				//����������
	int		  video_quality;		//��Ƶ����
	int		  frame_rate;			//��Ƶ��֡����
};

struct  msg_get_init_param
{
	uint32		camera_id;
	uint32		src_clientid;
	uint32		dst_clientid;
	uint16		video_type;           //ָ��realtime,normal,history
	uint16      padding;
};

struct msg_want_download_hist_file
{
	uint32 camera_id;
	uint32 client_id;
	uint16 download_type;              // 0:normal  1: forcely
};

struct msg_want_download_hist_file_ack
{
	uint32   camera_id;
	uint32   client_id;
	uint32   result;		//0: �ɹ�����enum HIST_LOOK_REPONSEֵ�������档
	uint32   camera_vd_svr_ip;//�����camera�ڵ�¼֮�󷵻ص��м̷�������ַ
};

struct client_vd_start_download_hist_file
{
	uint32 camera_id;
	uint32 client_id;
	uint32 begin_time;      //
	uint32 end_time;
	uint32 begin_frame;     //��ʼ֡��
};

struct client_vd_stop_download_hist_file
{
	uint32 camera_id;
	uint32 client_id;
	uint32 begin_time;
	uint32 end_time;
};

struct client_vd_download_hist_file_finished
{
	uint32 camera_id;
	uint32 client_id;
	uint32 begin_time;
	uint32 end_time;
	uint32 last_frame_timestamp;  //���һ֡��timestamp,��ֹ��Ϣ�ȵ��������ݺ󵽵����
};

struct msg_vd_download_hist_data_ack
{
	uint32  camera_id;
	uint32  client_id;
	uint32  last_frameid;
};

struct  msg_ask_multiple_data
{
	uint32   msg_id;       //��Ϣ��ID�ţ���Ȼ����������ֵ
	uint32   camera_id;
	uint32   client_id;
	uint16	 ask_packet_num;    //����Ϣ���������������
    struct msg_ask_data   ask_data[0];
};

///track//////////////////////////////////////////////////////////////////////
struct client_tk_start_look_camera
{
	uint32 camera_id;//ϣ���ۿ���camera_id
	uint32 client_id;
	uint16 net_type;
	uint16 peer_type;
};

///��camera�����ɾ���������
struct client_tk_stop_look_camera
{
	uint32 camera_id;					//Ŀ��camera_id
	uint32 client_id;					//��ɾ����clientid
	uint16 net_type;
	uint16 peer_type;
};

struct client_tk_get_partner_list
{
	uint32 camera_id;					//Ŀ��camera_id
	uint32 client_count;				//����ĸ���
	uint16 net_type;
	uint16 peer_type;
};


///����camera��ص�client �б�ķ��ذ�
struct client_tk_partner_list_ack
{
	uint32 camera_id;					//��ص�camera�ı�ʶId
	uint16 client_count;				//�ͻ��˵ĸ���
	client_s client_array[0];				//�ͻ���������׵�ַ
};

///��ȡ���ڲ鿴ͬһ��camera�������������
struct client_tk_get_partner_list_count
{
	uint32 camera_id;					//Ŀ��camera_id
};

///�������ڲ鿴ͬһ��camera�������������
struct client_tk_partner_list_count_ack
{
	uint32 camera_id;					//��ص�camera�ı�ʶId
	uint32 client_list_count;			//�鿴ͬһ��camera������
};

struct client_tk_p2p_call
{
	uint16 net_type;			//�������ͣ�������ţ���ͨ�������
	uint16 peer_type;
	uint32 camera_id;
	uint32 father_id;		//�Է��ڵ�id
	uint32 son_id;	//���ڵ�id
	uint32 son_public_udp_ip;			//�Լ��Ĺ���ip
	uint16 son_public_udp_port;		//�Լ�����port
	uint32 son_local_ip;				//�Լ�˽��ip
	uint16 son_local_port;			//�Լ�˽��port
};

//��Ŀ��ڵ����Լ��򶴵ķ��ذ�
struct client_tk_p2p_call_ack
{
	uint16 net_type;//�������ͣ�������ţ���ͨ�������
	uint16 peer_type;
	uint32 camera_id;
	uint32 father_id;					//�Է��ڵ�id
	uint32 son_id;					//���ڵ�id
	uint32 father_public_udp_ip;		//�Է��Ĺ���ip
	uint16 father_public_udp_port;	//�Է�����port
	uint32 father_local_ip;			//�Է�˽��ip
	uint16 father_local_port;		//�Է�˽��port
};


////////////////////////////////////////////////
///im

struct msg_chat_content
{
	uint32 src_user_id;								//Դ�û�id
	uint32 dest_user_id;							//Ŀ���û�id
	char   src_nick_name[MAX_NICK_NAME_SIZE];		//Դ�û�����
	uint32	send_time;								//�������ݷ�������
	font_s	m_tFont;								//��������
	uint16 content_size;							//������Ϣ��С
	char contents[0];								//��������
} ;

struct msg_chat_shake
{
	uint32 src_user_id;
	uint32 dest_user_id;
};

//////////////////////////////////////////
///For security center 
/////////////////////////////////////////////
struct get_camera_netinfo
{
	uint32    camera_id;
	uint32	  client_id;
};

struct get_camera_netinfo_ack
{
	uint32    camera_id;
	uint32	  client_id;
	uint32    public_ipaddr;
	uint32	  local_ipaddr;
	uint32	  gateway_ipaddr;
	uint32    net_isp_type;
	uint32    net_isp_type_mode;  //0:auto probe 1:tel 2:cnc
};

struct client_apply_salt_req
{ 
	char user_name[64];
	uint16 user_type;  
};

struct client_apply_salt_ret
{
	char salt[16];
};

struct set_camera_net_isptype
{
	uint32    camera_id;
	uint32	  client_id;
	uint32    net_isp_type;
};

struct get_device_info
{
	uint32    camera_id;
	uint32	  client_id;
};

struct get_device_info_ack
{
	uint32    camera_id;
	uint32	  client_id;
	char	  version_hardware[16];
	char	  version_software[16];
	char	  version_oem_sdk[16];
	uint32	  public_ipaddr;
	uint32	  local_ipaddr;
	char	  mac_addr[24];
	uint32	  free_mem_size;
	uint32	  free_flash_size;
	uint32	  has_disk;
};

enum  CAMERA_ALARM_TYPE
{
	ALARM_TYPE_OFFLINE,
	ALARM_TYPE_LOST_VIDEO,
	ALARM_TYPE_MASK_VIDEO,
	ALARM_TYPE_DETECTION_MOTION,
	ALARM_TYPE_DISK_FULL,
	ALARM_TYPE_RECORD_ABNORMAL,
	ALARM_TYPE_LOG_LAMP_OFF,           //Log����ϵ� 
	ALARM_TYPE_LED_SCREEN_OFF,         //LED��Ļ�ϵ�
	ALARM_TYPE_TALK_REQUEST,           //����ͨ������
	ALARM_TYPE_LOG_LAMP_ON,           //Log�����ϵ� 
	ALARM_TYPE_LED_SCREEN_ON,         //LED��Ļ�ϵ�
	
	//by ¼��ʧ����
	ALARM_TYPE_LOST_RECORD,

	ALARM_TYPE_ONLINE = 20,
	//by �ޱ���
	//20120518
	ALARM_TYPE_NULL = 100,
};

struct camera_alarm
{
	uint32		camera_id;
	uint32		alarm_type;
	uint32      alarm_id;         //id of alarm record in database
	char		alarm_msg[32];
};

struct forward_camera_alarm
{
        uint32          admin_id;
        uint32          camera_id;
        uint32          alarm_type;
        uint32          alarm_id;         //id of alarm record in database
        char            alarm_msg[32];
};

struct alarm_2_mgr_alarm_msg
{
        int forward_alarm_num;
        struct forward_camera_alarm fcamera_alarm[0];
};

struct server_login_alarm_req
{
        unsigned int server_ip;
        unsigned int port;
};

struct camera_alarm_ack_msg
{
        uint32 camera_id;
        uint32 alarm_id;
        uint32 ack_msg;
        uint32 padding;
};


struct get_motion_detection_param
{
	uint32		camera_id;
	uint32		client_id;
};

struct motion_detection_param
{
	uint32		camera_id;
	uint32		client_id;
	uint32		begin_time;	//��ʼʱ�䣬����
	uint32		end_time;		//����ʱ�䣬����
	uint32		delay;      
	uint32 		trigger_record;
	uint32		trigger_alarm;
	uint32		detection_sense;   //�ƶ����������:0-�����;1-5������,ֵԽ��Խ����
	uint32		flag_buzz;		//�Ƿ������ط�����0: �� 1����
};

enum  MOTION_DETECTION_SENSE
{
	MOTION_DETECTION_STOP=0,
	MOTION_DETECTION_SENSE_1,
	MOTION_DETECTION_SENSE_2,
	MOTION_DETECTION_SENSE_3,
	MOTION_DETECTION_SENSE_4,
	MOTION_DETECTION_SENSE_5,
};

struct get_lost_video_param
{
	uint32		camera_id;
	uint32		client_id;
};

struct lost_video_param
{
	uint32		camera_id;
	uint32		client_id;
	uint32		begin_time;	//��ʼʱ�䣬����
	uint32		end_time;		//����ʱ�䣬����
	uint32		delay;      
	uint32 		trigger_record;
	uint32		trigger_alarm;
	uint32		flag_buzz;		//�Ƿ������ط�����0: �� 1����
};

struct get_mask_video_param
{
	uint32		camera_id;
	uint32		client_id;
};

struct mask_video_param
{
	uint32		camera_id;
	uint32		client_id;
	uint32		begin_time;	//��ʼʱ�䣬����
	uint32		end_time;		//����ʱ�䣬����
	uint32		delay;      
	uint32 		trigger_record;
	uint32		trigger_alarm;
	uint32		flag_buzz;		//�Ƿ������ط�����0: �� 1����
};

struct set_preset_point
{
	uint32  camera_id;
	uint32  client_id;
	uint32  preset_no;
	uint32  preset_flag;	//0:add 1: del  2: to 
};



struct  start_stop_cruise_path
{
	uint32	 camera_id;
	uint32	 client_id;
	uint32   cruise_path_no;
};

struct  set_yuntai_mode
{
	uint32	camera_id;
	uint32	client_id;
	uint32  yuntai_mode;
	uint32	mode_param;
};

enum  YUNTAI_MODE
{
	YUNTAI_MODE_USER,
	YUNTAI_MODE_CRUISE,
	YUNTAI_MODE_WATCH,
};

struct  get_system_time
{
	uint32	 camera_id;
	uint32   system_time;
};

struct  set_alarm_upload
{
	uint32	camera_id;
	uint32   client_id;
	uint32   is_alarm_upload;   //0: �ر� 1������
};

struct  switch_alarm_param
{
	uint32   camera_id;
	uint32   channel_no;        //ͨ����
	uint32   begin_time;		//������ʼʱ��
	uint32   end_time;           //��������ʱ�� 
	uint32   alarm_type;         //��������
	uint32   alarm_mode;         //ָ���ߵ͵�ƽ��0���͵�ƽ 1���ߵ�ƽ
};

struct  set_switch_alarm_param
{
	uint32   camera_id;
	uint32   client_id;              //���ͷ�
	struct   switch_alarm_param    switch_param;  //     
};

struct  get_switch_alarm_param
{
	uint32   camera_id;
	uint32   client_id;              //���ͷ�
};

struct  get_switch_alarm_param_ack
{
	uint32   camera_id;
	uint32   client_id;              //���ͷ�
	uint32   count;				//  ָ�����в�������ĸ�����
	struct   switch_alarm_param    switch_param[0];  // 
};

struct  set_switch_device
{
	uint32   camera_id;			//���豸�˲������ϸ�ָ�� �豸����ͨ��channel_no�ж�
	uint32   client_id;         //���ͷ�
	uint32   channel_no;        //ͨ���� ��0��ʼ
	uint32   device_type;         //�����豸����  1��LED�ƣ�2��LCD��Ļ
	uint32   switch_mode;         //ָ�����أ�0���� 1����
	//by 20120518
	//�ṩ�������Զ��� ʹ֮�������Զ�ģʽ�� ��ĳ��ʱ������Ч
	uint32   auto_mode;			//�Զ�״̬ 0���ֶ����� 1���Զ����� 2���������
	uint32   begin_time;		//������ʼʱ��
	uint32   end_time;          //��������ʱ�� 
};

//////////////////////////////////////////////////////////////////////////
//by 
//20120518
struct  get_switch_device_param
{
	uint32   camera_id;
	uint32   client_id;              //���ͷ�
};

struct  get_switch_device_param_ack
{
	uint32   camera_id;
	uint32   client_id;              //���ͷ�
	uint32   count;				//  ָ�����в�������ĸ�����
	struct   set_switch_device    switch_device[0];  // 
};

struct  realtime_stream_type
{
	uint32	 camera_id;
	uint32   client_id;
	uint32   stream_type;   //0: ������ 1��������1
};

struct  set_runtime_audio 
{
	uint32   camera_id;
	int		 audio_enable;          // 0: disable   1: enable 
};

////////////////////////////////////
struct camera_2_mgr_vca_data_report
{
	uint32 camera_id;    //�����ϴ���camera id
	uint32 vca_id;       //�󶨵����ܴ�����
	char   begin_time[24];  //��ʼʱ�䣬��ʽΪ"2011-11-11 11:11:11"���ַ���  
	char   end_time[24];  //��ֹʱ�䣬��ʽΪ"2011-11-11 11:11:11"���ַ���
	uint32 val;          //��ֵ
};

struct mgr_2_camera_vca_data_report_ack
{
	uint32 camera_id;     //�����ϴ���camera id
	uint32 vca_id;        //�󶨵����ܴ�����
};

struct client_2_infosvr_query_vca_data
{
	uint32 vca_id;            //�󶨵����ܴ���������
	uint32 val;					//ͳ����ֵ
	char   begin_time[24];    //��ʼʱ�䣬��ʽΪ"2011-11-11 11:11:11"���ַ���  
	char   end_time[24];      //��ֹʱ�䣬��ʽΪ"2011-11-11 11:11:11"���ַ���
};

struct client_2_infosvr_query_vca_data_list
{
	uint32 client_id;         //����Ŀͻ���
	uint32 camera_id;         //�����camera id
	uint32 query_num;         //�����ʾ����
	uint32 counts;            //��������
	char   begin_time[24];    //��ʼʱ�䣬��ʽΪ"2011-11-11 11:11:11"���ַ���  
	char   end_time[24];      //��ֹʱ�䣬��ʽΪ"2011-11-11 11:11:11"���ַ���
	struct client_2_infosvr_query_vca_data data_list[0];  //������׵�ַ
};

///used by  broadcast server alive message
struct  server_alive_msg
{
	int		server_type;   // login manage status info etc.
	unsigned int	last_alive_msg_time; // time of last alive message reveived
	int     is_alive;           //
	unsigned int  srv_ipaddr;   // ip address of server
	char	srv_c_ipaddr[24];   
	int		srv_port;           //server port
	int     start_time;         //time of server startup
	unsigned int  clients_num;  // client number of the server
	unsigned int  camera_num;   // camera number of the server
	int		work_thread_num;    // number of working threads of server
};


////////////////////////
struct  server_forward_msg
{
	unsigned int    dstination_id;          // perhaps is clientid or cameraid or device id etc.
	unsigned int    cmd_id;					// forward message id 
	int			    msg_body_len;   
	char			msg_body[0];
};


////////////////////////////////////////////////
//structures for talk purpose
struct  mgr_talk_msg
{
	uint32    camera_id;
	uint32    src_clientid;		// sender of message
	uint32    dst_clientid;     // dstination of message
	uint32    custom_id;       // company id of camera 
	uint32    reason;           //����ʱ����ָ��ԭ�� 0:normal  1: �ܾ� 2: ������ƥ�� 3: private talk
};

struct  mgr_talk_ack_msg
{
	uint32    camera_id;
	uint32    src_clientid;		// sender of message
	uint32    dst_clientid;     // dstination of message
	uint32    custom_id;       // company id of camera
	uint32    result;           //0: success   1: has talked to other
	uint32    audio_frm_type;    //audio frame type of support
};

struct  p2p_audio_data_msg
{
	uint32 src_clientid;	   //�������ݷ�
	uint32 dst_clientid;       //dstination of message
	uint32 block_id;
	char data[0]; //����
};

//////////////////////////////////////////////////////////////////////////
//by
//�ӷ�������ͨ��CLIENT_DATA_GET_COMPANY_EVENT�õ��ÿͻ�֧�ֵ��¼�����ؽṹ�����£�
struct get_company_event_list
{
	uint32 custom_id;
};

//����ʱCLIENT_DATA_GET_COMPANY_EVENT_ACK
struct  event_describtion
{
	uint32   event_id;
	char     event_name[32];
};
struct company_event_list_ret
{
	uint32 custom_id;
	uint16 event_num;   // event��Ŀ
	struct event_describtion event_list[0];
};

//////////////////////////////////////////////////////////////////////////
//by 20121211
//����ҵ��ѯ��
//CLIENT_DATA_GET_COMPANY_ACTIVED_DEVICE
//CLIENT_DATA_GET_COMPANY_ACTIVED_DEVICE_ACK
struct client_2_data_active_device
{
	uint32 	custom_id;
	uint32 	active_device;//0:none 1:actived some device
};

//CLIENT_DATA_CHANGE_CAMERA_NAME
//�ͻ��������ݷ��������͸�������
struct  client_2_data_change_camera_name
{
	uint32 	user_id;
	uint32 	camera_id;
	char	camera_name[32];
};

//CLIENT_MGR_SET_CAMERA_ALARM_NOTE_MSG
//CLIENT_MGR_GET_CAMERA_ALARM_NOTE_MSG
//CLIENT_MGR_GET_CAMERA_ALARM_NOTE_ACK_MSG
//MGR_GET_CAMERA_ALARM_NOTE_MSG
//MGR_GET_CAMERA_ALARM_NOTE_ACK_MSG

//struct client_mgr_set_camera_alarm_note_msg
//{
//	uint32	user_id;
//	uint32 	camera_id;
//	uint32 	note_switch;	//0:close 1:open
//	uint32	begin_time;		//��ʼʱ�䣬����
//	uint32	end_time;		//����ʱ�䣬����
//};



//CLIENT_MGR_SET_CAMERA_CRUISE_MODE_MSG
struct client_camera_cruise_mode_msg
{
	uint32	user_id;
	uint32 	camera_id;
	uint32 	cruise_mode;//0:horizonal cruise 1:vertical cruise
};

//CLIENT_DATA_SUMBIT_LOG_CONTENT
struct client_2_data_submit_log_content_msg
{
	uint32 		user_id;
	uint32 		log_time;//��־ʱ��
	char	 	log_type[32];//��־���� 1.��¼ 2.������
	char		log_content[64];//��־����
};
//CLIENT_DATA_GET_LOG_CONTENT_MSG
//by zbiao  ֧�ּ�ͥ���ֻ��ͻ��˻���û�������¼
/////////////////////////////////////////
struct client_2_data_get_log_content_msg
{
	uint32 		user_id;	
	char	 	log_type[32];//��־���� 1.��¼ 2.������
};
struct user_log_content
{
	char		username[32];
	char		log_content[64];	//��־����
	uint32 	log_time;	//��־����ʱ��
};


struct client_2_data_get_log_content_msg_ack
{
	char	 	log_type[32];	//��־���� 1.��¼ 2.������
	uint32	usercnt;
	user_log_content userLog[32];
};

////////////////////////////////////////////////////
struct timing_record_time_list
{	
	uint32	begin_time;		//��ʼʱ�䣬����
};

//CLIENT_MGR_SET_CAMERA_TIMING_RECORD_PARA_MSG
struct client_camera_timing_record_para
{
	uint32	user_id;
	uint32 	camera_id;
	uint32 	timing_record_switch;//0:close 1:open
	uint32 	record_length;//¼��ʱ������λΪ��
	uint32	time_count;//���ø���
	struct 	timing_record_time_list  time_list[0];//¼��ʼʱ��
};

//CLIENT_DATA_GET_HOME_FILE_LIST_MSG
struct client_2_data_get_home_file_list_msg
{
	uint32 	user_id;
	uint32 	camera_id;
	uint32  req_count;
	uint32  start_file_id;
	uint32 	query_s_date;	//��ѯ��ʼ����
	uint32  query_e_date;	//��ѯ��ֹ����
	uint32 	query_type;		//0:ȫ���ļ� 1.����ͼƬ 2.������Ƶ 3.��ʱͼƬ 4.��ʱ��Ƶ 5.����ͼƬ
};

struct home_file
{	
	char		file_name[32];
	uint32		file_size;
	uint32		file_time;
	uint32		file_id;	//�ļ���Ψһ��ʾ��
	char		file_url[200];	//�ļ�·��
};

//CLIENT_MGR_GET_CLOUD_HOME_FILE_LIST_ACK_MSG
struct client_2_data_get_home_file_list_ack_msg
{
	uint32 	query_type;		//0:ȫ���ļ� 1.����ͼƬ 2.������Ƶ 3.��ʱͼƬ 4.��ʱ��Ƶ 5.����ͼƬ
	uint32 	file_count;		//0:���ļ�
	struct 	home_file files[0];
};



//CLIENT_DATA_EDIT_HOME_FILE_MSG
struct client_2_data_edit_home_file
{
	uint32	user_id;
	uint32 	query_type;//1.����ͼƬ 2.������Ƶ 3.��ʱͼƬ 4.��ʱ��Ƶ 5.����ͼƬ
	uint32  file_id;
	char	old_file_name[32];
	char	new_file_name[32];
	uint32  edit_type;//0:change file name 1:delete file
};

//������Ϣ
//CLIENT_2_MGR_SNAPSHOT_MSG
struct  client_2_mgr_snapshot_msg
{
	uint32   camera_id;
	uint32   client_id;	//by 20121225 �������յĿͻ���
};
//MGR_2_CAMERA_SNAPSHOT_MSG
struct mgr_2_camera_snapshot_msg
{
	uint32   camera_id;
	uint32   client_id;	//by 20121225 �������յĿͻ���
};
//�豸�ϴ��ļ�ѯ����Ϣ
//CAMERA_2_HTTP_QUERY_FILE_UP_MSG
struct camera_2_http_query_file_up_msg
{
	uint32   camera_id;
	uint32   file_type;	//�ļ����� 1.����ͼƬ 2.������Ƶ 3.��ʱͼƬ 4.��ʱ��Ƶ 5.����ͼƬ
	uint32   file_size;  
};

//�豸�ϴ��ļ�ѯ��Ӧ����Ϣ
//HTTP_2_CAMERA_QUERY_FILE_UP_ACK_MSG
struct http_2_camera_query_file_up_ack_msg
{
	uint32   camera_id;
	uint32   file_type;	//�ļ����� 1.����ͼƬ 2.������Ƶ 3.��ʱͼƬ 4.��ʱ��Ƶ 5.����ͼƬ
	/*
	����ֵ��
	0.��Чȷ�� 
	1.�޴�Ȩ��
	2.�豸����
	3.�ռ�����
	*/
	uint32   ack_msg;	
};

//CAMERA_2_MGR_FILE_UP_ACK_MSG
//�豸�ϴ��ļ�������Ϣ
struct camera_2_mgr_file_up_ack_msg
{
	uint32   camera_id;
	uint32   client_id;	//by 20121225 �������յĿͻ���
	uint32   file_type;	//�ļ����� 1.����ͼƬ 2.������Ƶ 3.��ʱͼƬ 4.��ʱ��Ƶ 5.����ͼƬ
	uint32   file_id;	//�ļ�ID �豸�ϴ�http�ɹ�����Ҫ�����ļ���id֪ͨ���������
	uint32	 ack_msg;	//���������Ϣ��ע
	char	 file_url[200];	//�ļ�·��
};

//MGR_2_CLIENT_SNAPSHOT_ACK_MSG
struct mgr_2_client_file_up_ack_msg
{
	uint32   camera_id;
	uint32   client_id;	//by 20121225 �������յĿͻ���
	uint32   file_type;	//�ļ����� 1.����ͼƬ 2.������Ƶ 3.��ʱͼƬ 4.��ʱ��Ƶ 5.����ͼƬ
	uint32   file_id;	//�ļ�ID �豸�ϴ�http�ɹ�����Ҫ�����ļ���id֪ͨ���������
	uint32	 ack_msg;	//���������Ϣ��ע
	char	 file_url[200];	//�ļ�·��
};

//������Ϣ
//CAMERA_ALARM_MSG
struct camera_alarm_msg
{
	uint32 camera_id;
	uint32 alarm_type;	//��������
};

//��������
struct client_camera_common_order
{
	uint32  order_type;
	uint32	user_id;
	uint32 	camera_id;
};

//UPDATE_MOBILE_INVITE_INFO
struct update_2_mobile_invite
{
	uint32 device_id;
	uint32 custom_id;
	char   software_version[16];
	uint32 reserver1;
	uint32 reserver2;
};

//UPDATE_MOBILE_INVITE_ACK
struct mobile_2_update_invite_ack
{
	uint32 device_id;
	uint32 custom_id;
	uint32 status;       // 1 msg received; 2 agree to update ; 
	char   software_version[16];
	uint32 reserver1;
	uint32 reserver2;
};



//UPDATE_DEVICE_FTP_INFO
struct update_2_device_ftp_info
{
	uint32 device_id;
	uint32 custom_id;
	uint32 task_id;
	char   username[16];
	char   password[16];
	char   pathname[128];
	char   md5[32];
	uint32 reserver1;
	uint32 reserver2;
};

//UPDATE_DEVICE_FTP_INFO_ACK
struct device_2_update_ftp_ack
{
	uint32 device_id;
	uint32 custom_id;
	uint32 task_id;
	uint32 status;   // 1 msg received; 2 update packet downloaded; 4 update failed ; 8 update succeed
	uint32 reason;
	uint32 reserver1;
	uint32 reserver2;
};

struct user_2_mgr_disconn_device
{
	uint32 device_id;
	uint32 user_id;
};

//CLIENT_MGR_SET_VIDEO_PARAM=20217
struct client_mgr_set_video_param
{
	uint32 device_id;
	uint32 user_id;
	uint32 channel;
	uint32 video_type;
	uint32 reservers[2];
};

////////////////////////////////////////////////

#pragma pack()

#endif//__PROTO_H__

