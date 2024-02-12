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

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int mn = inf;
    for(int i = 0; i < n; ++i) if(a[i] % 2 == 1)mn = min(mn, a[i]); 
    //奇数
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 1 and a[i] <= mn){
            goto A;
        }
    }
    yes;
    return;
    A:;
    //偶数
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 0 and a[i] <= mn){
            no;
            return;
        }
    }
    yes;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
