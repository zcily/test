package com.testPackage;

import java.util.*;

public class Employee
{
	private String name;
	private double salary;
	private Date hireDay;
	public static final double PI = 3.141592653;

	{
		System.out.println("test for initialization block");	
	}

	{
		System.out.println("the second initialization block");	
	}

	public Employee(String _name, double _s, int _year, int _month, int _day)
	{
		name = _name;	
		salary = _s;
		GregorianCalendar calendar = new GregorianCalendar(_year, _month - 1, _day);
		hireDay = calendar.getTime();
	}

	public double raiseSalary(int percent)
	{
		this.salary += (double)(this.salary * percent) / 100.0;	

		return this.salary;
	}

	public String getName()
	{
		return name;
	}

	public double getSalary()
	{
		return salary;
	}

	public Date getHireday()
	{
		return hireDay;
	}

	public static void main(String[] args)
	{
		System.out.println("just to test employee");	
		Employee temp = new Employee("zwy", 9999999, 1989, 5, 1);
	}
}


