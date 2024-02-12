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
int n;
string s, a, b;
unordered_set<int>mp[N];

void solve(){
    for(int i = 0; i <= n; ++i)mp[i].clear();
    s.clear(), a.clear(), b.clear();
    cin >> s >> n >> a >> b;
    for(int i = 0; i < n; ++i){
        for(int j = (int)a[i]; j <= (int)b[i]; ++j)
            mp[i].insert(j - '0');
    }
    int flag = 0; 
    for(auto i:s){
        if(flag >= n){
            break;
        }
        if(mp[flag].count(i - '0'))mp[flag].erase(i - '0');
        if(mp[flag].empty())++flag;
    }
    int sum = 0;
    for(int i = 0; i < n; ++i)sum += (int)mp[i].size();
    if(sum != 0){
        yes;
        return;
    }
    no;

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
