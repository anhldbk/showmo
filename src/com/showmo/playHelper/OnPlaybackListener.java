package com.showmo.playHelper;

public interface OnPlaybackListener {
	/*
	 * �طſ�������
	 */
	void onPlaybackOver(boolean bres,int errorCode);
	
	void onPlaybackPre();   
	/*
	 * �طŽ���
	 */
	void onPlaybackCompleted();
	void onStopPlayback(boolean bres,int errCode);
}
