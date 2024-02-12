#include<iostream>
#include<stack>

using namespace std;
#define int long long
const int N = 2e3 + 5;
int a[N][N];
int dep[N][N];
int lx[N], rx[N];
stack<int> s;

void clear(){
    while(!s.empty())s.pop();
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j];
        for (int i = 0; i <= n + 3; ++i)for (int j = 0; j <= m + 3; ++j)dep[i][j] = 0;
        for (int j = 1; j <= m; ++j)for (int i = 1; i <= n; ++i)if (a[i][j])dep[i][j] = dep[i - 1][j] + 1;

        //TLE
//        int mx = 0;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                int h = dep[i][j];
//                int len = 1;
//                int len1 = 1;
//                while (j + len <= m) {
//                    if (dep[i][j + len] < h)break;
//                    else ++len;
//                }
//                while (j - len1 >= 1) {
//                    if (dep[i][j - len1] < h)break;
//                    else ++len1;
//                }
//                mx = max(mx, (len + len1 - 1) * h);
//            }
//        }

        //单调栈
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                while (!s.empty() and dep[i][j] <= dep[i][s.top()])s.pop();
                lx[j] = (s.empty() ? 1 : s.top() + 1);
                s.push(j);
            }
            clear();
            for (int j = m; j >= 1; j--) {
                while (!s.empty() and dep[i][j] <= dep[i][s.top()])s.pop();
                rx[j] = (s.empty() ? m : s.top() - 1);
                s.push(j);
            }
            clear();
            for (int j = 1; j <= m; j++) mx=max(mx,dep[i][j] * (rx[j] - lx[j] + 1));
        }
        cout << mx << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    solve();
    return 0;
}