import java.util.Scanner;

public class abc327_e {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; ++i)
            a[i] = in.nextInt();
        in.close();
        double[][] dp = new double[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] * 0.9 + a[i]);
            }
        }
        double ans = -1e18;
        double k = 1, sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += k;
            ans = Math.max(ans, dp[n][i] / sum - 1200 / Math.sqrt(i));
            k *= 0.9;
        }
        System.out.println(ans);
    }
}
