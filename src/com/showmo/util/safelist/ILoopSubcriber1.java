package com.showmo.util.safelist;


/*
 * SafeListѭ��������item�����ߣ��ɶ����߾�����item��Ĳ���
 * 
 * @return boolean ������true����ѭ������ false�˳�ѭ��
 */
public abstract class ILoopSubcriber1<T,K>{
	public abstract boolean loop(T item,K para);
}
