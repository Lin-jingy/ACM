import java.util.Scanner;

public class abc327_a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        in.close();
        for(int i = 1; i < n; ++i) {
            if(s.charAt(i) == 'a' && s.charAt(i - 1) == 'b') {
                System.out.println("Yes");
                return ;
            }
            if(s.charAt(i) == 'b' && s.charAt(i - 1) == 'a') {
                System.out.println("Yes");
                return ;
            }
        }
        System.out.println("No");
    }
}
