//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

auto fact(int x){
    int sum = 0;
    while(x){
        ++sum;
        x >>= 1;
    }
    return sum;
}


void solve(){
    int n;
    cin >> n;
    if(n == 1) cout << 1 << '\n';
    else if(n == 2) cout << 2 << '\n';
    else if(n == 3) cout << 2 << '\n';
    else {
        if(1 << (fact(n) - 1) == n) cout << n - (1 << (fact(n) - 2)) + 1 << '\n';
        else{
            int k = log2(n);
            int ans = 0;
            for(int i = 1; i <= k + 1; ++i){
                ans += (n - (1ll << (i - 1)) + (1ll << (i + 1))) / (1ll << (i + 1));
            }
            cout << ans << '\n';
        }

    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
