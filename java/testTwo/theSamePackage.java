package testTwo;

class theSamePackage
{
	public theSamePackage()
	{
		System.out.println("construct in the same package");	
	}

	void testCallbyTheSamePackage()
	{
		System.out.println("test the call from the same package");	
	}

	protected void testProtectedBySamePackage()
	{	
		System.out.println("test the call from the same package by protected");	
	}

	private void testPrivateBySamePackage()
	{	
		System.out.println("test the call from the same package by private");	
	}
}
