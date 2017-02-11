/**
 * Created by Joe on 2/8/2017.
 */
public class Sieve {

    private int[] primes;

    public void generatePrimes(int range){
        int[] num = new int[range+1];
        int numprimes = 0;

        for(int i = 2; i < range+1; ++i){
            if(num[i] != 0)
                continue;
            ++numprimes;
            for(int j = 2*i; j < range+1; j+=i){
                ++num[j];
            }
        }
        primes = new int[numprimes];
        int k = 0;
        for(int i = 2; i < range+1; ++i){
            if (num[i] == 0){
                primes[k] = i;
                ++k;
            }

        }

    }

    public void displayPrimes(){
        for(int i = 0; i < primes.length; ++i){
            System.out.print(primes[i] + " ");
            if(i%10 == 0)
                System.out.print("\n");
        }
    }

    public int[] decomposeNumber(int k){
        int[] ans = new int[2];
        int max = 0;
        int half = 0;

        while(primes[max] < k){

            ++max;
        }

        for(int i = 1; i <= max; ++i){
            for(int j = max; j >= i; --j){
                if(primes[j] == k - primes[i]){
                    ans[0] = primes[i];
                    ans[1] = primes[j];
                    break;
                }
            }
            if(ans[0] != 0)
                break;
        }


        return ans;
    }

}
