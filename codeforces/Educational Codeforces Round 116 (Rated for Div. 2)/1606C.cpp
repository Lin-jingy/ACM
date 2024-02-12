#include<bits/stdc++.h>
using namespace std;
int base[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int a[15], ans[15];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    int s = k + 1, p = n;
    for(int i = 1; i <= n; i++) {
        if(i == n) {
            ans[i] = s;
            break;
        }
        if(s > base[a[i + 1] - a[i]] - 1) {
            ans[i] = base[a[i + 1] - a[i]] - 1;
            s -= base[a[i + 1] - a[i]] - 1;
        } else {
            ans[i] = s;
            p = i;
            break;
        }
    }
    cout << ans[p];
    for(int i = 1; i <= a[p]; i++)cout << 9;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}