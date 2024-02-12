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

const int N = 3e5 + 5;
multiset<int>s[N];

void solve(){
    int n, m;
    cin >> n >> m;
    int ans = n;
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            if(s[x].empty())--ans;
            if(s[y].empty())--ans;
            s[x].insert(y);
            s[y].insert(x);
            cout << ans << '\n';
        }else{
            int x;
            cin >> x;
            if(!s[x].empty())++ans;
            while(!s[x].empty()){
                int k = *s[x].begin();
                s[x].erase(s[x].begin());
                auto it = s[k].find(x);
                s[k].erase(it);
                if(s[k].empty())++ans;
            }
            cout << ans << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
