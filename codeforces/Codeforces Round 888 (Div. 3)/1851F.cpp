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
#define yes cout << "Yes\n"
#define no cout << "No\n"


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int>a(n), p(n);
	for(size_t i(0); i < n; ++i)cin>> a[i] , p[i] = i;
	sort(ALL(p), [&](int x, int y){
        return a[x] < a[y];
    });
	int mn(1 << k), ans1(0), ans2(0);
	for(size_t i(0); i < n - 1; ++i){
		if((a[p[i]] ^ a[p[i + 1]]) <= mn) ans1 = p[i], ans2 = p[i+1], mn = (a[p[i]] ^ a[p[i + 1]]);
	}
    cout << ans1 + 1 << ' ' << ans2 + 1 << ' ';
    cout << ((1ll << k) - 1 - a[ans1] & (1ll << k) - 1 - a[ans2]) << '\n';
}




// const int N = 2e5 + 5;
// vector<bool>sp[N];
// string s[N];
// int n, k;

// vector<bool> change(int x){
//     vector<bool> mid;
//     while(x){
//         mid.push_back(x % 2);
//         x >>= 1;
//     }
//     while((int)mid.size() < k + 1) mid.push_back(0);
//     reverse(ALL(mid));
//     return mid;
// }

// void solve(){
//     cin >> n >> k;
//     k = (1ll << k);
//     vector<int>a(n);
//     for(size_t i(0); i < n; ++i) cin >> a[i], s[i].clear(), sp[i].clear();
//     for(size_t i(0); i < n; ++i) sp[i] = change(i);
//     for(size_t i(0); i < n; ++i) for(auto j:sp[i]){
//         if(j == false) s[i] += '0';
//         else s[i] += '1';
//     }
//     vector<int>p(n);
//     iota(ALL(p), 0);
//     sort(ALL(p), [&](int x, int y){
//         return s[x] > s[y];
//     });
//     sort(s, s + n, greater<>());
//     int mx(0), pos(0);
//     for(size_t i(1); i < n; ++i){
//         int mid(0);
//         for(size_t j(0); j < k + 1; ++j) if(s[i][j] == s[i - 1][j]) ++mid;
//         if(mid > mx) mx = mid, pos = i;
//     }
//     cout << p[pos] << ' ' << p[pos - 1] << ' ';
//     int x;
//     string &aa = s[pos], &bb = s[pos - 1];
//     reverse(ALL(aa)), reverse(ALL(bb));
//     for(size_t i(0); i < k + 1; ++i){
//         if(aa[i] == bb[i] and aa[i] == 1) x += (1ll << i);
//     }
//     cout << x << '\n';

// }

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
