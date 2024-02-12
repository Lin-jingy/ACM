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
auto fact(int x){
    vector<int>a;
    while(x){
        a.emplace_back(x % 2);
        x >>= 1;
    }
    while(a.size() < 30) a.emplace_back(0);
    reverse(a.begin(), a.end());
    return a;
}
void solve(){
    int n, k, x;
    cin >> n >> k;
    list<vector<int>>a, b, c;
    vector<int>en(fact(k));
    vector<int>now(30);
    for(int i = 1; i <= n; ++i) cin >> x, a.emplace_back(fact(x));
    for(int i = 1; i <= n; ++i) cin >> x, b.emplace_back(fact(x));
    for(int i = 1; i <= n; ++i) cin >> x, c.emplace_back(fact(x));
    while(!a.empty()){
        auto &it = *a.begin();
        for(int i = 0; i < 30; ++i) if(en[i] == 0 and it[i] == 1) goto A;
        for(int i = 0; i < 30; ++i) if(now[i] == 0) now[i] = it[i];
        a.pop_front();
    }
    A:;
    while(!b.empty()){
        auto &it = *b.begin();
        for(int i = 0; i < 30; ++i) if(en[i] == 0 and it[i] == 1) goto B;
        for(int i = 0; i < 30; ++i) if(now[i] == 0) now[i] = it[i];
        b.pop_front();
    }
    B:;
    while(!c.empty()){
        auto &it = *c.begin();
        for(int i = 0; i < 30; ++i) if(en[i] == 0 and it[i] == 1) goto C;
        for(int i = 0; i < 30; ++i) if(now[i] == 0) now[i] = it[i];
        c.pop_front();
    }
    C:;
    for(int i = 0; i < 30; ++i){
        if(en[i] != now[i]){
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
