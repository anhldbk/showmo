package com.showmo.activity.alarmInfo;

public interface CameraAlarmType {
	int ALARM_TYPE_OFFLINE = 0;
	int ALARM_TYPE_LOST_VIDEO = 1;
	int	ALARM_TYPE_MASK_VIDEO = 2;
	int	ALARM_TYPE_DETECTION_MOTION = 3;
	int	ALARM_TYPE_DISK_FULL = 4;
	int	ALARM_TYPE_RECORD_ABNORMAL = 5;
	int	ALARM_TYPE_LOG_LAMP_OFF = 6;          //Log����ϵ� 
	int	ALARM_TYPE_LED_SCREEN_OFF = 7;         //LED��Ļ�ϵ�
	int	ALARM_TYPE_TALK_REQUEST = 8;           //����ͨ������
	int	ALARM_TYPE_LOG_LAMP_ON = 9;           //Log�����ϵ� 
	int	ALARM_TYPE_LED_SCREEN_ON = 10;         //LED��Ļ�ϵ�

	//by ¼��ʧ����
	int ALARM_TYPE_LOST_RECORD = 11;

	int	ALARM_TYPE_ONLINE = 20;
	//by �ޱ���
	//20120518
	int	ALARM_TYPE_NULL = 100;

}
