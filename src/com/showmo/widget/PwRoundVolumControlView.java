package com.showmo.widget;

import com.showmo.R;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.util.TypedValue;
import android.view.MotionEvent;
import android.view.View;

public class PwRoundVolumControlView extends View {
	/**
	 * ��һȦ����ɫ
	 */
	private int mFirstColor;

	/**
	 * �ڶ�Ȧ����ɫ
	 */
	private int mSecondColor;
	/**
	 * Ȧ�Ŀ��
	 */
	private int mRingWidth;
	
	private int mRadius;
	/**
	 * ����
	 */
	private Paint mPaint;
	
	private Paint mBackPaint;
	/**
	 * ��ǰ����
	 */
	private int mCurrentCount = 0;

	/**
	 * �м��ͼƬ
	 */
	private Bitmap mImage;
	/**
	 * ÿ������ļ�϶
	 */
	private int mSplitSize;
	/**
	 * ����
	 */
	
	private int mBackgroundColor;
	private int mCount;

	private Rect mRect;
	private RectF mRectF;
	public PwRoundVolumControlView(Context context, AttributeSet attrs)
	{
		this(context, attrs, 0);
	}

	public PwRoundVolumControlView(Context context)
	{
		this(context, null);
	}

	/**
	 * ��Ҫ�ĳ�ʼ�������һЩ�Զ����ֵ
	 * 
	 * @param context
	 * @param attrs
	 * @param defStyle
	 */
	public PwRoundVolumControlView(Context context, AttributeSet attrs, int defStyle)
	{
		super(context, attrs, defStyle);
		init();
		TypedArray a = context.getTheme().obtainStyledAttributes(attrs, R.styleable.PwRoundVolumControlView, defStyle, 0);
		getDisAttrs(a);
	}
	private void getDisAttrs(TypedArray a){
		int n = a.getIndexCount();

		for (int i = 0; i < n; i++)
		{
			int attr = a.getIndex(i);
			switch (attr)
			{
			case R.styleable.PwRoundVolumControlView_VolumForeColor:
				mFirstColor = a.getColor(attr, Color.GREEN);
				break;
			case R.styleable.PwRoundVolumControlView_VolumBgColor:
				mSecondColor = a.getColor(attr, Color.CYAN);
				break;
			case R.styleable.PwRoundVolumControlView_centerIcon:
				mImage = BitmapFactory.decodeResource(getResources(), a.getResourceId(attr, 0));
				break;
				
			case R.styleable.PwRoundVolumControlView_radius:
				mRadius = a.getDimensionPixelSize(attr, 0);
				break;
			case R.styleable.PwRoundVolumControlView_ringWidth:
				mRingWidth= a.getDimensionPixelSize(attr, (int) TypedValue.applyDimension(
						TypedValue.COMPLEX_UNIT_PX, 20, getResources().getDisplayMetrics()));
				break;
			case R.styleable.PwRoundVolumControlView_VolumLevelCount:
				mCount = a.getInt(attr, 20);// Ĭ��20
				break;
			case R.styleable.PwRoundVolumControlView_splitSize:
				mSplitSize = a.getInt(attr, 20);
				break;
			case R.styleable.PwRoundVolumControlView_backcolor:
				mBackgroundColor = a.getColor(attr,0x5fffffff);
				break;
			}
		}
		a.recycle();
		
	}
	private void init(){
		mPaint = new Paint();
		mRect = new Rect();
		mBackPaint=new Paint();
		mRectF=new RectF();
	}
	@Override
	protected void onDraw(Canvas canvas)
	{
		mPaint.setAntiAlias(true); // �������
		mPaint.setStrokeWidth(mRingWidth); // ����Բ���Ŀ��
		mPaint.setStrokeCap(Paint.Cap.ROUND); // �����߶ζϵ���״ΪԲͷ
		mPaint.setAntiAlias(true); // �������
		mPaint.setStyle(Paint.Style.STROKE); // ���ÿ���
		int centre = getWidth() / 2; // ��ȡԲ�ĵ�x����
		if(mRadius==0){
			mRadius=centre - mRingWidth / 2;
		}
		
		mBackPaint.setStyle(Paint.Style.FILL);
		mBackPaint.setColor(mBackgroundColor);
		mBackPaint.setAntiAlias(true); 
		mRectF.left=0;
		mRectF.top=0;
		mRectF.bottom=getHeight();
		mRectF.right=getWidth();
		
		canvas.drawRoundRect(mRectF, 14.0f, 14.0f, mBackPaint);
		/**
		 * �����ȥ
		 */
		drawOval(canvas, centre, mRadius);

		/**
		 * �������������ε�λ��
		 */
		int innerRadius = mRadius - mRingWidth / 2;// �����Բ�İ뾶
		/**
		 * ���������εľ��붥�� = mCircleWidth + relRadius - ��2 / 2
		 */
		double innerRecWidHalf=Math.sqrt(2) * 1.0f / 2 * innerRadius;
		mRect.left = (int) (centre - innerRecWidHalf);
		/**
		 * ���������εľ������ = mCircleWidth + relRadius - ��2 / 2
		 */
		mRect.top = (int) (centre - innerRecWidHalf);
		mRect.bottom = (int) (mRect.left + innerRecWidHalf*2);
		mRect.right = (int) (mRect.left + innerRecWidHalf*2);

		/**
		 * ���ͼƬ�Ƚ�С����ô����ͼƬ�ĳߴ���õ�������
		 */
		if (mImage.getWidth() < Math.sqrt(2) * innerRadius)
		{
			mRect.left = (int) (mRect.left + innerRecWidHalf - mImage.getWidth() * 1.0f / 2);
			mRect.top = (int) (mRect.top + innerRecWidHalf - mImage.getHeight() * 1.0f / 2);
			mRect.right = (int) (mRect.left + mImage.getWidth());
			mRect.bottom = (int) (mRect.top + mImage.getHeight());

		}
		// ��ͼ
		canvas.drawBitmap(mImage, null, mRect, mPaint);
	}

