package code;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * The super class with all the main code
 * @author Joe
 *
 */
public abstract class Super extends JFrame{

	private FlowLayout lay;
	
	private JButton series;
	private JButton parallel;
	private JButton sp;
	private JTextField text;
	private Icon pic;
	private JLabel picture;
	private static int rounds = 0;
	private int tipe;
	private static int score;
	public final int loops = 5;
	private int[] guess = new int[5];
	private int[] answer = new int[5];

	//private int deBug=0;
	
	public Super (String x, String filename, int type){
		
		super (x);
		lay = new FlowLayout();
		lay.setAlignment(lay.CENTER);
		setLayout(lay);
		
		answer[rounds] = type;
		tipe = type;
		
		pic = new ImageIcon(getClass().getResource(filename));
		picture = new JLabel();
		picture.setIcon(pic);
		add(picture);
		
		text = new JTextField("           Is this cirucit series, parallel, or series-parallel?", 30);
		text.setEditable(false);
		add(text);
		
		
		series = new JButton("Series");
		parallel = new JButton("Parallel");
		sp =  new JButton ("Series-Parallel");
		
		add(series);
		add(parallel);
		add(sp);
		
		action act = new action();
		
		series.addActionListener(act);
		parallel.addActionListener(act);
		sp.addActionListener(act);
		
	}
	
	private class action implements ActionListener{
		
		public void actionPerformed(ActionEvent event){
			if (event.getSource() == series || event.getSource() == parallel || event.getSource() == sp )
			{
				int z = 0;
				if (event.getSource() == series){
					z = 0;
					guess[rounds] = 0; 
				}
				
				else if (event.getSource() == parallel){
					z = 1;
					guess[rounds] = 1; 
				}
				else {
					z = 2;
					guess[rounds] = 2; 
				}
				
				if (tipe == z)
				{
					++score;
				}
				
				try {
				Thread.sleep(150);
				} 
				catch (InterruptedException e) {
				e.printStackTrace();
				}
				Super.this.dispose();
				
				++rounds;
				
				if (rounds >= loops){
					displayScore();
				}
					
						
			}
		}
		
	}
	
	public void displayScore(){
		JOptionPane.showMessageDialog(null, "You got " + (double)score/(double)rounds*100 + "% of the questions correct");
	}
	
	
	
}
