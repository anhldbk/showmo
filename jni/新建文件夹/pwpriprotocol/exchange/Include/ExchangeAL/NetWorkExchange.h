#ifndef __EXCHANGE_AL_NETWORK_EXCHANGE_H__
#define __EXCHANGE_AL_NETWORK_EXCHANGE_H__

#include "../Types/Defs.h"
#include "CommExchange.h"
#include "Exchange.h"
#include "MediaExchange.h"
#include "../PAL/ExDec.h"
#include "../PAL/Net.h"

//��Ҫ���ڼ�
#if 0
enum NetWorkErrorNo
{
	ACCOUNT_NOT_LOGIN = ERROR_BEGIN_NETCOMMON + 1,
	ACCOUNT_PASSWORD_NOT_VALID = ERROR_BEGIN_NETCOMMON + 2,
	ACCOUNT_USER_NOT_VALID = ERROR_BEGIN_NETCOMMON + 4,
	ACCOUNT_USER_LOCKED = ERROR_BEGIN_NETCOMMON + 5,
	ACCOUNT_USER_IN_BLACKLIST = ERROR_BEGIN_NETCOMMON + 6,
	ACCOUNT_USER_HAS_USED = ERROR_BEGIN_NETCOMMON + 7,
};
#endif

//�ṹ�������ͳһ��Ϊ����ǰ׺�ĸ�ʽ

#define  NAME_PASSWORD_LEN  64
#define  DECODER_NAME_LEN	64
#define  EMAIL_ADDR_LEN  32
#define  N_MIN_TSECT 2
#define  N_ALARMSERVERKEY 5
#define  MAX_FILTERIP_NUM 64
#define  MAX_MAC_LEN 32

///< �������ṹ����
struct RemoteServerConfig
{
	char ServerName[NAME_PASSWORD_LEN];	///< ������
	IPAddress ip;						///< IP��ַ
	int Port;							///< �˿ں�
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����
	bool Anonymity;							///< �Ƿ�������¼
};

/// ¼�����ز���
enum RecordDownloadPolicy
{
	DOWNLOADING_AT_NORMALSPEED = 0,	//��ͨ����
	DOWNLOADING_AT_HIGHSPEED,		//��������
};

/// �������
enum TransferPolicy
{
	TRANSFER_POLICY_AUTO,		///< ����Ӧ
	TRANSFER_POLICY_QUALITY,	///< ��������
	TRANSFER_POLICY_FLUENCY,	///< ��������
	TRANSFER_POLICY_TRANSMISSION,///<��������
	TRANSFER_POLICY_NR,
};

///< ��ͨ��������
struct NetCommonConfig
{
	char HostName[NAME_PASSWORD_LEN];	///< ������
	IPAddress HostIP;		///< ����IP
	IPAddress Submask;		///< ��������
	IPAddress Gateway;		///< ����IP
	int HttpPort;			///< HTTP����˿�
	int TCPPort;			///< TCP�����˿�
	int SSLPort;			///< SSL�����˿�
	int UDPPort;			///< UDP�����˿�
	int MaxConn;			///< ���������
	int MonMode;			///< ����Э�� {"TCP","UDP","MCAST",��}
	int MaxBps;				///< �޶�����ֵ
	int TransferPlan;		///< ������� ��TransferPolicy
	bool bUseHSDownLoad;	///< �Ƿ����ø���¼�����ز���
	char sMac[MAX_MAC_LEN]; ///< MAC��ַ
};

struct NetDevList
{
	std::vector<NetCommonConfig> vNetDevList;
};

///< IPȨ������
struct NetIPFilterConfig
{
	bool Enable;		///< �Ƿ���
	IPAddress BannedList[MAX_FILTERIP_NUM];		///< �������б�
	IPAddress TrustList[MAX_FILTERIP_NUM];		///< �������б�
};

