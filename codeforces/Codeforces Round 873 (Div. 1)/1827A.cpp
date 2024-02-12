#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int a[N], b[N], p[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    for(int i = 1; i <= n; ++i)cin >> b[i];
    sort(a + 1, a + 1 + n, greater<>());
    sort(b + 1, b + 1 + n, greater<>());
    int flag = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = flag; j <= n; ++j){
            if(a[j] > b[i])++flag;
            else{
                p[i] = flag;
                goto A;
            }
        }
		p[i] = flag;
		A:;
    }
    int ans = 1;
    for(int i = 1; i <= n; ++ i){
        if(p[i] > i - 1)ans = ans * (p[i] - i) % mod;
        else {
            cout << 0 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
