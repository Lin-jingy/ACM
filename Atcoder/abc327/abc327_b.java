import java.util.Scanner;

public class abc327_b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        in.close();
        for(int i = 1; ; i ++) {
            long ans = qpow(i, i);
            if(ans > n || ans < 0) break;
            if(ans == n) {
                System.out.println(i);
                return ;
            }
        }
        System.out.println("-1");

    }   
    static long qpow(long a, long b) {
        long sum = 1;
        while(b != 0) {
            if((b & 1) == 1) sum *= a;
            b >>= 1;
            a *= a;
        }
        return sum;
    } 
}
