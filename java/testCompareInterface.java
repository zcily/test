import com.testPackage.Employee;
import com.myInterface.testInterface;
import java.util.Arrays;

public class testCompareInterface implements testInterface<Employee>
{
	public static void main(String[] args)
	{	
		Employee[] staff = new Employee[3];
		staff[0] = new Employee("zhang", 175000, 1989, 12, 15); 
		staff[1] = new Employee("wu", 95000, 1989, 12, 15);
		staff[2] = new Employee("yi", 105000, 1989, 12, 15);

		Arrays.sort(staff);


		for( Employee temp : staff){
			temp.raiseSalary(20);
			System.out.println("name : " + temp.getName() 
					+ " , salary : " + temp.getSalary()
					+ " , hireDay : " + temp.getHireday());
		}

		System.out.println("name : " + staff[0].getName() 
				+ " , salary : " + staff[0].getSalary()
				+ " , hireDay : " + staff[0].getHireday());

		Employee temp = staff[0];

		temp.setName("test zhang");


		System.out.println("after set name \n\n");
		System.out.println("name : " + staff[0].getName() 
				+ " , salary : " + staff[0].getSalary()
				+ " , hireDay : " + staff[0].getHireday());

		System.out.println("name : " + temp.getName() 
				+ " , salary : " + temp.getSalary()
				+ " , hireDay : " + temp.getHireday());
		System.out.println("after set name \n\n");


		System.out.println("use  clone !!!!");

		Employee temp2;
		try {
			temp2 = staff[0].clone();
			temp2.setName("test 222 zhang");

			System.out.println("name : " + temp2.getName() 
					+ " , salary : " + temp2.getSalary()
					+ " , hireDay : " + temp2.getHireday());


			System.out.println("name : " + staff[0].getName() 
					+ " , salary : " + staff[0].getSalary()
					+ " , hireDay : " + staff[0].getHireday());

			System.out.println("after set name \n\n");


		}catch(CloneNotSupportedException e){
			System.out.println("" + e.toString());	
		}
	}	

	public void justTestInterface()
	{
		System.out.println("just test interface");	
	}
}
