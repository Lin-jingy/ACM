import java.util.Scanner;

public class abc327_c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int [][]s = new int[10][10];
        for(int i = 1; i <= 9; ++i) for(int j = 1; j <= 9; ++j) s[i][j] = in.nextInt();
        in.close();
        int []p = new int[10];
        int []cp = p;
        for(int i = 1; i <= 9; ++i) {
            for(int j = 1; j <= 9; ++j) {
                p[s[i][j]]++;
            }
            if(check(cp)) return ;
        }
        for(int i = 1; i <= 9; ++i) {
            for(int j = 1; j <= 9; ++j) {
                p[s[j][i]]++;
            }
            if(check(cp)) return ;
        }
        for(int i = 1; i <= 9; ++i) {
            for(int j = 1; j <= 3; ++j) {
                p[s[i][j]]++;
            }
            if(i % 3 == 0) {
                if(check(cp)) return ;
            }
        }
        for(int i = 1; i <= 9; ++i) {
            for(int j = 4; j <= 6; ++j) {
                p[s[i][j]]++;
            }
            if(i % 3 == 0) {
                if(check(cp)) return ;
            }
        }
        for(int i = 1; i <= 9; ++i) {
            for(int j = 7; j <= 9; ++j) {
                p[s[i][j]]++;
            }
            if(i % 3 == 0) {
                if(check(cp)) return ;
            }
        }
        System.out.println("Yes");
    }
    static boolean check(int []p) {
        for(int i = 1; i <= 9; ++i) {
            if(p[i] == 0) {
                System.out.println("No");
                return true;
            }
        }
        for(int i = 1; i <= 9; ++i) p[i] = 0;
        return false;
    }
}
