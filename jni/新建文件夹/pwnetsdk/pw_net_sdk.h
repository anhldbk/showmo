
#ifndef PW_NET_SDK_H
#define PW_NET_SDK_H

#include "proto.h"
using namespace std;

#ifdef NETMODULE_EXPORTS
#ifdef WIN32
	#define PWNET_API  extern "C" __declspec(dllexport)
#else
	#define PWNET_API __attribute__((__stdcall))
#endif
#else
#ifdef WIN32
 #define PWNET_API  extern "C" __declspec(dllimport)   //VC ��
#else
 #define PWNET_API __attribute__((__stdcall))
#endif
#endif

#ifndef CALL_METHOD
#ifdef WIN32
	#define CALL_METHOD	__stdcall  //__cdecl
#else
    #define CALL_METHOD	__stdcall  
#endif
#endif

#define  MAX_FILE_NUM 16
#define  FRAME_MAX    32
#define  AUDIO_MAX    1024
#define  ONE_BLK_SIZE (1024-sizeof(msg_header)-sizeof(msg_data)) 
#define  ALARM_BLK_SIZE (1024-sizeof(msg_header)-sizeof(alarm_msg_data)) 
#define  AUDIO_BLK_SIZE  320 

enum MsgId
{
	UPDATE_DOWNPOS = 1000,
	UPDATE_FAILED = 1001,
	UPDATE_SUCCESS = 1002,
	DOWNLOAD_PIC_POS = 1003,		//����ͼƬ����
	DOWNLOAD_PIC_FAILED = 1004,		//����ͼƬʧ��
	DOWNLOAD_PIC_SUCCESS = 1005,    //����ͼƬ�ɹ�
	PLAY_STOP = 1006,               //������ֹͣ 
};

struct SDK_CAMERA_UPDATE
{
	uint32 cameraid;				//camera id
	uint32 cmd;				        //cmd MsgId
	uint32 downpos;                 //�������ؽ��� 
};

struct SDK_CAMERA_STATE
{
	uint32 customid;				//camera�����ͻ�id
	uint32 cameraid;				//camera id
};


struct SDK_TIME
{
	uint32 nYear;		//��
	uint32 nMonth;		//��
	uint32 nDay;		//��
	uint32 nHour;		//ʱ
	uint32 nMinute;	//��
	uint32 nSecond;	//��
};

// ¼���ļ����ؽṹ��
struct SDK_REMOTE_FILE
{
	uint32  size;						// �ļ���С
	char    sFileName[108];				// �ļ���
	uint32  nFileType;				    // �ļ����� ö�٣�Remote_File_Type  
	SDK_TIME startTime;	                // �ļ���ʼʱ��
	SDK_TIME endTime;	                // �ļ�����ʱ��
};

// ��ѯ¼������
struct SDK_SEARCH
{
	uint32		 nFileType;			// �ļ����� ö�٣�Remote_File_Type
	SDK_TIME     startTime;			// ��ʼʱ��
	SDK_TIME     endTime;			// ����ʱ��
};


struct SDK_REMOTE_SEARCH
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	SDK_SEARCH  findinfo; 
};

struct SDK_REMOTE_FILELIST
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	uint32 file_count;
	SDK_REMOTE_FILE fileinfo[MAX_FILE_NUM];
};


struct REMOTE_CONTROL
{
	uint32 Action;	        // �طŶ���
	uint32 TransMode;	    // ����ģʽ
	char   sFileName[108];
	SDK_TIME stStartTime;	// ��ʼʱ��
	SDK_TIME stEndTime;		// ����ʱ��
	uint32   PlayMode;	    // 0
	uint32   Value;	        // 
};

struct SDK_REMOTE_CONTROL
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	REMOTE_CONTROL control;
};

struct REMOTE_POS_ASK
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	char   sFileName[108];
};

struct REMOTE_POS_ACK
{
	uint32 remote_pos;
};

/// ����ģʽ
enum Remote_TansMode
{
	SDK_TRANSMODE_TCP,		// TCP����
	SDK_TRANSMODE_UDP,		// UDP����
	SDK_TRANSMODE_MCAST,	// �ಥ
	SDK_TRANSMODE_RTP,		// RTP����
	SDK_TRANSMODE_NR
};

enum  Remote_PlayBack_Action
{
	SDK_PLAY_BACK_PAUSE,		 // ��ͣ�ط� 
	SDK_PLAY_BACK_CONTINUE,	 	 // �����ط�  
	SDK_PLAY_BACK_FAST,	         // ���ٻط� 
	SDK_PLAY_BACK_SLOW,	         // ���ٻط� 
	SDK_PLAY_BACK_SEEK_PERCENT,  // �طŶ�λ�ٷֱ� 
};