///< �鲥����
struct NetMultiCastConfig
{
	bool Enable;		///< �Ƿ���
	RemoteServerConfig Server;		///< �鲥������
};

///< pppoe����
struct NetPPPoEConfig
{
	bool Enable;		///< �Ƿ���
	RemoteServerConfig Server;		///< PPPOE������
	IPAddress addr;		///< ���ź��õ�IP��ַ
};

///< DDNS����
struct NetDDNSConfig
{
	bool Enable;	///< �Ƿ���
	bool Online;		///< �Ƿ�����
	char DDNSKey[NAME_PASSWORD_LEN];	///< DDNS��������
	char HostName[NAME_PASSWORD_LEN];	///< ������
	RemoteServerConfig Server;		///< DDNS������
};

enum TransferProtocol
{
	TRANSFER_PROTOCOL_TCP,
	TRANSFER_PROTOCOL_UDP,
	TRANSFER_PROTOCOL_NR,
};


enum TransferProtocol_V2
{
	TRANSFER_PROTOCOL_NETIP,
	TRANSFER_PROTOCOL_ONVIF,
	TRANSFER_PROTOCOL_NAT,
	TRANSFER_PROTOCOL_DAHUA,
	TRANSFER_PROTOCOL_NR_V2,
};

///< ��������ַ����
struct NetDecorderConfig
{
	bool Enable;						///< �Ƿ���
	char UserName[NAME_PASSWORD_LEN];	///< DDNS��������, Ŀǰ��:
	char PassWord[NAME_PASSWORD_LEN];	///< ������
	char Address[NAME_PASSWORD_LEN];
	int Protocol;
	int Port;							///< ���������Ӷ˿�
	int Channel;						///< ����������ͨ����
	int Interval;                       ///< ��Ѳ�ļ��ʱ��(s),0:��ʾ����
};

/// ��������ַ����
struct NetDecorderConfigAll
{
	NetDecorderConfig vNetDecorderConfig[N_DECORDR_CH];
};


//��������ַ����v2
struct NetDecorderConfigAll_V2
{
	std::vector<NetDecorderConfig> vNetDecorderVector[N_DECORDR_CH];
};

enum DevType
{
	DEV_TYPE_IPC,
	DEV_TYPE_DVR,
	DEV_TYPE_HVR,
	DEV_TYPE_NR
};

///< ��������ַ����
struct NetDecorderConfigV3
{
	bool Enable;						///< �Ƿ���
	char UserName[NAME_PASSWORD_LEN];	///< DDNS��������
	char PassWord[NAME_PASSWORD_LEN];	///< ������
	char Address[NAME_PASSWORD_LEN];
	int Protocol;
	int Port;							///< ���������Ӷ˿�
	int Channel;						///< ����������ͨ����
	int Interval;                       ///< ��Ѳ�ļ��ʱ��(s),0:��ʾ����
	char ConfName[DECODER_NAME_LEN];	///<��������
	int DevType;						///<�豸����
	int StreamType;						///<���ӵ���������CaptureChannelTypes
};

/*��������������*/
enum DecorderConnType
{
	CONN_SINGLE = 0, 	/*������*/
	CONN_MULTI = 1,		/*��������Ѳ*/
	CONN_TYPE_NR,
};

/*����ͨ��������*/
struct NetDigitChnConfig
{
	bool Enable;		/*����ͨ���Ƿ���*/
	int ConnType;		/*�������ͣ�ȡDecoderConnectType��ֵ*/
	int TourIntv;		/*������ʱ��Ѳ���*/
	uint SingleConnId;	/*������ʱ����������ID, ��1��ʼ��0��ʾ��Ч*/
	bool EnCheckTime;	/*������ʱ*/
	std::vector<NetDecorderConfigV3> vNetDecorderConf; /*�����豸ͨ�����ñ�*/
};

/*��������ͨ��������*/
struct NetDecorderConfigAll_V3
{
	NetDigitChnConfig DigitChnConf[N_DECORDR_CH];
};

