import java.util.Arrays;
import java.util.Scanner;

public class abc326_c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int []a = new int[n];
        for(int i = 0; i < n; ++i) a[i] = in.nextInt();
        in.close();
        Arrays.sort(a);
        long ans = 0;
        int l = 0;
        for(int i = 0; i < n; ++i) {
            while(l < i && a[l] + m <= a[i]) {
                l++;
            }
            ans = Math.max(ans, i - l + 1); 
        }
        System.out.println(ans);
    }
}