enum Remote_File_Type
{
	SDK_RECORD_ALL = 0,
	SDK_RECORD_ALARM = 1,	// �ⲿ����¼��
	SDK_RECORD_DETECT,	    // ��Ƶ���¼��
	SDK_RECORD_REGULAR,	    // ��ͨ¼��
	SDK_RECORD_MANUAL,	    // �ֶ�¼��
	SDK_PIC_ALL = 10,
	SDK_PIC_ALARM,		    // �ⲿ����ץ��
	SDK_PIC_DETECT,		    // ��Ƶ���ץ��
	SDK_PIC_REGULAR,         // ��ͨץ��
	SDK_PIC_MANUAL,          // �ֶ�ץ��
	SDK_TYPE_NUM,
};

struct SDK_APPLY_ACCOUNT
{
	uint16 user_type;
};

struct SDK_APPLY_ACCOUNTINFO
{
	char user_name[64];
	uint16 user_type;
};

struct SDK_REMOTE_MESSAGE   // Զ�̻طŽ���  HIST_VIDEO_CAMERA_ACK_MSG
{
	uint32 camera_id;
	uint32 client_id;
	uint32 custom_id;
	uint32 device_id;
	uint32 id;
	uint32 option;
	uint32 value1;
	uint32 value2;
};

typedef struct tcframe_inner_blk_tags
{
	int  size;
	int  ask_count;  
}tcframe_inner_blk;

typedef struct tcframe_blk_array_tags
{
	unsigned int    frame_type;
	unsigned int    blk_received;  
	unsigned int    blk_sum;
	unsigned int    frame_size;
	unsigned int    frm_seq;
	unsigned int    frm_blk_seq;
	bool            blk_used;  
	bool            blk_all;
	bool            blk_push; 
	bool            blk_state[512];
	tcframe_inner_blk blks[512];  	
	char            *data;  
}tcframe_blk_array;

typedef struct tcaudio_inner_array_tags
{
	unsigned int    frm_size; 	
	char            data[160];  
}audio_inner_blk;

typedef struct tcaudioe_blk_array_tags
{
	unsigned int    frm_seq;
	bool            blk_used;
	unsigned int    frm_blk_seq; 
	bool            blkstate[15];  
	audio_inner_blk blkdata[15];
}audio_blk;


struct SDK_VOLUME_VALUE
{
	uint32 options;  //  ����ѡ��;
	uint32 values;	 //  &options = 1 ��  0 ��	
	uint32 volume;   //  0-100 ����
	uint32 control;  //  ����
}; 

struct SDK_WIFI_VALUE
{
	unsigned int reserver1;
	unsigned int reserver2;
	unsigned int wifi_db;
	unsigned int local_ip;
	char   mac[18];
	char   version[16];
	char   currentssid[16];
};

enum NetWork
{
	Public_NET = 0,
	Local_NET ,
};
                                                                  
/***************************************************************************************************/



// ʵʱ�������ݻص�����ԭ��
typedef int   (*RealDataCallBack) (char *pBuffer,long lStreamType,long lFrameNum,long lbufsize,long dwUser); // lStreamType 0 iframe 1 pframe 4 jpeg

typedef void  (*errordatacallback) (char *pBuffer);

typedef void  (*msgdatacallback)(char *pBuffer,long lmsgid,long lexternid,long lbufsize,long dwUser);

// init
bool	PW_NET_Init();

// get last error
bool	PW_NET_GetLastError(unsigned long *dwError);

// get VerifyCode
bool	PW_NET_GetVerifyCode(send_verifycode_req* lpcode);

// check verify code
long    PW_NET_CheckVerifyCode(char *strUserName,char *strVerifyCode);// 0:��֤����ȷ 1����֤�벻����  2����֤�벻����  -1��ʧ��

// get app version
bool	PW_NET_GetAppVersion(int nDeviceType,query_app_version_ret *lpVersion); //0 ipc365; 1 iup365

// add terminal information
bool	PW_NET_AddTerminal(terminal_device_add_req *lpTerminal);

// reset password by old password
bool	PW_NET_ResetPassword(reset_password_req *lpByOldPass);

// reset password by verifycode
bool	PW_NET_ResetPasswordEx(reset_password_byverify_req *lpByVerify);

// ap get device online state
long	PW_NET_GetDeviceid(char *strUuid); // error <= 0

// change device name
bool    PW_NET_ModifyDevName(int nDeviceId,char *strName);

// device bilnd or not 
long	PW_NET_BindState(char *strUuid,char *strUser); // 0δ���û���1�ѱ����û��󶨣�2�������û���  -1 error

