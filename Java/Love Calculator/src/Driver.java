/**
 * Created by Joe on 2/15/2017.
 */
public class Driver {

    public static void main(String[] args){
        Calculations c = new Calculations();
        int[] v = c.stringToVector("adbdcd");
        System.out.println(v[0] + " " + v[1] + " " + v[2]);
        int[][] arr = {{3,2,1},{5,2,6},{8,6,5}};
        System.out.println(c.determinant(arr));
        System.out.println(c.Compatability("Mansha", "Ridhi", "Midi"));
    }
}
