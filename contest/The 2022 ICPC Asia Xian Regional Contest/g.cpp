#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

set<string>mp[505];
string x;

void solve() {
    int n;cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x;
        if(x.size() <= 500) mp[x.size()].insert(x);
    }
    int ans = 0;
    for (int i = 1;i <= 500;i++) {
        if (mp[i].empty()){
            ans=i-1;
            break;
        }
        if (i == 1) {
            ans = 1;
            continue;
        } 
        vector<string>s;
        for (auto j : mp[i]) {
            string temp1=j.substr(0,i-1);
            string temp2=j.substr(1,i-1);
            if(!mp[i-1].count(temp1)){
                s.push_back(j);
                continue;
            }
            if(!mp[i-1].count(temp2)){
                s.push_back(j);
                continue;
            }
            
        }
        for (auto j : s) mp[i].erase(j);
        if (mp[i].empty()){
            ans=i-1;
            break;
        }
    }
    cout << ans << '\n';
    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}