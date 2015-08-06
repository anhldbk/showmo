package com.showmo.util;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.PixelFormat;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;

public class ZoomPic {
	 public static Bitmap drawableToBitmap(Drawable drawable) // drawable ת���� bitmap 
      {
                int width = drawable.getIntrinsicWidth();   // ȡ drawable �ĳ��� 
                int height = drawable.getIntrinsicHeight();
                Bitmap.Config config = drawable.getOpacity() != PixelFormat.OPAQUE ? Bitmap.Config.ARGB_8888:Bitmap.Config.RGB_565;         // ȡ drawable ����ɫ��ʽ 
                Bitmap bitmap = Bitmap.createBitmap(width, height, config);     // ������Ӧ bitmap 
                Canvas canvas = new Canvas(bitmap);         // ������Ӧ bitmap �Ļ��� 
                drawable.setBounds(0, 0, width, height);
                drawable.draw(canvas);      // �� drawable ���ݻ��������� 
                return bitmap;
      }

	 public static Drawable zoomDrawable(Drawable drawable, int w, int h)
      {
                int width = drawable.getIntrinsicWidth();
                int height= drawable.getIntrinsicHeight();
                Bitmap oldbmp = drawableToBitmap(drawable); // drawable ת���� bitmap 
                Matrix matrix = new Matrix();   // ��������ͼƬ�õ� Matrix ���� 
                float scaleWidth = ((float)w / width);   // �������ű��� 
                float scaleHeight = ((float)h / height);
                matrix.postScale(scaleWidth, scaleHeight);         // �������ű��� 
                Bitmap newbmp = Bitmap.createBitmap(oldbmp, 0, 0, width, height, matrix, true);       // �����µ� bitmap ���������Ƕ�ԭ bitmap �����ź��ͼ 
                return new BitmapDrawable(newbmp);       // �� bitmap ת���� drawable ������ 
      }
	 
}
