#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 5;
int a[N];
int n, m;

inline int lcm(int x, int y){return x * y / __gcd(x, y);}

void solve(){
    cin >> n >> m;
    int k = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        k = lcm(k, a[i]);
    }
    for(int i = 1; i <= n; ++i){
        if((k / 2) / (a[i] / 2) % 2 == 0){
            cout << 0 << '\n';
            return;
        }
    }
    cout << (int)((m - k / 2.0) / k + 1) << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
