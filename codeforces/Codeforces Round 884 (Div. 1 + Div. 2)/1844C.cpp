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

const int N = 2e5 + 5;
int a[N];


void solve(){
    int n;
    cin >> n;
    list<int>l;
    int mx = -INF;
    for(int i = 1; i <= n; ++i) cin >> a[i], l.push_back(a[i]), mx = max(mx, a[i]);
    int flag = 0, k = 0, k1 = 0;
    for(auto i:l){
        if(flag and i > 0) k += i;
        flag = 1 - flag;
    }
    if(k == 0) k = mx;
    flag = 0;
    for(auto i:l){
        if(!flag and i > 0) k1 += i;
        flag = 1 - flag;
    }
    if(k1 == 0) k1 = mx;
    cout << max(k1, k) << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
