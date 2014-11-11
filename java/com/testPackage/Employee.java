package com.testPackage;

import java.util.*;

public abstract class Employee
{
	private String name;
	private double salary;
	private Date hireDay;
	public static final double PI = 3.141592653;

	public Employee(String _name, double _s, int _year, int _month, int _day)
	{
		System.out.println("construct in Employee");
		name = _name;	
		salary = _s;
		GregorianCalendar calendar = new GregorianCalendar(_year, _month - 1, _day);
		hireDay = calendar.getTime();
	}

	public abstract void testPureFunction();

	public double raiseSalary(int percent)
	{
		this.salary += (double)(this.salary * percent) / 100.0;	
		System.out.println("raiseSalary in Employee");
		return this.salary;
	}

	public void setName(String newName)
	{
		this.name = newName;	
	}

	public String getName()
	{
		System.out.println("getName in Employee");
		return name;
	}

	public double getSalary()
	{
		System.out.println("getSalary in Employee");
		return salary;
	}

	public Date getHireday()
	{
		System.out.println("getHireday in Employee");
		return hireDay;
	}

	public static void main(String[] args)
	{
		System.out.println("just to test employee");	
		//Employee temp = new Employee("zwy", 9999999, 1989, 5, 1);
	}
}


