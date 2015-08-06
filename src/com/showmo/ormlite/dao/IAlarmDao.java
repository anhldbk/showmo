package com.showmo.ormlite.dao;

import java.util.List;

import com.showmo.alarmManage.Alarm;

import android.R.interpolator;


public interface IAlarmDao {
	public int insert(Alarm info);
	public List<Alarm> queryAllByDeviceId(int deviceId);
	public List<Alarm> queryLimitByTime(int deviceId,long beginTime,long endTime,int limit);//����begintime��endtime֮�����µ�limit����Ϣ
	
	public List<Alarm> queryLastestItems(int deviceId,int limit);//�������ݱ��������µ�limit��
	public List<Alarm> queryLastestItems(int deviceId,long beginTime, int limit);//�������ݱ�����beginTime֮ǰ��limit��
	
	public Alarm queryByRecordId(int id);
	public int RemoveByRecordId(int id);
	public int Remove(List<Alarm> data);
	public int RemoveByDeviceId(int deviceId);
	public int updateInfo(Alarm info);
}
