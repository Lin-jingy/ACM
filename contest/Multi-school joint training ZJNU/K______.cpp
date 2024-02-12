#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
int n, m, d, p;

bool check(int x){
    int l = p - x;
    int r = p + x;
    int sum = 0;
    if(l < 1)sum += (p - 1) * (l - 1) + 
    else sum += x * x / 2;
    if(r > n)sum += (x + r - n) * (n - p) / 2;
    else sum += x * x / 2;
    sum += x;
    if(sum * d > m)return false;
    else return true;
}

void solve(){
    cin >> n >> m >> d >> p;
    m -= n;
    int ans = 0;
    int l = 0, r = m;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid))l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    // int l = p, r = p;
    // while(1){
    //     if(m >= (r - l + 1) * d){
    //         ans += d;
    //         m -= (r - l + 1) * d;
    //         r = min(n, r + 1);
    //         l = max(1ll, l - 1);
    //     }else break;
    //     if(l == 1 and r == p)break;
    // }
    // int k = m / (r - l + 1);
    // ans += k;
    cout << ans + 1 << '\n';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i = 1; i <= n; ++ i){

    }
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
//https://do1.aiusr.site/contest/1275/problem/K