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

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int k1 = count(s.begin(), s.end(), '1');
    int k0 = count(s.begin(), s.end(), '0');
    for(int i = (1ll << k1); i <= (1 << n) - (1ll << k0) + 1; ++i)cout << i << ' ';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
