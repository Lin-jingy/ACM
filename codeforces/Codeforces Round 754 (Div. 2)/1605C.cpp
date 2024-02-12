#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.find("aa") != string::npos) cout << 2 << '\n';
        else if(s.find("aba") != string::npos or s.find("aca") != string::npos) cout << 3 << '\n';
        else if(s.find("abca") != string::npos or s.find("acba") != string::npos) cout << 4 << '\n';
        else if(s.find("abbacca") != string::npos or s.find("accabba") != string::npos) cout << 7 << '\n';
        else cout<< -1 << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
