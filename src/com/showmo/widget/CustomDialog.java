package com.showmo.widget;


import com.showmo.R;

import android.app.Dialog;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

/**
 * ͨ�õĵ�������
 * ʹ�÷�����
 * setTitle()���ñ���
 * setMessage()������Ϣ
 * setOnCustomDialogClickListener()���ð�������
 * 
 * @author Terry
 *
 */
public class CustomDialog extends Dialog implements OnClickListener {

	Context context;
	private TextView mTvTitle;
	private TextView mTvMessage;
	private onCustomDialogClickListener mOnCustomDialogClickListener;
	private int mTitleResis;
	private int mMessageResid;
	private int mBtnOkResid ;
	private int mBtnCancelResid ;
	private Button mBtnOk;
	private Button mBtnCancel;
	
	public CustomDialog(Context context) {
		super(context);
		this.context = context;
	}
	public CustomDialog(Context context, int theme){
		super(context, theme);
		this.context = context;
	}
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.dialog_custom);
		initView();
	}

	private void initView(){
		mTvTitle =  (TextView)findViewById(R.id.tv_dialog_title);
		mTvMessage = (TextView)findViewById(R.id.tv_dialog_message);
		mBtnOk = (Button)findViewAndSet(R.id.btn_dialog_ok);
		mBtnCancel = (Button)findViewAndSet(R.id.btn_dialog_cancel);
		mBtnOk.setText(mBtnOkResid);
		mBtnCancel.setText(mBtnCancelResid);
		mTvTitle.setText(mTitleResis);
		mTvMessage.setText(mMessageResid);

	}

	private View findViewAndSet(int id){
		View view = findViewById(id);
		view.setOnClickListener(this);
		return view ;
	}
	
	/**
	 * ���ñ���
	 * @param resid
	 */
	public void setTitle(int resid) {
		mTitleResis = resid; 
		if(mTvTitle != null){
			mTvTitle.setText(resid);
		}
	}
	
	/**
	 * ������Ϣ
	 * @param resid
	 */
	public void setMessage(int resid){
		mMessageResid = resid; 
		if(mTvMessage != null){
			mTvMessage.setText(resid);
		}
	}
	/**
	 * �����Ҳఴ������
	 * @param resid
	 */
	public void setBtnOkResid(int resid){
		mBtnOkResid = resid ;
		if(mBtnOk != null){
			mBtnOk.setText(resid);
		}
		
	}
	/**
	 * ������ఴ������
	 * @param resid
	 */
	public void setBtnCancelResid(int resid){
		mBtnCancelResid = resid ;
		if(mBtnCancel != null){
			mBtnCancel.setText(resid);
		}
		
	}
	
	
	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.btn_dialog_ok:
			if(mOnCustomDialogClickListener!=null){
				mOnCustomDialogClickListener.onDialogOkClick();
			}
			
			break;
		case R.id.btn_dialog_cancel:
			if(mOnCustomDialogClickListener!=null){
				mOnCustomDialogClickListener.onDialogCancelClick();
			}
			break;

		default:
			break;
		}
	}
	
	public interface onCustomDialogClickListener{
		void onDialogOkClick();
		void onDialogCancelClick();
		
	}
	
	public onCustomDialogClickListener getOnCustomDialogClickListener() {
		return mOnCustomDialogClickListener;
	}
	/**
	 * ������ť���
	 * @param mOnCustomDialogClickListener
	 */
	public void setOnCustomDialogClickListener(
			onCustomDialogClickListener mOnCustomDialogClickListener) {
		this.mOnCustomDialogClickListener = mOnCustomDialogClickListener;
	}
	
	

}
