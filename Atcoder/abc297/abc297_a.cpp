#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[105];

void solve(){
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 2; i <= n; ++i){
        if(a[i] - a[i - 1] <= d){
            cout << a[i] << '\n';
            return;
        }
    }
    cout << "-1\n";
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}