/*ͨ��ģʽ����*/
struct NetDecorderChnModeConfig
{
	CAPTURE_TOTAL_HVRCAP 	HVRTotalCap;
	int HVRCurCapMode;
};

/*����ͨ��״̬*/
struct NetDecorderChnStatus
{
	char ChnName[CHANNEL_NAME_MAX_LEN];
	char pMaxResName[50];
	char pCurResName[50];
	char pStatus[50];
};


/*��������ͨ��״̬*/
struct NetDecorderChnStatusAll
{
	NetDecorderChnStatus ChnStatusAll[MAX_HVR_CHNCAP];
};

//Pos�豸����
enum PosDevType
{
	POS_TYPE_MANY_LINES, //�������ܽ���Ű���Ʒ��Ϣһ���͹���
	POS_TYPE_ONE_LINE,   //ÿͳ��һ����Ʒ�ͰѸ���Ʒ����Ϣ���͹���
	POS_NR
};

//���ֱ����ʽ
enum WordEncode
{
	WORD_ENCODE_GB2312,  //���ֱ���GB2312
	WORD_ENCODE_UNICODE, //����� Unicode
	WORD_ENCODE_UTF8,    //UTF-8
};

// pos�������
struct NetPosConfig
{
	bool Enable;		/*pos��ͨ��ʹ��*/
	int Devtype;		//pos������
	int Protocol;		//ͨ��Э��
	int Port;			//Э��˿ں�
	bool SnapEnable;    //ץ��ʹ��
	int  StartLine;     //���յ�����Ϣ�Ӷ����п�ʼ��ʾ
	int  WordEncodeType;//���ֱ����ʽ����ö��ֵ WordEncodeType ��ʾ
	int res;			//����
};
//����pos���������
struct NetPosConfigAll
{
	NetPosConfig PosConfig[N_SYS_CH];
};

///< ������������
struct NetAlarmCenterConfig
{
	bool bEnable;		///< �Ƿ���
	char sAlarmServerKey[NAME_PASSWORD_LEN];	///< ��������Э����������,
	///< �������ķ�����
	RemoteServerConfig Server;
	bool bAlarm;
	bool bLog;
};

struct NetAlarmServerConfigAll
{
	NetAlarmCenterConfig vAlarmServerConfigAll[MAX_ALARMSERVER_TYPE];
};

///< ftp����
struct NetFtpServerConfig{
	bool bEnable;        ///< ������ʹ��
	RemoteServerConfig Server;	///< FTP������
	char cRemoteDir[MAX_PATH_LENGTH];	///< Զ��Ŀ¼
	int iMaxFileLen;	///< �ļ���󳤶�
};

///< NTP����

struct NetNTPConfig
{
	///< �Ƿ���
	bool Enable;
	///< PPPOE������
	RemoteServerConfig Server;
	///< ��������
	int UpdatePeriod;
	///< ʱ��
	int TimeZone;
};

#define  MAX_EMAIL_TITLE_LEN 64
#define  MAX_EMAIL_RECIEVERS  5
///< EMAIL����
struct NetEmailConfig
{
	///< �Ƿ���
	bool Enable;
	///< smtp ��������ַʹ���ַ�����ʽ���
	///< ������ip,Ҳ����������
	RemoteServerConfig Server;
	bool bUseSSL;
	///< ���͵�ַ
	char SendAddr[EMAIL_ADDR_LEN];
	///< �����˵�ַ
	char Recievers[MAX_EMAIL_RECIEVERS][EMAIL_ADDR_LEN];
	///< �ʼ�����
	char Title[MAX_EMAIL_TITLE_LEN];
	///< email��Чʱ��
	TimeSection Schedule[N_MIN_TSECT];
};

