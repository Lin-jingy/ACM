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

vector<PII> C, D;
vector<int> vc, cc, vd, cd;

bool cmp(PII a, PII b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
}

void solve(){
    int n, c, d;
    cin >> n >> c >> d;
    for(int i = 1; i <= n; ++i){
        int val, cas;
        char op;
        cin >> val >> cas >> op;
        if(op == 'C'){
            if(cas <= c)C.push_back({cas, val});
        } 
        else {
            if(cas <= d) D.push_back({cas, val});
        }
    }

    int ans = 0;
    if(!C.empty() and !D.empty()) {
        int mx1 = 0, mx2 = 0;
        for(int i = 0; i < C.size(); ++i) mx1 = max(C[i].second, mx1);
        for(int i = 0; i < D.size(); ++i) mx2 = max(D[i].second, mx2);
        ans = mx1 + mx2;
    }
        
    sort(C.begin(), C.end(), cmp);
    sort(D.begin(), D.end(), cmp);
    for(auto i:C){
        vc.emplace_back(i.second);
        cc.emplace_back(i.first);
    }
    for(auto i:D){
        vd.emplace_back(i.second);
        cd.emplace_back(i.first);
    }
    
    int mx = 0, flag = 0;
    int last = 0;
    if(C.size() < 2)goto A;
    for(int i = (int)C.size() - 1; i >= 1; --i){
        auto it = upper_bound(cc.begin(), cc.end(), c - cc[i]) - cc.begin();
        for(int j = last; j < it; ++j) if(vc[j] > mx) mx = vc[j], flag = j;
        if(i != flag) ans = max(ans, mx + cc[i]);
        last = it;
    }
    A:;
    mx = last = flag = 0;
    if(D.size() < 2)goto B;
    for(int i = (int)D.size() - 1; i >= 1; --i){
        auto it = upper_bound(cd.begin(), cd.end(), d - cd[i]) - cd.begin();
        for(int j = last; j < it; ++j) if(vd[j] > mx) mx = vd[j], flag = j;
        if(i != flag) ans = max(ans, mx + cd[i]);
        last = it;
    }
    B:;

    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
