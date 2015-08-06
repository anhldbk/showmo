#ifndef __EXCHANGE_AL_ABILITY_SET_H__
#define __EXCHANGE_AL_ABILITY_SET_H__

#include "../Types/Types.h"
#include "CommExchange.h"
#include "MediaExchange.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////
/// ϵͳ������
/// ���빦��
enum EncodeFunctionTypes
{
	ENCODE_FUNCTION_TYPE_DOUBLE_STREAM,		///< ˫��������
	ENCODE_FUNCTION_TYPE_COMBINE_STREAM,	///< ��ϱ���
	ENCODE_FUNCTION_TYPE_SNAP_STREAM,		///< ץͼ����
	ENCODE_FUNCTION_TYPE_WATER_MARK,		///< ˮӡ����
	ENCODE_FUNCTION_TYPE_NR,
};

/// ��������
enum AlarmFucntionTypes
{
	ALARM_FUNCTION_TYPE_MOTION_DETECT,	///< ��̬���
	ALARM_FUNCTION_TYPE_BLIND_DETECT,	///< �����ڵ�
	ALARM_FUNCTION_TYPE_LOSS_DETECT,	///< ������ʧ
	ALARM_FUNCTION_TYPE_LOCAL_ALARM,	///< ���ر���
	ALARM_FUNCTION_TYPE_NET_ALARM,		///< ���籨��
	ALARM_FUNCTION_TYPE_IP_CONFLICT,	///< IP��ַ��ͻ
	ALARM_FUNCTION_TYPE_NET_ABORT,		///< �����쳣
	ALARM_FUNCTION_TYPE_STORAGE_NOTEXIST,	///< �洢�豸������
	ALARM_FUNCTION_TYPE_STORAGE_LOWSPACE,	///< �洢�豸��������
	ALARM_FUNCTION_TYPE_STORAGE_FAILURE,	///< �洢�豸����ʧ��
	ALARM_FUNCTION_TYPE_VIEDO_ANALYZE,      ///< ��Ƶ����
	ALARM_FUNCTION_TYPE_NR
};

/// ���������
enum NetServerTypes
{
	NET_SERVER_TYPES_IPFILTER,		///< �׺�����
	NET_SERVER_TYPES_DHCP,			///< DHCP����
	NET_SERVER_TYPES_DDNS,			///< DDNS����
	NET_SERVER_TYPES_EMAIL,			///< Email����
	NET_SERVER_TYPES_MULTICAST,		///< �ಥ����
	NET_SERVER_TYPES_NTP,			///< NTP����
	NET_SERVER_TYPES_PPPOE,
	NET_SERVER_TYPES_DNS,
	NET_SERVER_TYPES_ARSP,			///< ����ע�����
	NET_SERVER_TYPES_3G,            ///< 3G���Ź���
	NET_SERVER_TYPES_MOBILE,			///< �ֻ����
	NET_SERVER_TYPES_UPNP,			///< UPNP
	NET_SERVER_TYPES_FTP,			///< FTP
	NET_SERVER_TYPES_WIFI,			///< WIFI
	NET_SERVER_TYPES_ALARM_CENTER,  ///< �澯����
	NET_SERVER_TYPES_NETPLAT_MEGA,  ///< ���Ż�ͨ
	NET_SERVER_TYPES_NETPLAT_XINWANG,  ///< ����
	NET_SERVER_TYPES_NETPLAT_SHISOU,  ///< ����
	NET_SERVER_TYPES_NETPLAT_VVEYE,  ///< ������
	NET_SERVER_TYPES_RTSP,           ///< RTSP
	NET_SERVER_TYPES_SHORT_MSG,      ///< ���ͱ�������
	NET_SERVER_TYPES_MULTIMEDIA_MSG, ///< ���ʹ���ͼ�Ĳ���
	NET_SERVER_TYPES_DAS,			///<DAS
	NET_SERVER_TYPES_LOCALSDK_PLATFORM,///<����ƽ̨��Ϣ����
	NET_SERVER_TYPES_GOD_EYE,///<���۽Ӿ�����ϵͳ
	NET_SERVER_TYPES_NAT,		///NAT��͸��MTU����
	NET_SERVER_TYPES_VPN,		///VPN����
	NET_SERVER_TYPES_MEDIASTREAM,		//��ý������
	NET_SERVER_TYPES_NR,
};

/// Ԥ������
enum PreviewTypes
{
	PREVIEW_TYPES_TOUR,		///< ��Ѳ
	PREVIEW_TYPES_TALK,		///< GUI��������
	PREVIEW_TYPES_NR
};

///��������
enum CommTypes
{
	COMM_TYPES_RS485,			///<485����
	COMM_TYPES_RS232,			///<232����
	COMM_TYPES_NR
};

///���뷨����
enum InputMethod
{
	NO_SUPPORT_CHINESE,		//��֧����������
	NO_SUPPORT_NR
};

///��ǩ��ʾ
enum TipShow
{
	NO_BEEP_TIP_SHOW,
	NO_FTP_TIP_SHOW,
	NO_EMAIL_TIP_SHOW,
	NO_TIP_SHOW_NR
};

///���ع���
enum MobileDVR
{
	MOBILEDVR_STATUS_EXCHANGE,
	MOBILEDVR_DELAY_SET,
	MOBILEDVR_CARPLATE_SET,
	MOBILEDVR_GPS_TIMING,
	MOBILEDVR_NR
};

///��������
enum OtherFunction
{
	OTHER_DOWNLOADPAUSE,		//¼��������ͣ����
	OTHER_USB_SUPPORT_RECORD,	//USB֧��¼����
	OTHER_SD_SUPPORT_RECORD,	//SD֧��¼����
	OTHER_ONVIF_CLIENT_SUPPORT,	//�Ƿ�֧��ONVIF�ͻ���
	OTHER_NR
};

