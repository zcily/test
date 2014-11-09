import java.math.*;
import java.util.*;

public class test
{
	final static double CM_PER_INCH = 2.54D;	
	public static void main(String[] args)
	{	
		double paperWidth = 8.5;
		double paperHeight = 11;

		System.out.println("Paper size in centimeters : " 
				+ paperWidth * CM_PER_INCH +  " by " + paperHeight * CM_PER_INCH); 

		String temp = "abcdefghijklmnopqrstuvwxyz";

		System.out.println("substring (1, 2) : " + temp.substring(0,5));

		String tempEmpty = "";
		String tempNull = null;

		System.out.println("*************  " + tempEmpty.equals("") + "    ***   " +  tempEmpty.equals(null) + "  length  :  " + tempEmpty.length());

		if(tempEmpty.equals("")) {
			System.out.println("is the empty string");	
		}

		if(tempEmpty.equals(null)){
			System.out.println("is the null string");	
		}


		System.out.println("*************************** use StringBuilder");

		StringBuilder builder = new StringBuilder();

		builder.append("a");
		builder.append("d");

		String completedString = builder.toString();

		System.out.println("***************  completedString : " + completedString);

		System.out.println("************************* test about system.in");

		Scanner in = new Scanner(System.in);

		/*
		System.out.println("what your name");
		String name = in.nextLine();
		System.out.println("you name is : " + name);

		System.out.println("How old are you");
		int age = in.nextInt();
		System.out.println("you age is : " + age);
		
		System.out.println("How many number do you need to choose");
		int allNumber = in.nextInt();

		System.out.println("The most number need to use");
		int cNumber = in.nextInt();

		BigInteger lotteryOdds = BigInteger.valueOf(1);

		for(int i = 1; i <= allNumber; ++i){
			lotteryOdds = lotteryOdds.multiply(BigInteger.valueOf(cNumber - i + 1)).divide(BigInteger.valueOf(i));
		}

		System.out.println("Your odds is  " + lotteryOdds);


		System.out.println("args length  : " + args.length);
		*/

		System.out.println("2/3 = " + 2/3 + " 3/2 = " + 3/2 + " 4*(4 - 2 + 1) / 2 = " + 4 * (4 - 2 + 1) / 2);

		final int NMAX = 10;
		int[][] TwoArrays = new int[NMAX][];

		for(int i = 0; i < NMAX; ++i){
			TwoArrays[i] = new int[i + 1];

			//for(int j = 0; j < i + 1; ++j){
			//	TwoArrays[i][j] = 1;
			//}
		}


		for(int n = 0; n < TwoArrays.length; ++n){
			for(int k = 0; k < TwoArrays[n].length; ++k){
				int lotteryOdds = 1;	

				for(int i = 1; i <= k; ++i){
					if(n == 4 ){
						System.out.print("before i : " + i + "  k  : " + k);
						System.out.println("before lotteryOdds : " + lotteryOdds);
					}

					lotteryOdds = lotteryOdds * (n - i + 1)	 / i;

					if(n == 4 ){
						System.out.print("after i : " + i + "  k  : " + k);
						System.out.println("after lotteryOdds : " + lotteryOdds);
					}
				}

				TwoArrays[n][k] = lotteryOdds;
			}
		}

		for(int []tempArray : TwoArrays){
			for(int tempValue : tempArray){
				System.out.print(tempValue + " ");
			}
			System.out.println("");
		}
	}
}
