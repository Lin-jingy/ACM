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

list<string>l;

void solve(){
    int n;
    cin >> n;
    int mn = inf;
    string kk;
    while(n--){
        string a;
        int k;
        cin >> a >> k;
        l.push_back(a);
        if(k < mn) mn = k, kk = a;
    }
    int flag = 0;
    for(auto it = l.begin(); it != l.end(); ){
        if(flag == 1 or *it == kk){
            flag = 1;
            cout << *it << '\n';
            it = l.erase(it);
        }else{
            ++it;
        }
        
    }
    for(auto i:l){
        cout << i << '\n';
    }
    
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
