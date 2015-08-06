package com.showmo.util;

import java.io.UnsupportedEncodingException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.SecureRandom;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

/**
 * ���ܹ����࣬�ԳƼ���AES
 * @author Terry
 *
 */
public class AESUtil {
	
	public static String KEY_AES = "01020304";
	
	 /** 
     * ���� 
     * @method encrypt 
     * @param content   ��Ҫ���ܵ����� 
     * @param password  �������� 
     * @return 
     * @throws  
     * @since v1.0 
     */  
    public static byte[] encrypt(String content, String password){  
        try {  
            KeyGenerator kgen = KeyGenerator.getInstance("AES");  
            SecureRandom sr;
			try {
				sr = SecureRandom.getInstance("SHA1PRNG","Crypto" );
				sr.setSeed(password.getBytes());
			} catch (NoSuchProviderException e) {
				e.printStackTrace();
				return null ;
			}
            kgen.init(128, sr);  
            SecretKey secretKey = kgen.generateKey();  
            byte[] enCodeFormat = secretKey.getEncoded();  
            SecretKeySpec key = new SecretKeySpec(enCodeFormat, "AES");  
            Cipher cipher = Cipher.getInstance("AES");// ����������  
            
            byte[] byteContent = content.getBytes("utf-8");  
            cipher.init(Cipher.ENCRYPT_MODE, key);// ��ʼ��  
            byte[] result = cipher.doFinal(byteContent);  
            return result; // ����  
        } catch (NoSuchAlgorithmException e) {  
            e.printStackTrace();  
        }catch (NoSuchPaddingException e) {  
            e.printStackTrace();  
        }catch (UnsupportedEncodingException e) {  
            e.printStackTrace();  
        }catch (InvalidKeyException e) {  
            e.printStackTrace();  
        }catch (IllegalBlockSizeException e) {  
            e.printStackTrace();  
        }catch (BadPaddingException e) {  
            e.printStackTrace();  
        }  
        return null;  
    }  
      
    /** 
     * ���� 
     * @method decrypt 
     * @param content   ���������� 
     * @param password  ������Կ 
     * @return 
     * @throws  
     * @since v1.0 
     */  
    public static byte[] decrypt(byte[] content, String password){  
        try {  
            
            KeyGenerator kgen = KeyGenerator.getInstance("AES");  
            SecureRandom sr;
			try {
				sr = SecureRandom.getInstance("SHA1PRNG","Crypto" );
				sr.setSeed(password.getBytes());
			} catch (NoSuchProviderException e) {
				e.printStackTrace();
				return null ;
			}
            
            kgen.init(128, sr);  
            SecretKey secretKey = kgen.generateKey();  
            byte[] enCodeFormat = secretKey.getEncoded();  
            SecretKeySpec key = new SecretKeySpec(enCodeFormat, "AES");  
            Cipher cipher = Cipher.getInstance("AES");// ����������  
            cipher.init(Cipher.DECRYPT_MODE, key);// ��ʼ��  
            byte[] result = cipher.doFinal(content);  
            return result; // ����  
        } catch (NoSuchAlgorithmException e) {  
            e.printStackTrace();  
        }catch (NoSuchPaddingException e) {  
            e.printStackTrace();  
        }catch (InvalidKeyException e) {  
            e.printStackTrace();  
        }catch (IllegalBlockSizeException e) {  
            e.printStackTrace();  
        }catch (BadPaddingException e) {  
            e.printStackTrace();  
        }  
          
        return null;  
    }  
      
    /** 
     * ��������ת����16���� 
     * @method parseByte2HexStr 
     * @param buf 
     * @return 
     * @throws  
     * @since v1.0 
     */  
    public static String parseByte2HexStr(byte buf[]){  
        StringBuffer sb = new StringBuffer();  
        for(int i = 0; i < buf.length; i++){  
            String hex = Integer.toHexString(buf[i] & 0xFF);  
            if (hex.length() == 1) {  
                hex = '0' + hex;  
            }  
            sb.append(hex.toUpperCase());  
        }  
        return sb.toString();  
    }  
      
    /** 
     * ��16����ת��Ϊ������ 
     * @method parseHexStr2Byte 
     * @param hexStr 
     * @return 
     * @throws  
     * @since v1.0 
     */  
    public static byte[] parseHexStr2Byte(String hexStr){  
        if(hexStr.length() < 1)  
            return null;  
        byte[] result = new byte[hexStr.length()/2];  
        for (int i = 0;i< hexStr.length()/2; i++) {  
        	String highString=hexStr.substring(i*2, i*2+1);
            int high = Integer.parseInt(highString, 16);  
            String lowString=hexStr.substring(i*2+1, i*2+2);
            int low = Integer.parseInt(lowString, 16);  
            result[i] = (byte) (high * 16 + low);  
        }  
        return result;  
    }  
	
}
