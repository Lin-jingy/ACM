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

const int N = 1e6 + 5;
int p[N];

auto fact(int x){
    vector<int>mid;
    while(x){
        mid.emplace_back(1 - (x % 2));
        x >>= 1;
    }
    int k = 0;
    for(int i = 0; i < mid.size(); ++i){
        if(mid[i] == 1){
            k += (1ll << i);
        }
    }
    return k;
    
}

void solve(){
    int n;
    cin >> n;
    vector<int>ans;
    int flag = 0;
    int k = 0;
    for(int i = n - 1; i >= 0; ){
        while(flag and i >= 0){
            if(!p[k] and k < n){
                p[k] = 1;
                ans.emplace_back(k++);
                --i;
            }else flag = 0;
            
        }
        if(!flag){
            flag = 1;
            k = fact(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto i:ans)cout << i << ' ';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
