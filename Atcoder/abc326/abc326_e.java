import java.util.Scanner;

public class abc326_e {
    final static int mod = 998244353;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int []a = new int[n + 1];
        for(int i = 1; i <= n; ++i) a[i] = in.nextInt();
        in.close();
        long []dp = new long[n + 1];
        long rn = rmod(n);
        long k = rn;
        dp[1] = k;
        for(int i = 2; i <= n; ++i) {
            long mid = k * rn % mod;
            k = (k + mid) % mod;
            dp[i] = k;
        }
        //1 0.333462
        //2 0.444473
        //3 0.592548
        long ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans = (ans + dp[i] * a[i] % mod) % mod;
        }
        System.out.println(ans);
    }
    static long qpow(long a, long b) {
        long sum = 1;
        while(b > 0) {
            if((b & 1) == 1) sum = sum * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return sum;
    }
    static long rmod(long a) {
        return qpow(a, mod - 2);
    } 
}
