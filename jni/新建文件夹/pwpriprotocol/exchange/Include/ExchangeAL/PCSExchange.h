#ifndef __EXCHANGE_PCS_H
#define __EXCHANGE_PCS_H

#include <string>
#include "../Infra/Types.h"

struct DeviceCode
{
	std::string device_code;
	std::string user_code;
	std::string verification_url;
	std::string qrcode_url;
	int expires_in;  //Device_code/User_code ����ʱ��,��λΪs
	int interval;    //��ȡAccess_token���,��λΪs	
};

struct AccessTokenCode
{
	std::string access_token;
	int expires_in;   			//Access Token����Ч�ڣ�����Ϊ��λ
	std::string refresh_token;	 
	std::string scope;
	std::string session_key;
	std::string session_secret;
};

struct QuotaCode		////�ռ������Ϣ
{
	uint quota;		////�ռ����,��λ�ֽ�
	uint used;		////��ʹ�ÿռ�,��λ�ֽ�
};

struct UploadCode			////�ϴ��ļ�
{
	std::string path;		////�ļ�·��
	uint size;			////�ļ��ֽڴ�С
	uint ctime;			////�ļ�����ʱ��	
	uint mtime;			////�ļ��޸�ʱ��
	std::string md5;		////�ļ�md5ǩ��	
	uint fs_id;			////�ļ���PCS����ʱΨһ��ʶID
};

struct SliceUploadCode	    ////��Ƭ�ϴ�--�ļ���Ƭ���ϴ�
{
	std::string md5;
};

struct MergeFileCode		////��Ƭ�ϴ�--�ϲ��ļ�
{
	std::string path;		////�ļ�·��
	uint size;			////�ļ��ֽڴ�С
	uint ctime;			////�ļ�����ʱ��	
	uint mtime;			////�ļ��޸�ʱ��
	std::string md5;		////�ļ�md5ǩ��	
	uint fs_id;			////�ļ���PCS����ʱΨһ��ʶID
};

struct BaiduPcsConfig
{
	int 	action;		// 0:��; 1: �����; 2: ���ò���
	bool  bind;		// 0:δ��; 1: �Ѱ�
	char 	userCode[32];
	int	bConfirm;	// �󶨹��̵Ĳ��������ʶ��0��ʾ��һ����ȡusercode
	bool	fileDetect;
	bool	fileAlarm;
	bool	fileBlind;
	bool	snapDetect;
	bool	snapAlarm;
	bool	snapBlind;
};


#endif
