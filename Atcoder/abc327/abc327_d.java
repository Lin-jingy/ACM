import java.util.Scanner;

public class abc327_d {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; ++i)
            a[i] = in.nextInt();
        for (int i = 0; i < m; ++i)
            b[i] = in.nextInt();
        in.close();
        DSU T = new DSU(2 * n + 5);
        for(int i = 0; i < m; ++i) {
            if(T.same(a[i], b[i])) {
                System.out.println("No");
                return ;
            }
            T.merge(a[i], b[i] + n);
            T.merge(a[i] + n, b[i]);
        }
        System.out.println("Yes");
    }

    final static int N = (int) 4e5 + 100;

    static class DSU {
        private int[] f = new int[N];

        DSU(int n) {
            for (int i = 1; i <= n; i++)
                f[i] = i;
        }

        public int find(int x) {
            if (x == f[x])
                return x;
            else
                return f[x] = find(f[x]);
        }

        public boolean same(int x, int y) {
            return find(x) == find(y);
        }

        void merge(int x, int y) {
            if (!same(x, y))
                f[find(x)] = find(y);
        }
    };
}
