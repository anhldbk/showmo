
package com.showmo.dataDef.copy;
import java.lang.String;

import android.text.format.Time;
public class PWPlayBackVideoFrame {
	public PWPlayBackVideoFrame(Time bTime,Time eTime,String fileName,int fileType,int size,int cameraId){
		beginDateTime=bTime;
		endDateTime=eTime;
		sFileName=fileName;
		nFileType=fileType;
		videoSize=size;
		nCameraId=cameraId;
	}
	public Time beginDateTime;//��Ƶ��ʼʱ��
	public Time endDateTime;//��Ƶ����ʱ��
	public String sFileName;
	public int  nFileType;				    // �ļ����� ö�٣�Remote_File_Type
	public int videoSize;
	public int  nCameraId;
}
