#ifndef __EX_DECODE_20110812_H
#define __EX_DECODE_20110812_H
#ifdef __cplusplus
extern "C"
{
#endif
#define MAX_HVR_CHNCAP			32

typedef struct HVR_CHNCAP 
{
	int nD1Chn;		// ֧�ֵ�D1·��
	int n960HChn;	// ֧�ֵ�960H·��
	int n720PChn;	// ֧�ֵ�720P·��
	int n1080PChn;	// ֧�ֵ�1080P·��
	int nCIFChn;	//֧�ֵ�CIFͨ����
	int nHD1Chn;	//֧�ֵ�HD1ͨ����
	int nRes[2];
}HVR_CHNCAP, *PHVR_CHNCAP;

typedef struct CAPTURE_HVRCAP 
{
	HVR_CHNCAP DigitalCap;		// ֧�ֵ�����ͨ����Ϣ
	HVR_CHNCAP AnalogCap;		// ֧�ֵ�ģ��ͨ����Ϣ
}CAPTURE_HVRCAP, *PCAPTURE_HVRCAP;

typedef struct CAPTURE_TOTAL_HVRCAP 
{
	int		nHVRCap;			// ʵ��֧�ֵ�ģʽ
	CAPTURE_HVRCAP	HVRCap[MAX_HVR_CHNCAP];		// ����ģʽ�Ļ���
}CAPTURE_TOTAL_HVRCAP, *PCAPTURE_TOTAL_HVRCAP;
 
/// ����HVR��Ӧ��ģʽ
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureSetHVRCap(const CAPTURE_HVRCAP *pHVRCap);
 
//! ��õ�ǰHVR��Ӧ��ģʽ
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureGetCurHVRCap(CAPTURE_HVRCAP *pHVRCap);
 
//! ���HVR֧�ֵ�Ӧ��ģʽ
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureGetTotalHVRCap(CAPTURE_TOTAL_HVRCAP *pHVRCap);
 
 
// HVR�Ľӿ�����һЩ������3���ӿڣ�һ����ȡ֧�ֵ����й���ģʽ��һ�����ù���ģʽ��һ����ȡ��ǰ����ģʽ

#ifdef __cplusplus
}
#endif

#endif

