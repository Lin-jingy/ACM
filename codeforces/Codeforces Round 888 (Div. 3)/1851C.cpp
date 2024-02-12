// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define int long long
using PII = pair<int, int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(size_t i(0); i < n; ++i) cin >> a[i];
    if(a.front() == a.back()){
        if(count(ALL(a), a.front()) >= k) yes;
        else no;
        return;
    }
    if(n == 2){
        if(k == 1) yes;
        else no;
        return;
    }
    int kk(k), kkk(k);
    int flag1(0), flag2(n - 1);
    for(size_t i(0); i < n - 1 and kk > 0; ++i) if(a[i] == a.front()) --kk, flag1 = i;
    for(size_t i(n - 1); i > 0 and kkk > 0; --i) if(a[i] == a.back()) --kkk, flag2 = i;
    if(kk == 0 and kkk == 0 and flag1 < flag2) yes;
    else no;
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)solve();
    return 0;
}
