package genericFunction;

import java.util.logging.*;

public class testGeneric
{
	public static void main(String[] args)
	{
		Logger.getGlobal().info("this is test generic function");

		String []array = new String[]{"a", "b", "c", "d", "e"};
		String midArray  = Pair.<String>getMiddle(array);

		Logger.getGlobal().info("the midde array is : " + midArray);

		Pair<String> mm = Pair.<String>minmax(array);

		Logger.getGlobal().info("the array min : " + mm.getFirst() + "   max : " + mm.getSecond());

		Pair<Double> temp = new Pair<Double>();

	}
}

class Pair<T>
{
	private T first;
	private T second;

	public Pair()
	{
		first = null;	
		second = null;
	}

	public Pair(T first, T second)
	{
		this.first = first;	
		this.second = second;
	}

	public T getFirst()
	{
		return this.first;	
	}

	public T getSecond()
	{
		return this.second;	
	}

	public void setFirst(T newFisrt)
	{
		this.first = newFisrt;	
	}

	public void setSecond(T newSecond)
	{
		this.second = newSecond;	
	}

	public static <T> T getMiddle(T[] array)
	{
		return array[array.length / 2];
	}

	public static <T extends Comparable> Pair<T> minmax(T[] array)
	{
		T min =	array[0];
		T max = array[0];

		for(int i = 1; i < array.length; ++i){
			if(min.compareTo(array[i]) > 0) min = array[i];
			else if(max.compareTo(array[i]) < 0) max = array[i];
		}

		return new Pair<T>(min, max);
	}
}

