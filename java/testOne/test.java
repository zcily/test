package testOne;

import java.lang.Math;
import java.util.Random;

public class test
{
	public static void main(String[] args)
	{
		/*
		A temp = new A();	

		System.out.println("a : " + temp.a + "  b : *" + temp.b+"");

		for(String ts : args) {
			System.out.println("args : " + ts);	
		}

		for(int i = 0; i < args.length; ++i){
			System.out.printf("args[%d] : %s\n", i, args[i]);	
		}

		Dog spot = new Dog("spot", "Ruff!!");
		Dog scruffy = new Dog("scruffy", "Wurf!!");

		spot.says();
		scruffy.says();

		Dog a = spot;

		a.says();

		a.setName("Tom");
		a.setSpeaks("WoW!!!");

		a.says();
		spot.says();
		*/

		/*
		Random random = new Random();

		double[] dArray = new double[25];

		dArray[0] = random.nextDouble() * 100;
tt:

		for(int i = 1; i < dArray.length; ++i){
			dArray[i] = random.nextDouble() * 100;

			if(i == 5)
				break tt;
			System.out.println(i + " : " + dArray[i]);
		}
		System.out.println("goto before");
		System.out.println("goto end");
		*/

		/*
		if(args.length != 1)
			return;

		int []fib = new int[100];

		fib[0] = 1;
		fib[1] = 1;
		System.out.print("" + fib[0] + " " + fib[1] + " ");
		for(int i = 2; i < Integer.parseInt(args[0]); ++i){
			fib[i] = fib[i - 1] + fib[i - 2];
			System.out.print(fib[i] + " ");
		}

		System.out.println("");
		*/


	}
}

class Dog
{
	private String name;
	private String speaks;

	public Dog(String name, String says)
	{
		this.name = name;	
		this.speaks = says;
	}

	public void setName(final String name)
	{
		this.name = name;	
	}

	public void setSpeaks(final String speaks)
	{
		this.speaks = speaks;
	}

	public String says()
	{
		System.out.println(name + "  : " + this.speaks);
		return this.speaks;	
	}
}

class A
{
	public A()
	{
		System.out.println("new construct about a by defalut");	
	}
	int a;
	char b;
}
