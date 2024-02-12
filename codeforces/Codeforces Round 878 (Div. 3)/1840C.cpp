#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 2e5 + 5;
int a[N], post[N];

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    memset(post, 0, (n + 1) * 4);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int flag = 0;
    for(int i = n; i >= 1; --i){
        if(a[i] <= q)++flag;
        else flag = 0;
        post[i] = flag;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(post[i] >= k)ans += post[i] - k + 1;
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
