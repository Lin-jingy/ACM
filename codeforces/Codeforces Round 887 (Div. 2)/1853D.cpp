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
    vector<int>a(n), p(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y){
        return a[x] < a[y];
    });
    deque<int>dq;
    for(auto i:p) dq.push_back(i);
    vector<int>ans(n);
    int flag = n;
    int k = 0;
    while(!dq.empty()){
        if((a[dq.front()] - k == 0 and a[dq.back()] - k == flag) or ((a[dq.front()] - k != 0 and a[dq.back()] - k != flag))){
            no;
            return;
        }
        if(a[dq.front()] - k == 0) ans[dq.front()] = -flag, dq.pop_front();
        else if(a[dq.back()] - k == flag) {
            ans[dq.back()] = flag;
            dq.pop_back();
            ++k;
        }
        --flag;
    }
    yes;
    for(auto i:ans) cout << i << ' ';
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
