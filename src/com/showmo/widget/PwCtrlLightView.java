package com.showmo.widget;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.ColorMatrixColorFilter;
import android.os.Handler;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.widget.ImageButton;
/**
 * ��ס��ť�ϰ벿�ֱ������°벿�ֱ䰵
 *  ��ɫ�ı�ӿ� onColorChangeListener
 *  �ı���ɫ���� public void setColor(int step)
 * @author Terry
 *
 */
@Deprecated
public class PwCtrlLightView extends ImageButton  {

	public static int COLOR_UPDATE_INTERVAL = 25; //���º���ɫ���µ�ʱ����(ms)
	
	public static float COLOR_UPDATE_STEP = 0.035f ;  //���º���ɫ���µĲ���
	
	public static float COLOR_UPDATE_MAX = 4f ; //���º���ɫ�Աȶ����ֵ
	
	public static float COLOR_UPDATE_MIN = 0.5f ;  //���º���ɫ�Աȶ���Сֵ 

	public static float COLOR_OFFSET_DEF = 1.2f ; //Ĭ�ϵ���ɫ�Աȶ�
	
	//���㹫ʽ��COLOR_OFFSET_DEF- COLOR_UPDATE_MIN��/COLOR_UPDATE_STEP
	public static int STEP_COUNT_DEF = 20 ; //Ĭ�ϵĲ��� 
	
	
	private int stepCount ;

	private Handler mHandler ;

	private UpdateColorRunnable mUpdateColorRunnable ;

	private float mColorOffsetNow   ; //ɫ��ƫ����

	private boolean isColorLight;  //��ɫ�Ƿ����

	private boolean mColorUpdateFlag ;

	private float[] mColorMatrix   ;

	private  onColorChangeListener mOnColorChangeListener ;

	private boolean mInitColorOffset;

	public PwCtrlLightView(Context context) {
		super(context);
		init();
	}
 

	public PwCtrlLightView(Context context, AttributeSet attrs, int defStyleAttr) {
		super(context, attrs, defStyleAttr);
		init();
	}

	public PwCtrlLightView(Context context, AttributeSet attrs) {
		super(context, attrs);
		init();
	}

	private void init(){
		mHandler = new Handler();
		mUpdateColorRunnable = new UpdateColorRunnable();
		mInitColorOffset = true ;
		mColorOffsetNow = COLOR_OFFSET_DEF ;
		stepCount = STEP_COUNT_DEF ;
	}

	private void initColorOffset(){
		getBackground().setColorFilter(
				new ColorMatrixColorFilter(getFloatArray2(COLOR_OFFSET_DEF)));
		setBackgroundDrawable(getBackground());
	}
	
	@Override
	protected void onDraw(Canvas canvas) {
		super.onDraw(canvas);
		if(mInitColorOffset){
			initColorOffset();
			mInitColorOffset = false  ;
		}
	}

	@Override
	public boolean onTouchEvent(MotionEvent event) {
		switch (event.getAction()) {
		case MotionEvent.ACTION_DOWN:

			isColorLight = event.getX() < getWidth()/2 ? false :true ;
			mHandler.post (mUpdateColorRunnable );
			mColorUpdateFlag = true ;

			break;
		case MotionEvent.ACTION_UP:
			mColorUpdateFlag = false ;
			break;

		default:
			break;
		}
		return super.onTouchEvent(event);
	}



	private class UpdateColorRunnable implements  Runnable{
		@Override
		public void run() {
			if(mColorUpdateFlag){
				boolean canUpdate = false  ;
				canUpdate = isColorLight?mColorOffsetNow<=COLOR_UPDATE_MAX:
					mColorOffsetNow  >= COLOR_UPDATE_MIN;
				
				if(canUpdate){
					
					if(isColorLight){
						mColorOffsetNow = mColorOffsetNow +COLOR_UPDATE_STEP >COLOR_UPDATE_MAX?
								COLOR_UPDATE_MAX:mColorOffsetNow + COLOR_UPDATE_STEP   ;
						stepCount = stepCount < 100 ? stepCount +1: 100   ;
					}else{
						mColorOffsetNow =  mColorOffsetNow -COLOR_UPDATE_STEP <COLOR_UPDATE_MIN?
								COLOR_UPDATE_MIN:mColorOffsetNow - COLOR_UPDATE_STEP  ;
						stepCount = stepCount > 0 ? stepCount -1 : 0   ;
					}
					
					getBackground().setColorFilter(
							new ColorMatrixColorFilter(getFloatArray2(mColorOffsetNow)));
					setBackgroundDrawable(getBackground());
					if(mOnColorChangeListener!=null){
						mOnColorChangeListener.onColorChange( stepCount);
					}
					mHandler.postDelayed(this, COLOR_UPDATE_INTERVAL);
				}
				
				
			}




		}

	}