/// ϵͳ����
struct SystemFunction
{
	bool vEncodeFunction[ENCODE_FUNCTION_TYPE_NR];	///< ���빦��EncodeFunctionTypes
	bool vAlarmFunction[ALARM_FUNCTION_TYPE_NR];	///< ��������AlarmFucntionTypes
	bool vNetServerFunction[NET_SERVER_TYPES_NR];	///< ���������NetServerTypes
	bool vPreviewFunction[PREVIEW_TYPES_NR];		///< Ԥ������PreviewTypes
	bool vCommFunction[COMM_TYPES_NR];				///<��������CommTypes
	bool vInputMethodFunction[NO_SUPPORT_NR];		///<���뷨����InputMethod
	bool vTipShowFunction[NO_TIP_SHOW_NR];			//��ǩ��ʾTipShow
	bool vMobileDVRFunction[MOBILEDVR_NR];			//���ع���MobileCar
	bool vOtherFunction[OTHER_NR];					//��������OtherFunction
};

//////////////////////////////////////////////////////////////////////////
/// ����������

/// ������Ϣ
struct EncodeInfo
{
	bool bEnable;			///< ʹ����
	int iStreamType;		///< �������ͣ�capture_channel_t
	bool bHaveAudio;		///< �Ƿ�֧����Ƶ
	uint uiCompression;		///< capture_comp_t������
	uint uiResolution;		///< capture_size_t������
};

/// ��������
/// ˵���� 
/// 1. vCombEncInfo ����ϱ����������ֻ��3000ϵ�е��豸�������������5000֮��Ķ�û��ʹ����
/// 2. vEncodeInfo �Ǹ�������ͨ����������Ϣ��ֻ����������ImageSizePerChannel��ExImageSizePerChannel��ʵ���ظ��ģ������ǵ�IE�ļ��������û���õ�
///    IE����ʽ�ǵ�ImageSizePerChannel��ExImageSizePerChannelΪ0ʱʹ��vEncodeInfo��ͷ������
/// ����ͨ��������֧�ֵķֱ�������ȡ����2������: 1 - ��ǰͨ��֧�ֵķֱ��ʼ�ImageSizePerChannel 2 - ��ǰͨ��֧�ֵ���߱���������nMaxPowerPerChannel
/// ����������������͸��������ܺ�
/// ����ͨ��������֧�ֵķֱ�������ȡ����3������: 1 - ��ǰͨ��֧�ֵķֱ��ʼ�ExImageSizePerChannel 2 - ��ǰͨ��֧�ֵ���߱���������nMaxPowerPerChannel
/// 3 - ���������õķֱ����¸�����֧�ֵķֱ��ʼ�ExImageSizePerChannel
/// iChannelMaxSetSync�� 1 - ��ʾ����ͨ���ķֱ��ʶ�Ҫһ��
struct EncodeAbility
{
	int iMaxEncodePower;		///< ֧�ֵ��ܱ�������
	int iChannelMaxSetSync;		///< ÿ��ͨ���ֱ����Ƿ���Ҫͬ�� 0-��ͬ��, 1 -ͬ��
	uint nMaxPowerPerChannel[N_SYS_CH];		///< ÿ��ͨ��֧�ֵ���߱�������
	uint ImageSizePerChannel[N_SYS_CH];		///< ÿ��ͨ��֧�ֵ�ͼ��ֱ���
	uint ExImageSizePerChannel[N_SYS_CH];		///< ÿ��ͨ��֧�ֵĸ�����ͼ��ֱ���
	EncodeInfo vEncodeInfo[CAPTURE_CHN_NR];	///< ������Ϣ
	EncodeInfo vCombEncInfo[CAPTURE_CHN_NR];	///< ��ϱ�����Ϣ
	int	iMaxBps;				///< ֧�ֵ������ʴ�СKbps
	uint ExImageSizePerChannelEx[N_SYS_CH][CAPTURE_IMAGE_SIZE_EXT_NR];	///< ָ���������ֱ�����ÿ��ͨ���ĸ�����֧�ֵ�ͼ��ֱ���
};

/// �����ڵ�������
struct BlindDetectFunction
{
	int iBlindConverNum;	///< �����ڵ�����
};

/// ��������������
struct MotionDetectFunction
{
	int iGridRow;
	int iGridColumn;
};

/// ֧�ֵ�DDNS����
struct DDNSServiceFunction
{
	std::vector<std::string> vDDNSTypes;
};

/// ����Э��
struct CommFunction
{
	std::vector<std::string> vCommProtocols;
};

/// ��̨Э��
struct PTZProtocolFunction
{
	std::vector<std::string> vPTZProtocols;
};

/// �Խ���Ƶ��������
struct TalkAudioFormatFunction
{
	AudioInFormatConfigAll audioFormat;
};

/// ����֧��
struct MultiLangFunction
{
	std::vector<std::string> vMultiLanguage;
};

/// ��Ƶ��ʽ֧��
struct MultVstdFunction
{
	std::vector<std::string> vMultiVstd;
};

///�������ȼ�����
struct NetOrderFunction
{
	bool bNetOrder;
};

///������������
struct NetConnectAbility
{
	int nCurTcpNum;
	int nMaxTcpNum;
	int nCurNatNum;
	int nMaxNatNum;
};
///����״̬��
struct CarStatusNum
{
	int iCarStatusNum;
};

/// ֧�ֵ�VGA�ֱ����б�
struct VGAResolutionAbility
{
	std::vector<std::string> vAbilityVGA;
};
#endif
