package com.showmo.util.safelist;
/*
 * SafeListѭ��������item�����ߣ��ɶ����߾�����item��Ĳ���
 */
public interface ILoopSubcriber<T> {
	/*
	 * @para   T   ��
	 * @return boolean ������true����ѭ������ false�˳�ѭ��
	 */
	boolean loop(T item);//�Ƿ����ѭ��
}
