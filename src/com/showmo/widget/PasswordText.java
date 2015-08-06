package com.showmo.widget;

import android.content.Context;
import android.text.Editable;
import android.text.Selection;
import android.text.Spannable;
import android.text.TextWatcher;
import android.text.method.HideReturnsTransformationMethod;
import android.text.method.PasswordTransformationMethod;
import android.util.AttributeSet;
import android.widget.EditText;
/**
 * 
 * @author Terry
 *����༭��
 *���ƷǷ��ַ�����
 *���������Ƿ���ʾ
 */
public class PasswordText extends EditText{
	
	private boolean isPswVisible ;
	
	public PasswordText(Context context) {
		super(context);
	}

	public PasswordText(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);

	}

	public PasswordText(Context context, AttributeSet attrs) {
		super(context, attrs);

	}
	
	 
	
	public void setPswVisible(boolean isVisible){
		
		isPswVisible = isVisible;
		if(isPswVisible){ 
			setTransformationMethod(HideReturnsTransformationMethod.getInstance());
		}else{ 
			 setTransformationMethod(PasswordTransformationMethod.getInstance());
		}
		
		//���ù��
		Editable text = null ;
		if(isFocused()){
			  text = getText();
		} 
		if (text instanceof Spannable) {
			Spannable spanText = (Spannable)text;
			Selection.setSelection(spanText, text.length());
		}
		
	}
	
	public  void setPswVisible(){
		isPswVisible = ! isPswVisible;
		setPswVisible( isPswVisible);
	}
	
	

}
