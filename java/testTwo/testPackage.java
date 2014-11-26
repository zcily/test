package testTwo;

import myPackage.*;

public class testPackage
{
	public static void main(String[] args)
	{
		System.out.println("test package");		
		myPackageClass newPackage = new myPackageClass("test package");	

		newPackage.testCall();
		//newPackage.testOtherPackageByProtected();
		//newPackage.testOtherPackageByPrivated();
		//
		theSamePackage samePackage = new theSamePackage();
		samePackage.testCallbyTheSamePackage();
		samePackage.testProtectedBySamePackage();
		//samePackage.testPrivateBySamePackage();

/*
		ConnectionManager xx = new ConnectionManager();
		xx.getConnect();
		System.out.println("for call static function");
		*/
		Connection temp0 = ConnectionManager.getConnect();
		Connection temp1 = ConnectionManager.getConnect();
		Connection temp2 = ConnectionManager.getConnect();
		Connection temp3 = ConnectionManager.getConnect();

		if(temp3 == null){
			System.out.println("no more connection");	
		}
	}
}
