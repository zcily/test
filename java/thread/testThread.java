package thread;


public class testThread
{
	public static void main(String[] args)
	{
/*
 * use only thread
		MyThreadWithThread test1 = new MyThreadWithThread("thread one");	
		MyThreadWithThread test2 = new MyThreadWithThread("thread two");	


		test1.start();
		test2.start();
*/
	    MyThreadWithRunnable test1 = new MyThreadWithRunnable("thread one");
	    MyThreadWithRunnable test2 = new MyThreadWithRunnable("thread two");

		Thread t1 = new Thread(test1);
		Thread t2 = new Thread(test1);

		t1.start();
		t2.start();
	}
}

class MyThreadWithThread extends Thread
{
	private String name;
	private int num = 200;

	public MyThreadWithThread(String name){
		super();	
		this.name = name;
	}


	public void run(){
		for(int i = 0; i < 100; ++i)	{
			System.out.println("the thread : " + this.name + " , i = " + i +  " num = " + (num--));	
		}
	}
}

class MyThreadWithRunnable implements Runnable
{
	private String name;
	private int num = 200;

	public MyThreadWithRunnable(String name){
		super();	
		this.name = name;
	}

	public void run()
	{
		for(int i = 0; i < 100; ++i)	{
			synchronized(this){
				System.out.println("the thread : " + this.name + " , i = " + i + " num = " + (num--));	
			}
		}
	}
}
