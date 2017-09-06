package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Main extends Application {

    private TextField f[][];

    @Override
    public void start(Stage primaryStage) throws Exception{
        primaryStage.setTitle("Grade Determiner");
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER);
        grid.setHgap(10);
        grid.setVgap(10);
        f = new TextField[1][3];

        Text title1 = new Text("Final Grade Calculator");
        title1.setFont(Font.font("Tahoma", FontWeight.LIGHT, 15));
        grid.add(title1, 0, 0, 3, 1);

        Label fin1 = new Label("Final Exam Percent");
        grid.add(fin1, 0, 1);
        Label fin2 = new Label("Desired final grade");
        grid.add(fin2, 1, 1);
        TextField fina1 = new TextField("Final Exam Weight");
        grid.add(fina1,0, 2);
        TextField fina2 = new TextField("Desired Final Grade");
        grid.add(fina2,1, 2);

        Label name1 = new Label("Catagory");
        grid.add(name1, 0, 3);
        Label name2 = new Label("Percent of Grade");
        grid.add(name2, 1, 3);
        Label name3 = new Label("Grade/Expected Grade");
        grid.add(name3, 2, 3);

        for(int i = 0; i < f[0].length; ++i) {
            f[0][i] = new TextField("");
            grid.add(f[0][i], i, 4);
        }

        Button btn = new Button("Add item");
        grid.add(btn, 2, 0, 2, 1);

        Button calc = new Button("Calculate");
        grid.add(calc, 0, f.length+4, 2, 1);

        btn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                TextField temp1[][] = f;
                f = new TextField[temp1.length+1][3];
                for(int i = 0; i < temp1.length; ++i){
                    f[i] = temp1[i];
                }
                for(int i = 0; i < f[0].length; ++i) {
                    f[temp1.length][i] = new TextField("");
                    grid.add(f[temp1.length][i], i, f.length+3);
                }
                try {
                    grid.add(calc, 0, f.length + 4);
                }
                catch (Exception IllegalArgumentException){
                }
            }
        });

        calc.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                GridPane grid2 = new GridPane();
                grid2.setAlignment(Pos.CENTER);
                grid2.setHgap(10);
                grid2.setVgap(10);
                Label a1 = new Label("Final Exam Grade");
                grid2.add(a1, 0, 0);
                Label a2 = new Label("Final Grade");
                grid2.add(a2, 1, 0);
                double[][] grades = new double[21][2];
                Label[][] stats = new Label[21][2];
                double partSum = 0;
                double needed = 0;

                for(int i = 0; i < f.length; ++i){
                    if(f[i][1].getText().compareTo("")==0)
                        break;
                    partSum += Double.parseDouble(f[i][1].getText())*Double.parseDouble(f[i][2].getText())/100;
                }

                needed = (Double.parseDouble(fina2.getText())-partSum)/Double.parseDouble(fina1.getText())*100;
                System.out.println(needed);
                Label need1 = new Label(Double.toString(needed));
                Label need2 = new Label(fina2.getText());
                need1.setTextFill(Color.RED);
                need2.setTextFill(Color.RED);
                int count = 0;
                boolean flag = true;
                for(int i = 0; i < grades.length; ++i){
                    grades[i][0]=100-5*i;
                    stats[i][0]=new Label(Double.toString(grades[i][0]));
                    grades[i][1]=partSum+grades[i][0]*Double.parseDouble(fina1.getText())/100;
                    stats[i][1]=new Label(Double.toString(grades[i][1]));
                    if(grades[i][0]<=needed&&flag){
                        grid2.add(need1,0,count+1);
                        grid2.add(need2,1,count+1);
                        ++count;
                        flag = false;
                    }
                    grid2.add(stats[i][0],0,count+1);
                    grid2.add(stats[i][1],1,count+1);
                    ++count;
                }

                Stage stage = new Stage();
                stage.setTitle("Final Grades");
                stage.setScene(new Scene(grid2, 450, 750));
                stage.show();
            }
        });

        primaryStage.setScene(new Scene(grid, 700, 500));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