//ץ�����ýṹ
struct NetSnifferConfig
{
	IPAddress		SrcIP;		//ץ��Դ��ַ
	int				SrcPort;	//ץ��Դ�˿�
	IPAddress		DestIP;		//ץ��Ŀ���ַ
	int				DestPort;	//ץ��Ŀ��˿�
};

#define MAX_ETH_NUM 4

//DHCP
struct NetDHCPConfig
{
	bool bEnable;
	char ifName[32];
};

/// ����������DHCP����
struct NetDHCPConfigAll
{
	NetDHCPConfig vNetDHCPConfig[MAX_ETH_NUM];
};

///< NTP����
struct NetDNSConfig
{
	IPAddress		PrimaryDNS;
	IPAddress		SecondaryDNS;
};


struct DDNSTypeConfigAll
{
	NetDDNSConfig vDDNSTypeAll[MAX_DDNS_TYPE];
};

///< ARSP(����ע�������)���ð�������̩DNS
struct NetARSPConfig
{
	bool bEnable;	///< �Ƿ���
	char sARSPKey[NAME_PASSWORD_LEN];	///< DNS��������
	int iInterval;	///< ������ʱ��
	char sURL[NAME_PASSWORD_LEN];    ///< ��������
	RemoteServerConfig Server;		///< DDNS������
	int nHttpPort;                  ///< ������HTTP�˿�
};

struct NetARSPConfigAll
{
	NetARSPConfig vNetARSPConfigAll[MAX_ARSP_TYPE];
};

enum Net3GType
{
	WIRELESS_AUTOSEL=0,	    ///< �Զ�ѡ��
	WIRELESS_TD_SCDMA=1,	///< TD-SCDMA����
	WIRELESS_WCDMA=2,		///< WCDMA����
	WIRELESS_CDMA_1X=3,     ///< CDMA 1.x����
	WIRELESS_EDGE=4,		///< GPRS����
	WIRELESS_EVDO=5,		///< EVDO����
	WIRELESS_MAX
};

struct Net3GConfig
{
	bool bEnable;			  ///< ����ģ��ʹ�ܱ�־
	int iNetType;			  ///< ������������
	std::string strAPN;		  ///< ���������
	std::string strDialNum;   ///< ���ź���
	std::string strUserName;  ///< �����û���
	std::string strPWD;  	  ///< ��������
	IPAddress addr;			  ///< ���ź��õ�IP��ַ
};

///< �ֻ�������ð�������̩DNS
struct NetMoblieConfig
{
	bool bEnable;	///< �Ƿ���
	RemoteServerConfig Server;		///< ������
};

struct NetUPNPConfig
{
	bool bEnable;			  ///< ʹ�ܱ�־
	bool bState;              ///< ״̬
	int iHTTPPort;			  ///< HTTP�˿�
	int iMediaPort;			  ///< ý��˿�
	int iMobliePort;		  ///< �ֻ���ض˿�
};

//WIFI
struct NetWifiConfig
{
	bool bEnable;
	std::string strSSID;            //SSID Number
	int nChannel;                   //channel
	std::string strNetType;         //Infra, Adhoc
	std::string strEncrypType;      //NONE, WEP, TKIP, AES
	std::string strAuth;            //OPEN, SHARED, WEPAUTO, WPAPSK, WPA2PSK, WPANONE, WPA, WPA2
	int  nKeyType;                  //0:Hex 1:ASCII
	std::string strKeys;
	IPAddress HostIP;		///< host ip
	IPAddress Submask;		///< netmask
	IPAddress Gateway;		///< gateway
};

struct NetWifiStatus
{
	int nWifiStatus;
};
struct NetAPSwapWifi
{
	int nAPSwapWifi;
};
// ����������Ϣ����
enum AlarmCenterMsgType
{
	ALARMCENTER_ALARM,
	ALARMCENTER_LOG,
};

// ����������Ϣ����
enum AlarmCenterStatus
{
	AC_START,
	AC_STOP,
};

