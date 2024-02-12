import java.util.Scanner;

public class abc326_b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        in.close();
        for(int i = a; i <= 999; ++i) {
            if(check(i)) {
                System.out.println(i);
                return ;
            }
        }

    }
    static boolean check(int x) {
        int a = x / 100;
        int b = x / 10 % 10;
        int c = x % 10;
        if(a * b == c) return true;
        else return false;
    }
}
