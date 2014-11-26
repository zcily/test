import com.testPackage.Employee;
import com.testPackage.Manager;
import java.util.Date;
import java.util.GregorianCalendar;

public class time
{
	public static void main(String[] args)
	{
		Date newTime = new Date();	

		String time = newTime.toString();

		System.out.println("the time is : " + time);


		Employee[] staff = new Employee[1];
		staff[0] = new Manager("zhang", 75000, 1989, 12, 15); 
		//staff[1] = new Employee("wu", 95000, 1989, 12, 15);
		//staff[2] = new Employee("yi", 105000, 1989, 12, 15);


		for( Employee temp : staff){
			temp.raiseSalary(20);
			System.out.println("name : " + temp.getName() 
						+ " , salary : " + temp.getSalary()
						+ " , hireDay : " + temp.getHireday());
		}

		//staff[0].testPureFunction();

		Manager ol = new Manager("zhangwuyi", 17000, 1989, 5, 1);

		System.out.println("manager name : " + ol.getName());
	}
}
