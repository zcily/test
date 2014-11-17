package logger;

import java.util.logging.*;

public class testLogger
{
	public static void main(String[] args)
	{
		Logger.getGlobal().info("just test how to user logger one");

		Logger.getGlobal().setLevel(Level.OFF);

		Logger.getGlobal().info("just test how to user logger two");

		Logger.getGlobal().setLevel(Level.ALL);

		Logger.getGlobal().info("just test how to user logger three");
	}
}
