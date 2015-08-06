package com.showmo.service;

import com.showmo.base.ShowmoApplication;
import com.showmo.util.LogUtils;
import com.showmo.util.MailUtils;
import com.showmo.util.StringUtil;

import android.R.anim;
import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;

public class PwSendExceptionMailService extends Service {
	public static final String ACTION_STRING="ipc365.app.showmo.service.PwSendExceptionMailService.RUNACTOIN";
	public static final String EXCEPTION_STR_KEY="data";
	@Override
	public IBinder onBind(Intent intent) {
		// TODO Auto-generated method stub
		LogUtils.v("mailservice", "PwSendExceptionMailService onBind "+android.os.Process.myPid());
		return null;
	}

	@Override
	public void onCreate() {
		// TODO Auto-generated method stub
		LogUtils.v("mailservice", "PwSendExceptionMailService onCreate "+android.os.Process.myPid());
		
		super.onCreate();
	}

	@Override
	public void onStart(Intent intent, int startId) {
		// TODO Auto-generated method stub
		LogUtils.v("mailservice", "PwSendExceptionMailService onStart "+android.os.Process.myPid());
		super.onStart(intent, startId);
	}
	private int lastOneStartId;
	@Override
	public int onStartCommand(Intent intent, int flags, int startId) {
		// TODO Auto-generated method stub
		lastOneStartId=startId;
		LogUtils.v("mailservice", "PwSendExceptionMailService onStartCommand "+android.os.Process.myPid());
		String str=intent.getStringExtra(EXCEPTION_STR_KEY);
		LogUtils.v("mailservice", "get:: "+str+" startId "+startId);
		super.onStartCommand(intent, flags, startId);
		
		if(StringUtil.isNotEmpty(str)){
			//������ʱ����application�����޷���ʾ��һ�䣬ֻ���ڷ���������ʾ��
			Toast.makeText(this,"�ǳ���Ǹ����Ϊδ֪ԭ��Сĩ�����ˣ�����Ϊ������" , Toast.LENGTH_SHORT).show();
			new Thread(new MailExceptionRunnable(str,startId)).start();
		}
		return  START_REDELIVER_INTENT;
	}

	public class MailExceptionRunnable implements Runnable{
		private String sendmsg;
		private int id;
		
		public MailExceptionRunnable(String msg,int sendId){
			sendmsg=msg;
			id=sendId;
		}
		public void run(){
			Log.e("send", "MailExceptionRunnable sendMail bf "+id);
			boolean bres=MailUtils.sendMail("breakdown", sendmsg, 
					MailUtils.InternalEmailAddr, MailUtils.InternalEmailAddrPsw, MailUtils.InternalEmailAddr, null);
			Log.e("send", "MailExceptionRunnable sendMail af "+bres+id);
			if(id==lastOneStartId){
				LogUtils.v("mailservice", "stopsetf startid== "+lastOneStartId);
				stopSelf();
			}
		}
	}
	
	@Override
	public void onDestroy() {
		// TODO Auto-generated method stub
		LogUtils.v("mailservice", "PwSendExceptionMailService onDestroy "+android.os.Process.myPid());
		super.onDestroy();
	}

	@Override
	public boolean onUnbind(Intent intent) {
		// TODO Auto-generated method stub
		LogUtils.v("mailservice", "PwSendExceptionMailService onUnbind "+android.os.Process.myPid());
		return super.onUnbind(intent);
	}

	@Override
	public void onRebind(Intent intent) {
		// TODO Auto-generated method stub
		LogUtils.v("mailservice", "PwSendExceptionMailService onRebind "+android.os.Process.myPid());
		super.onRebind(intent);
	}

	@Override
	public void onTaskRemoved(Intent rootIntent) {
		// TODO Auto-generated method stub
		LogUtils.v("mailservice", "PwSendExceptionMailService onTaskRemoved "+android.os.Process.myPid());
		super.onTaskRemoved(rootIntent);
	}
	
	
}
