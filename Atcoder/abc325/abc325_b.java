import java.util.Scanner;

public class abc325_b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int []num = new int[n];
        int []time = new int[n];
        for(int i = 0; i < n; ++i) {
            num[i] = in.nextInt();
            time[i] = in.nextInt();
        }
        in.close();
        long ans = 0;
        for(int i = 0; i < 24; ++i) {
            long sum = 0;
            for(int j = 0; j < n; ++j) {
                int t = time[j] + i;
                t = t % 24;
                if(t >= 9 && t <= 17) sum += num[j];
            }
            ans = Math.max(ans, sum);
        }
        System.out.println(ans);
    }
}
