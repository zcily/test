package com.thtfit.test;

import com.thtfit.test.R;
import java.lang.reflect.Field;

public class main
{
	public static void main(String[] args)
	{
		int sourceId = 0;

		try {
			sourceId = getResourceID("button_uartupdate");
			sourceId = getResourceID("button_posandroid");
		} catch (Exception e) {
			System.out.println("get id : " + e.toString());	
		}
	}

	private static int getResourceID(String idName) throws NoSuchFieldException, IllegalAccessException{
		int resourceID = 0;

		System.out.println( "********************** getResourceID : " + resourceID);
		Field field = R.id.class.getField(idName);  

		System.out.println( "********************** getResourceID : end");
		if(field != null){
			resourceID = field.getInt(new R.id());
			System.out.printf( "********************** getResourceID : %#x\n",resourceID);
		} else {
			System.out.println( "**********************  not find id");
			resourceID = -1; 
		}   
		return resourceID;
	}   

}
