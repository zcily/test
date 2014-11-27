package com.innerClass;

interface Selector
{
	boolean end();
	Object current();
	void next();
}

class Sequence
{
	private Object[] items;	
	private int index = 0;

	public Sequence()
	{
		items = new Object[1];	
	}

	public Sequence(int number)
	{
		items = new Object[number];
	}

	public boolean add(Object newObject)
	{
		if(index < items.length)
		{
			items[index++] = newObject;
			return true;
		}
		System.out.println("the sequence is full!!!!");
		return false;
	}

	public class selectorP implements Selector
	{
		private int i = 0;

		public boolean end()
		{
			return i == items.length;		
		}

		public Object current()
		{
			return items[i];
		}

		public void next()
		{
			if(i < items.length) ++i;
		}

		public Sequence getOutter()
		{
			return Sequence.this;	
		}
	}

	static class testStaticInnerClass
	{
	
	}

	public Selector getSelector()
	{
		return new selectorP();
	}
}

interface Contents
{
	void showInfo();
}

class testNoNameClass
{
	public Contents getContents()
	{
		return new Contents() {
				private int i = 1;	
				public void showInfo()
				{
					System.out.println("this is in the no name class");	
				}
		};
	}

	public static void main(String[] args)
	{
		testNoNameClass tnnc = new testNoNameClass();	

		Contents ctts = tnnc.getContents();

		ctts.showInfo();
	}
}

class testPrivateAboutInnerClass
{
	private String name = "default";
	
	private String getName()
	{
		return this.name;	
	}

	private void showInfo()
	{
		System.out.println("in outter class name : " + this.name);	
	}

	class inPrivateInnerClass
	{
		public inPrivateInnerClass()	
		{
			System.out.println("name : " + getName());
		}

		public void showInfoFromInnerClass()
		{
			showInfo();	
		}
	}

	public inPrivateInnerClass getInnerTest()
	{
		return new inPrivateInnerClass();	
	}
}

public class Outer
{
	private static Inner innerClass;

	private static class Inner
	{
		public Inner()
		{
			System.out.println("construct in inner class");	
		}

		public void showInfo()
		{
			System.out.println("this is in the inner class");	
		}
	}

	public static Inner getInnerClass()
	{
		if(null == innerClass)
			innerClass = new Inner();

		return innerClass;
	}

	public static void main(String[] args)
	{
		/*
		 *for test innner class 
		Inner in = getInnerClass();				

		in.showInfo();
		*/

		/*
		Sequence newSq = new Sequence(10);

		for(int i = 0; i < 10; ++i)
		{
			newSq.add("item" + i);
		}

		Selector st = newSq.getSelector();

		Sequence nsq = ((Sequence.selectorP)st).getOutter();
		nsq.add("a");
		nsq.add("b");

		for(; !st.end(); st.next()){
			System.out.println(st.current());	
		}
		*/

		/*
		testPrivateAboutInnerClass tpai = new testPrivateAboutInnerClass();
		testPrivateAboutInnerClass.inPrivateInnerClass tt = tpai.getInnerTest();

		tt.showInfoFromInnerClass();
		*/
	}
}
