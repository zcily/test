package polymorphism.shape;

public class Circle extends Shape
{
	@Override
	public void draw()
	{
		System.out.println("draw in Circle");	
	}

	@Override
	public void erase()
	{
		System.out.println("erase in Circle");	
	}
}
