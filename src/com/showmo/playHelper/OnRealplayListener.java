package com.showmo.playHelper;

public interface OnRealplayListener {
	/*
	 * ����ʱ��״̬�ص�
	 */
	void onRealplayStateListener(RealplayOutParams para);

	/*
	 * ���Ž���ص�
	 */
	void onRealplayResultListener(RealplayOutParams para);
	
	/*
	 * ����ǰ�ص�
	 */
	void onRealplayBeforeListener();
}
