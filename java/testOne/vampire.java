package testOne;

import java.util.Arrays;

public class vampire
{
	public static void main(String[] args)	
	{
		System.out.println("find vampire number: ");	

		getVampire();
	}
	

	public static void getVampire()
	{
		String[] value1, value2;
		int sum = 0;
		int from = 0;
		int to = 0;
		int countFind = 0;
		int countFinal = 0;

		int j = 0;

		for(int i = 10; i < 100; ++i){				
			from = i + 1;
			to = 100;

			for(j = from; j < to; ++j){
				sum = i * j;	

				if(sum % 100 == 0 || (sum - i - j) % 9 != 0)
					continue;

				countFind++;

				value1 = String.valueOf(sum).split("");
				value2 = (String.valueOf(i) + String.valueOf(j)).split("");
				Arrays.sort(value1);
				Arrays.sort(value2);

				if (Arrays.equals(value1, value2)) {// 排序后比较,为真则找到一组
					countFinal++;
					System.out.println("第" + countFinal+ "组: " + i + "*" + j + "=" + sum);
				}

			}
		}
	}
}
