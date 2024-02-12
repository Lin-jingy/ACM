#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 7;
vector<int>v;
int vis[N];

void fact(){
    for(int i = 2; i < N; ++ i){
        if(vis[i])continue;
        v.push_back(i);
        for(int j = i; j < N; j += i)vis[j] = 1;
    }

}

void solve(){
    int n;
    cin >> n;
    auto it = lower_bound(v.begin(), v.end(), 1 + n) - v.begin();
    auto it1 = lower_bound(v.begin(), v.end(), v[it] + n) - v.begin();
    cout << v[it] * v[it1] << '\n';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    fact();
    cin >> t;
    while(t--)solve();
    return 0;
}
