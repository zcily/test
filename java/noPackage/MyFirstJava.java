public class MyFirstJava
{
	public static void main(String[] args)
	{
		String[] greeting = new String[3];	

		greeting[0] = "Welcome to core java";
		greeting[1] = "by Zwy";
		greeting[2] = "for testing";


		for(String temp : greeting)
		{
			System.out.println(temp);	
		}
	}
}



