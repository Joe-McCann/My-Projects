package code;

import java.util.Random;

import javax.swing.JFrame;

public class Driver {

	/**
	 * The Driver for the circuit thing
	 */
	public static void main(String[] args) {
		
		int x;
		int z;
	
		Random rand = new Random();
		
		Super circuit;
		
		for (int i = 0; i < 5; ++i){
			
			x = rand.nextInt();
			x %= 3;
			x = Math.abs(x);
			
			z = rand.nextInt();
			z %= 5;
			z = Math.abs(z);
		
			if ( x == 0 ) 
				circuit = new Series("Question #" +Math.abs((i+1) - 6), z);
			
			else if ( x == 1 ) 
				circuit = new Parallel("Question #" +Math.abs((i+1) - 6), z);
		
			else 
				circuit = new Series_Parallel("Question #" +Math.abs((i+1) - 6), z);
		
			circuit.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			circuit.setSize(420, 500);
			circuit.setVisible(true);
			
			
			
		}
	
		
	}

}



