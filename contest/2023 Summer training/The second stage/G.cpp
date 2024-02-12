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

void solve(){
    string a;
    cin >> a;
    int ans = 0;
    int sum = 0, kk = 0, flag = 0;
    for(int i = 0; i < a.size(); ++i){
        kk = (a[i] - '0') % 3;
        sum += kk;
        ++flag;
        if(kk == 0 or sum % 3 == 0 or flag == 3){
            sum = flag = 0;
            ++ans;
        }

    }
    cout << ans ;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
