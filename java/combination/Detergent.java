package combination;

class Cleanser
{
	private String s = "Cleanser : ";
	protected void append(String newAdd){
		s += newAdd;	
	}

	public void dilute(){append(" dilute() ");}
	public void apply() {append(" apply() ");}
	public void scrub() {append(" scrub() ");}
	public String toString() {return s;}

	public static void main(String[] args){
		Cleanser x = new Cleanser();	
		x.dilute();
		x.apply();
		x.scrub();

		System.out.println(x);
	}
}

class root
{
	private String name = new String("defalut");

	private static A ttt = new A("Root A static");
	private B tttb = new B("Root B non static ");

	public root()
	{
		System.out.println("construct in root");	
	}

	public root(int i)
	{
		System.out.println("construct in root by i : " + i);	
	}

	public String showInfo(root rt)
	{
		System.out.println("root name : " + rt);	
		return name;
	}

	public void setName(final String newName)
	{
		this.name = newName;	
	}

	protected void test()
	{
	
	}

	public String toString()
	{
		return name;	
	}
}

class testRoot extends root
{
	private static A tt = new A("test Root A static");
	private B ttb = new B("test Root B non static ");

	public static void main(String[] args)
	{
		/*
		root t = new root(1);	
		t.showInfo(t);
		t.setName("new root in testroot main");	
		t.showInfo(t);
*/
		System.out.println("begin in main");
		testRoot tr = new testRoot();

		root rt = new root();
		System.out.println("end in main");

//		t.showInfo(tr);
	}

	public void testDownCall()
	{
		System.out.println("just test call down");	
	}

	public testRoot()
	{
		super();
		System.out.println("construct in test root");	
	}

	public testRoot(int i)
	{
		super(1);
		System.out.println("construct in test root by i : " + i);	
	}

	@Override
	protected void test()
	{
	}
}

public class Detergent extends Cleanser
{
	public void scrub(){
		append(" Detergent.scrub() ");
		super.scrub();
	}

	public void foam() {
		append(" foam() ");	
	}

	public static void main(String[] args)
	{
		Cleanser x = new Detergent();	

		x.dilute();
		x.apply();
		x.scrub();
		((Detergent)x).foam();

		System.out.println(x);

		System.out.println("test C");

		C c = new C(1);
	}
}

class A
{
	public A()
	{
		System.out.println("construct in A");	
	}

	public A(int i)
	{
		System.out.println("construct in A by i : "  + i);	
	}

	public A(String name)
	{
		System.out.println("construct in A by name : "  + name);	
	}
}

class B
{
	public B()
	{
		System.out.println("construct in B");	
	}

	public B(int i )
	{
		System.out.println("construct in B by i : "  + i);	
	}

	public B(String name)
	{
		System.out.println("construct in B by name : "  + name);	
	}

	protected void tt()
	{	
	}
}


class C extends A
{
	private static B testb = new B();

	public C()
	{
		super(1);
		System.out.println("construct in C");	
		testb.tt();
	}

	public C(int i)
	{
		super(1);
		System.out.println("construct in C by i : " + i);	
	}
}
