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
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    int ans = 0;
    if(bx < ax and cx < ax)ans += min(abs(bx - ax), abs(cx - ax));
    if(bx > ax and cx > ax)ans += min(abs(bx - ax), abs(cx - ax));
    if(by > ay and cy > ay)ans += min(abs(by - ay), abs(cy - ay));
    if(by < ay and cy < ay)ans += min(abs(by - ay), abs(cy - ay));
    cout << ans + 1 << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
