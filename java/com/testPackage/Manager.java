package com.testPackage;

public class Manager extends Employee
{
	private double bonus = 0.0D;	

	public Manager(String _name, double _s, int _year, int _month, int _day)
	{
		super(_name, _s, _year, _month, _day);	

		System.out.println("construct in Manager");
	}

	public void setBonus(double b)
	{
		this.bonus = b;
	}

	public String getName()
	{
		System.out.println("getName in Manager");
		return super.getName();
	}

	public double getSalary()
	{
		System.out.println("getSalary in Manager");
		return bonus + super.getSalary();
	}	

	public void testPureFunction()
	{
		System.out.println("\n\n\n");
		System.out.println("just test pure function");	
		System.out.println("\n\n\n");
	}
}
