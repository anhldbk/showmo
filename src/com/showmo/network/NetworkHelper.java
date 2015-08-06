package com.showmo.network;
import com.showmo.base.ShowmoSystem;

import android.os.AsyncTask;
import android.util.Log;
/**
 * �������������
 * ����ģʽ getInstance()
 * �첽�������ʱ����
 * @author Terry
 *
 */
public class NetworkHelper {
	private static NetworkHelper m_instance;
	public  synchronized static  NetworkHelper  getInstance(){
		if(m_instance==null){
			m_instance=new NetworkHelper();
		}
		
		return m_instance ;
	}
	/**
	 * ������������ʱ���ô˷��� 
	 * @param requestCallBack �����࣬��д��Ҫ�ķ���
	 */
	public void newNetTask(RequestCallBack requestCallBack ){	
		 
		new NetBaseAsyncTask(requestCallBack). execute();
	}
	
	private class NetBaseAsyncTask   extends AsyncTask< Void , ResponseInfo,  ResponseInfo> {
		
		private RequestCallBack  mRequestCallBack ;
		
		public NetBaseAsyncTask(RequestCallBack  requestCallBack){
			this.mRequestCallBack = requestCallBack ;
		}
 
		@Override
		protected void onPostExecute(ResponseInfo result) {
				//���� isSuccess ��־�Ƿ�ɹ�
				if(result == null){
					mRequestCallBack.onFinally();
					return   ;
				}
				if(result.isSuccess ){
					mRequestCallBack.onSuccess(result );
				}else{
					mRequestCallBack.onFailure( result );
				}
				mRequestCallBack.onFinally();
		}
		
		@Override
		protected void onProgressUpdate(ResponseInfo... values) {
			if(mRequestCallBack == null){
				return  ;
			}
			mRequestCallBack.onLoading(values[0]);
		}
		
		@Override
		protected ResponseInfo doInBackground(Void... params) {
			if(mRequestCallBack == null){
				return null ;
			}
			return mRequestCallBack.doInBackground();
		}
		
		@Override
		protected void onPreExecute() {
			if(mRequestCallBack == null){
				return   ;
			}
			mRequestCallBack.onPrepare();
		}
	}
}
