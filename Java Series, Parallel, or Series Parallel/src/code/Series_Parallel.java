package code;

/**
 * Creates series-parallel circuits
 * @author Joe
 *
 */
public class Series_Parallel extends Super{
	
	private static String[] files = new String[] {"SP #1.png","SP #2.png","SP #3.png","SP #4.png","SP #5.png"};
	
	public Series_Parallel (String x , int z){
		
		super ( x , files[z], 2);
		
	}
}
