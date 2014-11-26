package polymorphism.shape;

public class Square extends Shape
{
	@Override
	public void draw()
	{
		System.out.println("draw in Square");	
	}

	@Override
	public void erase()
	{
		System.out.println("erase in Square");	
	}
}
