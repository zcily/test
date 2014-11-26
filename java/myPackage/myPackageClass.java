package myPackage;

public class myPackageClass
{
	public myPackageClass()
	{
		System.out.println("construct in my package class");	
	}

	public myPackageClass(final String name)
	{
		System.out.println("construct by " + name);	
	}

	public void finalize()
	{
		System.out.println("just test finalizer");	
	}

	public void testCall()
	{
		System.out.println("success call from my package class");	
	}

	protected void testOtherPackageByProtected()
	{		
		System.out.println("success call from my package class by protected");	
	}

	private void testOtherPackageByPrivated()
	{		
		System.out.println("success call from my package class by private");	
	}
}

