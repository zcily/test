import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.Timer;

public class TalkingClock
{	
	private int interval;
	private boolean beep;
	private Timer t;

	public static void main(String[] args)
	{
		System.out.println("init talk clock");

		TalkingClock tc = new TalkingClock(1 * 1000, true);

		tc.start(false);

		JOptionPane.showMessageDialog(null, "Quit program?");
		tc.stop();
		System.exit(0);
	}


	public TalkingClock(int interval, boolean beep)
	{
		this.interval = interval;		
		this.beep = beep;
	}

	public void start(boolean beep)
	{				
		class timePrinter implements ActionListener
		{
			public void actionPerformed(ActionEvent event)
			{
				if(!TalkingClock.this.beep)
					return;

				Date now = new Date();	
				System.out.println("At the tone, the time is " + now + "   " + beep);
				Toolkit.getDefaultToolkit().beep();
			}
		}

		System.out.println("start to exec timer");

		ActionListener listener = new timePrinter();
		t = new Timer(1 * 1000, listener);

		t.start();
	}

	public void stop()
	{
		t.stop();	
	}
}
