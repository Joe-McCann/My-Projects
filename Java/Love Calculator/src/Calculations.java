/**
 * Created by Joe on 2/14/2017.
 */
public class Calculations {

    public int Compatability(String n1, String n2, String coupleName){
        int compat = 0;
        int[][] array = new int[3][];
        array[0] = stringToVector(n1);
        array[1] = stringToVector(n2);
        array[2] = stringToVector(coupleName);
        compat = Math.abs(determinant(array))%101;

        return compat;
    }

    public int[] stringToVector(String str){
        int[] vec = {0,0,0};
        if (str.length() < 3){
            str += str + "aaa";
        }
        String[] strVec = new String[3];
        strVec[0] = str.substring(0, (str.length()/3));
        strVec[1] = str.substring((str.length()/3), 2*(str.length()/3));
        strVec[2] = str.substring(2*(str.length()/3));

        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < strVec[i].length(); ++j){
                vec[i]+=(int)(strVec[i].charAt(j));
            }
        }
        return vec;
    }

    public int determinant(int[][] array){
        int det = 0;
        for(int i = 0; i < 3; ++i){
            det += (array[0][0+i]*array[1][(1+i)%3]*array[2][(2+i)%3]);
        }
        for(int i = 0; i < 3; ++i){
            det -= (array[0][2-i]*array[1][(4-i)%3]*array[2][Math.abs(3-i)%3]);
        }
        return det;
    }

}
