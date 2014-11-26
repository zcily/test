package testTwo;

public class ConnectionManager
{
	public static void main(String[] args)
	{
			
	} 

	private static int numOfConnection = 3;

	private static Connection[] cm = new Connection[3];

	static {
		for(Connection x : cm)	{
			x = Connection.makeConnection();				
		}
	}

	public ConnectionManager()
	{
		
	}

	public static Connection getConnect()
	{
		if( 0 == (numOfConnection--)){
			System.out.println("there is no connection");
			return null;	
		}else {
			return cm[numOfConnection];
		}
	}
}

class Connection
{
	private Connection()
	{
		System.out.println("construct in connection");	
	}

	static Connection makeConnection()
	{
		return new Connection();		
	}
}
