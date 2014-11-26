package polymorphism.shape;

import java.util.*;


class base
{
	public void fc()
	{
		System.out.println("call in fc");
		fbc();
	}

	public void fbc()
	{
		System.out.println("call in fbc with base");
	}
}

class child extends base
{
	public void fbc()
	{
		System.out.println("call in fbc with child");	
	}

	public static void testCall(base bs)
	{
		bs.fc();
	}

	public static void main(String[] args)
	{
		child cl = new child();			

		testCall(cl);
	}
}


public class RandomShapeGenerator
{
	public static RandomShapeGenerator gen = new RandomShapeGenerator();
	private Random rand = new Random(47);

	public Shape next(){
		Shape temp = null;
		switch(rand.nextInt(3))	
		{
			case 0 :
				temp = new Circle();
				break;
			case 1 :
				temp = new Square();
				break;
			case 2 :
				temp = new triangle();
				break;
		}

		return temp;
	}

	public static void main(String[] args)
	{
		Shape[] s = new Shape[9];

		for(int i = 0; i < s.length; ++i){
			s[i] = gen.next();
		}

		for(Shape shp : s){
			shp.draw();		
		}
	}
}
