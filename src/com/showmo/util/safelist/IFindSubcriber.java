package com.showmo.util.safelist;

/*
 * Safelist�� �������Ҷ����ߣ��ɿͻ�����ÿһ��ĵ�ʽ�ж�
 */
public interface IFindSubcriber<T> {
	/*
	 * @return boolean ����ture������ȳ���
	 * @para T ��
	 */
	boolean eqJudge(T item);
}
