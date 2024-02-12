#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int sum;
int a[105][105];
bool flag[105][105];
queue<pair<int, int>>k;
signed main() {         
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int k = getchar();
            a[i][j] = k-48;
        }
        getchar();
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (flag[i][j]==true || a[i][j]==0);
            else{
                sum++;
                k.push(make_pair(i, j));
                while (!k.empty()) {
                    int x = k.front().first;
                    int y = k.front().second;
                    k.pop();
                    if (x + 1 <= n && !flag[x + 1][y] && a[x + 1][y]!=0) {
                        flag[x + 1][y] = true;
                        k.push(make_pair(x + 1, y));
                    }
                    if (x - 1 >= 1 && !flag[x - 1][y] && a[x - 1][y]!=0) {
                        flag[x - 1][y] = true;
                        k.push(make_pair(x - 1, y));
                    }
                    if (y + 1 <= m && !flag[x][y + 1] && a[x][y + 1]!=0) {
                        flag[x][y + 1] = true;
                        k.push(make_pair(x, y + 1));
                    }
                    if (y - 1 >= 1 && !flag[x][y - 1] && a[x][y - 1]!=0) {
                        flag[x][y - 1] = true;
                        k.push(make_pair(x, y - 1));
                    }
                }
            }
        }
    }
    cout << sum;
    return 0;
}