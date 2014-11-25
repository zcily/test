package testOne;


public class testArgs
{
	static void printStringArray(String...args)
	{
		for(String temp : args)	{
			System.out.println("string : " + temp);	
		}
	}


	static void printInteger(Integer...args)
	{
		for(Integer temp : args){
			System.out.println("int : " + temp);	
		}
	}

	public static void main(String...args)
	{
		String []testArray = new String[] {new String("testOne"), new String("testTwo"), new String("testThree")};

		printStringArray(testArray);


		System.out.println("begin to print main args");

		printStringArray(args);

		Integer[]testIntArray = new Integer[]{1,2,3,5,6};

		printInteger(testIntArray);
	}
}
