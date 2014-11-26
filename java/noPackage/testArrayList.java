import java.util.*;
import com.testPackage.*;
import java.lang.reflect.*;

public class testArrayList
{
	public static void main(String[] args)
	{
		System.out.println("just test array list use");
		ArrayList<Employee> staff = new ArrayList<Employee>(10);
		System.out.println("before add the arraylist of employee size is : " + staff.size());
		staff.add(new Employee("zhang", 75000, 1989, 12, 15)); 
		staff.add(new Employee("zhang", 75000, 1989, 12, 15)); 
		staff.add(new Employee("zhang", 75000, 1989, 12, 15)); 
		staff.add(new Employee("zhang", 75000, 1989, 12, 15)); 
		staff.add(new Employee("zhang", 75000, 1989, 12, 15)); 

		System.out.println("after add the arrlist of employee size is : " + staff.size());

		staff.trimToSize();

		System.out.println("after trimToSize the size is : " + staff.size());

		ArrayList<Integer> test = new ArrayList<Integer>(100);

		System.out.println("the class name : " + staff.get(1).getClass().getName());
/*
	public String getName()
*/
		try{
			Class c = Class.forName("com.testPackage.Employee");

			Method m[] = c.getDeclaredMethods();

			for(Method temp : m){
				System.out.println("" + temp.toString());	
			}
				
			Employee emp = new Employee();

			//为空参数时处理。
			Class partypes[] = new Class[0];
			Method meth = c.getMethod("getName", partypes);

			//为空参数时处理。
			Object arglist[] = new Object[0];

			Object retobj = meth.invoke(emp, arglist);

			String retval = (String)retobj;

			System.out.println("the retval is : " + retval);

		}catch(Throwable e){
			System.out.println(e);	
		}
	}


	public static int add(int...args)
	{
		int sum = 0;
		for(int i = 0; i < args.length; ++i){
			System.out.printf("the args[%d] : %d\n", i, args[i]);	
			sum += args[i];
		}
		System.out.printf("the sum is : %d\n", sum);

		return sum;
	}
}
