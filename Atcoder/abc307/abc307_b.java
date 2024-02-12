import java.util.Scanner;

public class abc307_b {
	public static void main(String[] args)  {
        Scanner in = new Scanner(System.in);
		int n = in.nextInt();
        in.nextLine();
        String s[] = new String[n];
        for(int i = 0; i < n; ++i) s[i] = in.nextLine();
        in.close();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                String a = s[i] + s[j];
                if(a.equals(new StringBuilder(a).reverse().toString())){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
	}
}