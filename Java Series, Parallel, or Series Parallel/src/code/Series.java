package code;

/**
 * Class for to create series circuits
 * @author Joe
 *
 */
public class Series extends Super{

	private static String[] files = new String[] {"Series #1.png","Series #2.png","Series #3.png","Series #4.png","Series #5.png"};
	
	public Series (String x , int z){
		
		super ( x , files[z], 0);
		
	}
	
}
