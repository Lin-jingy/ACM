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
const int N = 505;

void solve(){
    int a[N];
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    int k1 = count(a + 1, a + 1 + n, 1), k0 = count(a + 1, a + 1 + n, -1);
    int ans = 0;
    while(k1 < k0){
        ++ans;
        ++k1;
        --k0;
    }
    if(k0 % 2 == 1)++ans;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
