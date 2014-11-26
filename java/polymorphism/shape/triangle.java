package polymorphism.shape;

public class triangle extends Shape
{
	@Override
	public void draw()
	{
		System.out.println("draw in Triangle");	
	}

	@Override
	public void erase()
	{
		System.out.println("erase in Triangle");	
	}
}
