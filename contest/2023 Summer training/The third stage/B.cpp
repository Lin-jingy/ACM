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

void solve(){
    string a;
    cin >> a;
    list<char>x, y;
    for(auto i:a){
        if((i - '0') % 2 == 1)x.push_back(i);
        else y.push_back(i);
    }
    string ans;
    while(!x.empty() and !y.empty()){
        if(x.front() < y.front())ans += x.front(), x.pop_front();
        else ans += y.front(), y.pop_front();
    }
    while(!x.empty())ans += x.front(), x.pop_front();
    while(!y.empty())ans += y.front(), y.pop_front();
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
