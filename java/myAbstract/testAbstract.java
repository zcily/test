package myAbstract;

abstract class myAbstractClass
{
	protected String name = "default";

	public myAbstractClass()
	{
		System.out.println("in the base abstract class");
		showinfo();	
		System.out.println("end in the base abstract class");
	}

	public abstract void showinfo();
	protected abstract void setName(final String name);

	public static void test(final myAbstractClass f)
	{
		System.out.println("in static test");
		f.showinfo();		
	}
}

class tt extends myAbstractClass
{
	public void showinfo()
	{
		name = "zwy";
		System.out.println("the name : " + super.name);			
	}

	public void setName(final String name)
	{
		super.name = name;	
	}

	public String getName()
	{
		return super.name;	
	}
}

interface Instrument 
{
	int VALUE = 3;

	void adjust();
}

interface PlayAble
{
	void play(int i);
}

interface playSame
{
	void play(int i);
}

class testInterface implements Instrument, PlayAble, playSame
{	
	public void adjust()
	{
		System.out.println("in the testInterface adjust()");	
	}

	public void play(int i)
	{
		System.out.println("in the implements interface i : " + i);	
	}
}

public class testAbstract
{
	public static String testBaseClassPre(myAbstractClass mac)
	{
		return ((tt)mac).getName();	
	}

	public static void testIf(PlayAble t)
	{
		t.play(11);	
	}

	public static void main(String[] args)
	{
		/*
		tt at = new tt();	
		myAbstractClass.test(at);
		at.setName("john");
		System.out.println("out : " + testAbstract.testBaseClassPre(at));
		*/
		testInterface it = new testInterface();

		testAbstract.testIf(it);
	}
}