// add device
bool	PW_NET_AddDevice(client_device_add_req *lpAddDevice,client_device_add_ret *lpDevice);

// repeat add device
bool	PW_NET_AddDeviceEx(client_device_add_req *lpAddDevice,client_device_add_ret *lpDevice);

// delete device
bool	PW_NET_DeleteDevice(char *strUuid);

// account 
long	PW_NET_VerityAccount(char *strUser);  // 0 not exist  1 exist  -1 failure

// apply test account
bool	PW_NET_ApplyTestAccount(int nDeviceType,SDK_APPLY_ACCOUNTINFO *lpAccount);// 0 ipc365 1 xiaomo

// delete apply test account
bool	PW_NET_DeleteApplyAccount(SDK_APPLY_ACCOUNTINFO *lpAccount);

// sign up server
bool	PW_NET_SignUp(client_register_2_login *lpRegister); 

// online state
bool	PW_NET_OnLineState(int nCamera_id); // 0 error 1 success

// manager server
bool	PW_NET_Mgr_SignIn();

// disconnect manager server 
bool	PW_NET_Mgr_DisConnect(int nCamera_id);


// login loginserver
bool	PW_NET_Login(client_2_login_req *lpLogin);

// logout device
bool	PW_NET_Logout();

// clean 
bool    PW_NET_Cleanup();

// video   realplay
bool	PW_NET_StartRealPlay(int nCamera_id ,int *netType);

// set stream  type
bool	PW_NET_SetStreamType(int nCamera_id,int nSteramType);// 0 main 1 sub  2jpeg

// set video data callback 
bool	PW_NET_SetRealDataCallBack(RealDataCallBack cbRealData,long dwUser);

// set msg data callback
bool	PW_NET_SetMsgDataCallBack(msgdatacallback cbMsgData,long dwUser);

// start receive alarm
bool	PW_NET_SetAlarmState(int nCamera_id,int nalarmtype,bool state);

// get alarm state
long	PW_NET_GetAlarmState(int nCamera_id,int nalarmtype); // 0 ��  1�� -1 ʧ��

// get alarm pic
long	PW_NET_GetAlarmPic(int nCamera_id,int nalarmtype,int nalarmcode,int nccid,int nstarttime,int nendtime); // -1 failure  0 no pic  1 succcess  

// release buf
void	PW_NET_ReleaseBuf(char *strBuf);

// stop realplay
bool	PW_NET_StopRealPlay(int nCamera_id);

// sound
bool	PW_NET_Audio(int nCamera_id,bool state);

// get device list
bool	PW_NET_GetDeviceList(int nDeviceType,int* nDeviceNum,char *lpDeviceList);// 0:ipc365 1:xiaomo   client_device_query_ret *lpDeviceList);

// print log
bool	PW_NET_Log(bool bPrint);

// get talk state
long	PW_NET_GetTalkState(int nCamera_id); // 0 close 1 open -1 failed

// talk ctrl
bool	PW_NET_TalkCtrl(int nCamera_id,bool bstate);//state: 1 start 0 close      

// send talk data
bool	PW_NET_SendTalkData(int nCamera_id,char *strTalk ,long lTalkSize);

// dubug test
bool	PW_NET_SetDebugCallBack(errordatacallback func);

// upgrade
bool	PW_NET_Upgrade(int nCamera_id ,char *strVersion); 

// light
bool	PW_NET_BrightCtrl(int nCamera_id,int nBrightness,int nCtrl); // 0:close 1: open 2:set

// get light
bool	PW_NET_Brightness(int nCamera_id,int *nBrightness);

// get volume
bool    PW_NET_GetVolume(int nCamerai_d,SDK_VOLUME_VALUE *strOutputVolume);

// set volume
bool    PW_NET_SetVolume(int nCamerai_d,SDK_VOLUME_VALUE *strInputVolume);

// get wifi
bool    PW_NET_GetWifiValue(int nCamerai_d,SDK_WIFI_VALUE *strOutputWifi);

/************************************************************************/                                                                     
/************************************************************************/

// remote file
bool	PW_NET_SearchRemoteFile(int nCamera_id,SDK_SEARCH* lpFindInfo, char *lpFileData, int *findcount);

// remote play
bool	PW_NET_PlayBack(int nCamera_id,SDK_REMOTE_FILE *lpPlayBackFile, RealDataCallBack fDownLoadDataCallBack, long dwDataUser);

// remote play control
bool	PW_NET_PlayBackControl(int nCamera_id,int ctrl,int ctrlvalue);

// stop remote play
bool	PW_NET_StopPlayBack(int nCamera_id);


#endif
