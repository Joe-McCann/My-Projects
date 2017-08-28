package code;

/**
 * Creates parallel circuits
 * @author Joe
 *
 */
public class Parallel extends Super{
	
	private static String[] files = new String[] {"Parallel #1.png", "Parallel #2.png", "Parallel #3.png", "Parallel #4.png", "Parallel #5.png"};
	
	public Parallel (String x , int z){
		
		super ( x , files[z], 1);
		
	}

}