	/**
	 * ���ݲ�������ÿ��С��
	 * 
	 * @param canvas
	 * @param centre
	 * @param radius
	 */
	private void drawOval(Canvas canvas, int centre, int radius)
	{
		/**
		 * ������Ҫ���ĸ����Լ���϶����ÿ�������ռ�ı���*360
		 */
		float itemSize = (360 * 1.0f - mCount * mSplitSize) / mCount;

		RectF oval = new RectF(centre - radius, centre - radius, centre + radius, centre + radius); // ���ڶ����Բ������״�ʹ�С�Ľ���

		mPaint.setColor(mSecondColor); // ����Բ������ɫ
		for (int i = 0; i < mCount; i++)
		{
			canvas.drawArc(oval, 90+i * (itemSize + mSplitSize), itemSize, false, mPaint); // ���ݽ��Ȼ�Բ��
		}

		mPaint.setColor(mFirstColor); // ����Բ������ɫ
		for (int i = 0; i < mCurrentCount; i++)
		{
			canvas.drawArc(oval, 90+i * (itemSize + mSplitSize), itemSize, false, mPaint); // ���ݽ��Ȼ�Բ��
		}
		
	}
	
	public int getMaxLevel(){
		return mCount;
	}
	public void setVolumLevel(int level)
	{
		if(level>mCount){
			mCurrentCount=mCount;
		}else if (level<0) {
			mCurrentCount=0;
		}
		mCurrentCount=level;
		postInvalidate();
	}
	
	/**
	 * ��ǰ����+1
	 */
	public void up()
	{
		setVolumLevel(++mCurrentCount);
	}

	/**
	 * ��ǰ����-1
	 */
	public void down()
	{
		setVolumLevel(--mCurrentCount);
	}

//	private int xDown, xUp;
//
//	@Override
//	public boolean onTouchEvent(MotionEvent event)
//	{
//
//		switch (event.getAction())
//		{
//		case MotionEvent.ACTION_DOWN:
//			xDown = (int) event.getY();
//			break;
//
//		case MotionEvent.ACTION_UP:
//			xUp = (int) event.getY();
//			if (xUp > xDown+20)// �»�
//			{
//				down();
//			} else
//			{
//				up();
//			}
//			break;
//		}
//
//		return true;
//	}
}
