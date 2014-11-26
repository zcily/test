public class myEnum
{	
	public enum color{
		BLUE
		RED,
		YELLOW,
		GREEN
	};

	public static void main(String[] args)
	{

		for(color temp : color.values()){
			System.out.println("the color : " + temp);	
		}
	}
}
