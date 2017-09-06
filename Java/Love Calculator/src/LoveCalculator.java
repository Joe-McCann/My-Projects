/**
 * Created by Joe on 2/16/2017.
 */

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;

public class LoveCalculator extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Calculations calc = new Calculations();
        primaryStage.setTitle("Love Calculator");
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER);
        grid.setHgap(10);
        grid.setVgap(10);

        Text title1 = new Text("Dr. Joe Presents");
        title1.setFont(Font.font("Tahoma", FontWeight.LIGHT, 15));
        grid.add(title1, 0, 0, 1, 1);

        Text title2 = new Text("The Love Calculator");
        title2.setFont(Font.font("Tahoma", FontWeight.BOLD, 30));
        title2.setTextAlignment(TextAlignment.CENTER);
        grid.add(title2, 0, 1, 3, 2);

        Label name1 = new Label("Name:");
        grid.add(name1, 0, 3);

        Label name2 = new Label("Name:");
        grid.add(name2, 2, 3);

        TextField f1 = new TextField("Name");
        grid.add(f1, 0, 4);

        TextField f2 = new TextField("Name");
        grid.add(f2, 2, 4);

        Label cn = new Label("Couple Name:");
        HBox hb2 = new HBox();
        hb2.setAlignment(Pos.CENTER);
        hb2.getChildren().add(cn);
        grid.add(hb2, 0, 5, 3, 1);

        TextField f3 = new TextField("Couple Name:");
        HBox hb3 = new HBox();
        hb3.setAlignment(Pos.CENTER);
        hb3.getChildren().add(f3);
        grid.add(hb3, 0, 6, 3, 1);

        Button btn = new Button("Calculate Love");
        grid.add(btn, 0, 7, 2, 1);

        Label love = new Label();
        HBox hb = new HBox();
        hb.setAlignment(Pos.BOTTOM_CENTER);
        hb.getChildren().add(love);
        grid.add(hb, 0, 9, 3, 5);

        btn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                int loveVal = calc.Compatability(f1.getText(), f2.getText(), f3.getText());
                love.setText("The chance of love is: " + Integer.toString(loveVal));
                love.setFont(new Font(25));
                love.setTextFill(Color.DARKRED);
            }
        });

        Scene scene = new Scene(grid, 500, 350);
        primaryStage.setScene(scene);
        scene.getStylesheets().add(LoveCalculator.class.getResource("loveCalculator.css").toExternalForm());
        primaryStage.show();
    }
}
