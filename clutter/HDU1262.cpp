#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
vector<int>v;
const int N = 1e4 + 5;
bool vis[N];

void fact(){
    for(int i = 2; i < N; ++i){
        if(vis[i])continue;
        v.emplace_back(i);
        for(int j = i; j < N; j += i)vis[j] = true;
    }
}

class node{
    public:
    int x, y, z;
    friend bool operator< (node a, node b){
        return a.z < b.z;
    }
};

void solve(){
    int n;
    while(cin >> n){
        vector<node>ans;
        auto end = lower_bound(v.begin(), v.end(), n) - v.begin();
        for(int i = 0; i < end; ++i){
            int k = n - v[i];
            if(find(v.begin(), v.end(), k) != v.end()){
                ans.push_back({v[i], k, abs(k - v[i])});
            }
        }
        int mn = 0;
        for(int i = 1; i < ans.size(); ++i){
            if(ans[i].z < ans[mn].z)mn = i;
        }
        cout << ans[mn].x << ' ' << ans[mn].y << '\n';
    }

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    fact();
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
