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

int a[10000];

void solve(){
    int n;
    cin >> n;
    n = 1 << n;
    list<int>l;
    for(int i = 1; i <= n; ++i) cin >> a[i], l.push_back(a[i]);
    while(l.size() != 2){
        for(auto it = l.begin(); it != l.end(); ){
            if(*(it++) > *(it)) it = l.erase(it);
            else --it, it = l.erase(it), ++it;
        }
    }
    int ans;
    if(l.front() >= l.back()) ans = l.back();
    else ans = l.front();
    cout << find(a + 1, a + 1 + n, ans) - a;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
