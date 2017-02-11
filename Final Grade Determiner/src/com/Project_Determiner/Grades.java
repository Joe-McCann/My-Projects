package com.Project_Determiner;
import javax.swing.*;
import javax.swing.table.JTableHeader;
import javax.swing.table.TableCellRenderer;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.text.DecimalFormat;

/**
 * Created by Joe on 5/6/2015.
 */
public class Grades extends JFrame{

    DecimalFormat fmt;
    private JTextField mp1;
    private JTextField mp2;
    private JTextField mp3;
    private JTextField mp4;
    private JTextField dfg;
    private JButton calc;
    private double a1;
    private double a2;
    private double a3;
    private double a4;
    private double adfg;

    public Grades(){
        super("The Final Challenge");
        setLayout(new FlowLayout());

        fmt = new DecimalFormat("0.##");

        thehandlers handle = new thehandlers();
        themousehandle mousehandle = new themousehandle();

        mp1 = new JTextField("First Marking Period Average: ", 30);
        mp2 = new JTextField("Second Marking Period Average: ", 30);
        mp3 = new JTextField("Third Marking Period Average", 30);
        mp4 = new JTextField("Estimated Fourth Marking Period Average", 30);
        dfg = new JTextField("Desired Final Grade", 30);

        mp1.addMouseListener(mousehandle);
        mp2.addMouseListener(mousehandle);
        mp3.addMouseListener(mousehandle);
        mp4.addMouseListener(mousehandle);
        dfg.addMouseListener(mousehandle);

        add(mp1);
        add(mp2);
        add(mp3);
        add(mp4);
        add(dfg);

        a1 = a2 = a3 = a4 = 0;

        calc = new JButton("Calculate");
        add(calc);
        calc.addActionListener(handle);

    }

    private class themousehandle implements MouseListener{

        public void mouseClicked(MouseEvent event){}

        public void mouseEntered(MouseEvent event){
            if (event.getSource() == mp1){
                mp1.requestFocusInWindow();
                mp1.selectAll();
            }

            else if (event.getSource() == mp2){
                mp2.requestFocusInWindow();
                mp2.selectAll();
            }

            else if (event.getSource() == mp3){
                mp3.requestFocusInWindow();
                mp3.selectAll();
            }

            else if (event.getSource() == mp4){
                mp4.requestFocusInWindow();
                mp4.selectAll();
            }

            else if (event.getSource() == dfg){
                dfg.requestFocusInWindow();
                dfg.selectAll();
            }
        }

        public void mouseExited(MouseEvent event){
            if (event.getSource() == mp1){
                mp1.requestFocusInWindow();
                mp1.setSelectionEnd(0);
            }

            else if (event.getSource() == mp2){
                mp2.requestFocusInWindow();
                mp2.setSelectionEnd(0);
            }

            else if (event.getSource() == mp3){
                mp3.requestFocusInWindow();
                mp3.setSelectionEnd(0);
            }

            else if (event.getSource() == mp4){
                mp4.requestFocusInWindow();
                mp4.setSelectionEnd(0);
            }

            else if (event.getSource() == dfg){
                dfg.requestFocusInWindow();
                dfg.setSelectionEnd(0);
            }
        }

        public void mousePressed(MouseEvent event){}

        public void mouseReleased(MouseEvent event){}
    }

    private class thehandlers implements ActionListener{

        public void actionPerformed(ActionEvent event){

            if (event.getSource() == calc) {
                mp1.requestFocusInWindow();
                mp1.selectAll();
                a1 = Double.parseDouble(mp1.getText());
                a2 = Double.parseDouble(mp2.getText());
                a3 = Double.parseDouble(mp3.getText());
                a4 = Double.parseDouble(mp4.getText());
                adfg = Double.parseDouble(dfg.getText());

                double sum = (a1 + a2 + a3 + a4) * .2;

                calcWindow calc = new calcWindow(sum, adfg);
                calc.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                calc.setSize(200, 450);
                calc.setVisible(true);

            }

        }

    }

    private class calcWindow extends JFrame{

        private JTable chart;
        private JTableHeader header;
        private JPanel panel;
        private double[] grades;
        private double[] endGrades;
        private Object[] columns;
        private Object[][] rows;
        private int theRow;

        public calcWindow(double sum, double wish){

            super("your Endgame");
            setLayout(new FlowLayout());

            double endWish = (wish - sum) * 5;
            int loop = 0;
            theRow = 0;

            grades = new double[7];
            endGrades = new double[7];
            rows = new Object[7][2];
            columns = new Object[2];
            columns[0] = "Exam Grade";
            columns[1] = "Final Grade";

            for (int i = 0; i < 7; ++i) {

                if ((100 - 10 * (i)) < endWish && loop == 0){
                    rows[i][0] = fmt.format(endWish);
                    rows[i][1] = fmt.format(wish);
                    loop = 1;
                    theRow = i;
                }

                else {
                    grades[i - loop] = 100 - 10 * (i - loop);
                    endGrades[i - loop] = sum + (100 - 10 * (i - loop)) * .2;
                    rows[i][0] = fmt.format(grades[i - loop]);
                    rows[i][1] = fmt.format(endGrades[i - loop]);
                }
            }


            chart = new JTable(rows, columns);
            chart.setDefaultRenderer(Object.class, new MyRendered());
            chart.setRowHeight(50);
            header = new JTableHeader();
            panel = new JPanel();
            header = chart.getTableHeader();
            panel.setLayout(new BorderLayout());
            panel.add(header, BorderLayout.NORTH);
            panel.add(chart, BorderLayout.SOUTH);
            add(panel);

        }

        private class MyRendered implements TableCellRenderer{

            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected,
                                                           boolean hasFocus, int row, int column) {
                JTextField editor = new JTextField();
                if (value != null) {
                    editor.setText(value.toString());
                }
                editor.setBackground(Color.WHITE);
                editor.setForeground((row == theRow) ? Color.MAGENTA : Color.BLACK);
                editor.setFont(new Font("Serif", Font.PLAIN, 16));
                return editor;
            }

        }

    }

}
