public class staticInnerClass
{
	public static void main(String[] args)
	{
		double values[] = new double[]{20,35,134,513,56131,3,134,561,1};

		Pair temp = Pair.minmax(values);

		System.out.println("the min value : " + temp.getFisrt());
		System.out.println("the max value : " + temp.getSecond());
	}


	public static class Pair
	{
		private double first;
		private double second;

		public Pair(double first, double second)
		{
			this.first = first;	
			this.second = second;
		}

		public double getFisrt()
		{
			return this.first;	
		}

		public double getSecond()
		{
			return this.second;	
		}

		public static Pair minmax(double[] arrays)
		{
			double min = arrays[0];
			double max = arrays[0];

			for(double value : arrays)	{
				if(value > max) max = value;
				if(value < min) min = value;
			}

			return new Pair(min, max);
		}
	}
}
