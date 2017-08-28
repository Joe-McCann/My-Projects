/**
 * Created by Joe on 2/8/2017.
 */
public class driver {

    public static void main(String[] args){
        Sieve siv = new Sieve();
        siv.generatePrimes(1000000);
        System.out.println("Done!");
        int[] x = new int[2];
        x = siv.decomposeNumber(20);
        System.out.println(x[0] + " " + x[1]);
        //siv.displayPrimes();
    }

}
