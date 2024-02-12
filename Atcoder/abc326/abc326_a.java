import java.util.Scanner;

public class abc326_a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        in.close();
        if(a > b && a - b <= 3) System.out.println("Yes");
        else if(a < b && b - a <= 2) System.out.println("Yes");
        else System.out.println("No");
    }
}