	public float[] getFloatArray(float colorOffset){
		if(mColorMatrix == null){
			mColorMatrix = new float[20] ;
			for(int i=0;i<20;i++){
				switch (i) {
				case 0:
				case 6:
				case 12:
				case 18:
					mColorMatrix[i] = 1 ;
					break;
				default:
					mColorMatrix[i]=0;
					break;
				}
			}
		}

		mColorMatrix[4] = colorOffset ;
		mColorMatrix[9] = colorOffset ;
		mColorMatrix[14] = colorOffset ;

		return mColorMatrix;

	}
	
	float lumR = 0.3086f;
	float lumG = 0.6094f;
	float lumB = 0.0820f;
	float lum = 0 ;
	
	public float[] getFloatArray2(float colorOffset){
		if(mColorMatrix == null){
			mColorMatrix = new float[25] ;
			for(int i=0;i<20;i++){
				switch (i) {
				case 0:
				case 6:
				case 12:
				case 18:
				case 24:
					mColorMatrix[i] = 1 ;
					break;
				default:
					mColorMatrix[i]=0;
					break;
				}
			}
		}
		
		//���Ͷ�
//		float s = colorOffset ;
//		float sr = (1-s)*lumR ;
//		float sg = (1-s)*lumG ;
//		float sb = (1-s)*lumB ;
//		
//		mColorMatrix[0] = sr + s;
//		mColorMatrix[1] = sr  ;
//		mColorMatrix[2] = sr  ;
//		
//		mColorMatrix[5] = sg;
//		mColorMatrix[6] = sg+s  ;
//		mColorMatrix[7] = sg  ;
//		
//		mColorMatrix[10] = sb;
//		mColorMatrix[11] = sb  ;
//		mColorMatrix[12] = sb +s  ;
		
//		mColorMatrix[0] = colorOffset ;
//		mColorMatrix[6] = colorOffset ;
//		mColorMatrix[12] = colorOffset ;
		
		//�Աȶ�
		float c = colorOffset ;
		float t = (1 - c )/2 ;
		
		mColorMatrix[0] = c ;
		mColorMatrix[6] = c ;
		mColorMatrix[12] =c  ;
		
		mColorMatrix[20] = t ;
		mColorMatrix[21] = t ;
		mColorMatrix[22] = t  ;
		
		
		mColorMatrix[20] += (colorOffset - COLOR_UPDATE_MIN) *30 ;
		mColorMatrix[21] += (colorOffset - COLOR_UPDATE_MIN) *30 ;
		mColorMatrix[22] +=(colorOffset - COLOR_UPDATE_MIN) *30 ;
		
		return mColorMatrix;

	}

	public interface onColorChangeListener{
		void onColorChange(int luminance);
	}

	public onColorChangeListener getOnColorChangeListener() {
		return mOnColorChangeListener;
	}


	public void setOnColorChangeListener(
			onColorChangeListener mOnColorChangeListener) {
		this.mOnColorChangeListener = mOnColorChangeListener;
	}
	/**
	 * ���ݲ����ı�ͼƬ��ɫ
	 * @param step ��Χ 0 - 100 ��>100 ��Ϊ100���� ��<0 ��Ϊ0����
	 */
	public void setColor(int step){
		if(step>100 ){
			step = 100 ;
		}else if(step < 0){
			step = 0 ;
		}
		
		stepCount = step ;
		
		mColorOffsetNow = COLOR_UPDATE_MIN + COLOR_UPDATE_STEP * step ;
		getBackground().setColorFilter(
				new ColorMatrixColorFilter(getFloatArray2(mColorOffsetNow)));
		setBackgroundDrawable(getBackground());
		invalidate();
	}
	 

}
