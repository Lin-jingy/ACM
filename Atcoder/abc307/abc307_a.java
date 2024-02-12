import java.util.Scanner;

public class abc307_a {

	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		int n = in.nextInt();
        for(int i = 0; i < n; ++i) {
            int ans = 0;
            for(int j = 0; j < 7; ++j){
                int x = in.nextInt();
                ans += x;
            }
            System.out.print(ans);
            System.out.print(" ");
        }
		in.close();
	}
}