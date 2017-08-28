package code;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * Doesn't work for some odd reason
 */
public class ResultsClass extends JFrame{
	
		private JTextField[] answer1;
		private JTextField[] guesses1;

	
	public ResultsClass(int answers[], int guesses[]){
		
		super ("Results");
		setLayout(new FlowLayout());
				
		for (int i = 0; i < 5; ++i){
			
			String x;
			
			x = String.format("The answer was %s", answers[i]);
			
			answer1[i] = new JTextField(x,15);
			
			String z;
			
			z = String.format("The answer was %s", guesses[i]);
			
			guesses1[i] = new JTextField(z,15);
			
			add(answer1[i]);
			add(guesses1[i]);		
		}
		
	}

}
