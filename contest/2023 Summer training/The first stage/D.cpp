#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf 9223372036854775807ll
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int h, c, t;
    cin >> h >> c >> t;

    int l = 1, r = 1e9;
    for(int i = 1; i <= 100; ++i){
        int mid = l + r >> 1;
        double k = (mid * h + mid * c - c) * 1.0 / (mid + mid - 1);
        if(k < t) r = mid;
        else l = mid;
    }
    int ans = 0;
    double k1 = (l * h + l * c - c) * 1.0 / (l + l - 1);
    double k2 = (r * h + r * c - c) * 1.0 / (r + r - 1);
    if(fabs(k1 - t) <= fabs(k2 - t))ans = l;
    else ans = r;
    double kk1 = fabs((ans*h+ans*c-c)*1.0/(ans+ans-1)-t);
    double kk2 = fabs((h+c)*1.0/2-t);
    if(kk1 < kk2) cout << ans + ans - 1 << '\n';
    //else if(kk3 < kk1 and kk3 < kk2) cout << 1 << '\n';
    else cout << 2 << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
