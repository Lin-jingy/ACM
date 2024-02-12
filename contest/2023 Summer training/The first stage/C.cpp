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

const int N = 1e5 + 5;
int a[N], b[N], p[N];

void solve(){
    int n;
    cin >> n;
    int mx = 0;
    list<int>l;
    a[0] = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(a[i], mx);
        p[a[i]]++;
        if(a[i] != a[i - 1]) l.push_back(a[i]);
    }
    if(a[1] != 0 and a[1] != 1){
        cout << -1 << '\n';
        return ;
    }

    for(int i = 1; i <= n; ++i){
        if(a[i] > i) {
            cout << -1 << '\n';
            return ;
        }
    }

    for(int i = 2; i <= n; ++i){
        if(a[i] < a[i - 1]){
            cout << -1 << '\n';
            return ;
        }
    }
    list<int>v;
    for(int i = 0; i < mx; ++i) if(!p[i]) v.push_back(i);
    for(int i = 1; i <= n - mx; ++i) v.push_back(i + mx);

    for(int i = 1; i <= n; ++i){
        if(a[i] > l.front()) b[i] = l.front(), l.pop_front();
        else{
            b[i] = v.front();
            v.pop_front();
        }
    }

    for(int i = 1; i <= n; ++i) cout << b[i] << ' ';
    return ;
}   

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
