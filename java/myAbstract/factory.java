package myAbstract;

interface product
{
	void productName();
	void Date();
}

interface myFactory
{
	product getProduct();
}

class IPproduct implements product
{	
	public void productName()
	{
		System.out.println("in IPproduct : " + "Iphone");
	}

	public void Date()
	{
		System.out.println("iphone product date : " + " 11-27-2014");
	}
}

class NKproduct implements product
{
	public void productName()
	{
		System.out.println("in nkproduct : " + "Nokia");
	}

	public void Date()
	{
		System.out.println("nk product date : " + " 11-27-2014");
	}
}

class checkIPfromfactory implements myFactory
{
	public product getProduct() {
		return new IPproduct();	
	}
}

class checkNKfromfactory implements myFactory
{
	public product getProduct() {
		return new NKproduct();	
	}
}

public class factory 
{
	public static void showFactoryProduct(myFactory mf){
		product pd = mf.getProduct();
		pd.productName();	
		pd.Date();
	}

	public static void main(String[] args)
	{
		showFactoryProduct(new checkIPfromfactory());	
		showFactoryProduct(new checkNKfromfactory());	
	}
}