// �澯������Ϣ����
struct NetAlarmCenterMsg
{
	IPAddress HostIP;		///< �豸IP
	int nChannel;           ///< ͨ��
	int nType;              ///< ���� ��AlarmCenterMsgType
	int nStatus;            ///< ״̬ ��AlarmCenterStatus
	SystemTime Time;        ///< ����ʱ��
	std::string strEvent;    ///< �¼�
	std::string strSerialID; ///< �豸���к�
	std::string strDescrip;  ///< ����
};

// RTSP
struct NetRtspConfig
{
	bool bServer;
	bool bClient;
	RemoteServerConfig Server;		///< ������ģʽ
	RemoteServerConfig Client;		///< �ͻ���ģʽ
};

struct DASSerInfo
{
	bool enable;
 	char serAddr[NAME_PASSWORD_LEN];
	int  port;
	char userName[NAME_PASSWORD_LEN];
	char passwd[NAME_PASSWORD_LEN];
	char devID[NAME_PASSWORD_LEN];
};

struct NetMediaStreamConfig
{
	bool enable;
	char serAddr[NAME_PASSWORD_LEN];
	int  port;
	char devID[NAME_PASSWORD_LEN];
};


//�ֻ���������
struct NetShortMsgCfg
{
	bool bEnable;       //�����ֻ����ŵĹ����Ƿ�����
	char pDesPhoneNum[MAX_RECIVE_MSG_PHONE_COUNT][16]; //���ն��ŵ��ֻ��ţ���֧��3���ֻ���
	int  sendTimes;     //��Ҫ��ÿ���ֻ����Ͷ��ٴζ���
};

//�ֻ���������
struct NetMultimediaMsgCfg
{
	bool bEnable;				// �����ֻ����ŵĹ����Ƿ�����
	char pDesPhoneNum[MAX_RECIVE_MSG_PHONE_COUNT][16]; //���ղ��ŵ��ֻ��ţ���֧��3���ֻ���
	char pGateWayDomain[40];	// ���ص�ַ��������IP
	int  gateWayPort;			// ���ض˿�
	char pMmscDomain[40];		// ���ŷ�������ַ��IP������
	int  mmscPort;				// ���ŷ������˿ں�
};


//�������ȼ�
struct NetOrderConfig
{
	bool         bEnable;          //�Ƿ������������ȼ�
	int          netCount;         //����������Ŀ
	NetLinkOrder pNetOrder[NM_NR]; //�������ȼ�
	NetLinkOrder pReserve[7-NM_NR];//���µ���������Ԥ��
};

//����ƽ̨��Ϣ����
typedef struct LocalSdkNetPlatformConfig
{
	int Enable;
	int nISP;
	char sServerName[32];
	char ID[32];
	char sUserName[32];
	char sPassword[32];
	IPAddress HostIP;		///< host ip
	int port;
}LOCALSDK_NET_PLATFORM_CONFIG;

//���۽Ӿ�����ϵͳ
struct	GodEyeConfig
{
	bool bEnable;
	char MainServerName[NAME_PASSWORD_LEN]; //������
	int MainPort;	//���˿�
	char ExServerName[NAME_PASSWORD_LEN]; //��������
	int ExPort;	//���ö˿�
};

enum  DigManagerShowStatus
{
	SHOW_NONE,
	SHOW_ALL,
};


//����ͨ����ʾ״̬
struct DigitalManagerShow
{
	int  nDigitalManagerShowSta;
};

//NATʹ�ܣ�MTUֵ
struct NatConfig
{
	bool bEnable;
	int nMTU;
};

struct VPNConfig
{
	bool Enable;		///< �Ƿ���
	IPAddress ServiceIp;					///< ������IP��ַ
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����
	IPAddress addr;		///< ���ź��õ�IP��ַ
};

void exchangeServer(CKeyExchange& configExchange, CConfigTable& table, RemoteServerConfig& server);

#endif

