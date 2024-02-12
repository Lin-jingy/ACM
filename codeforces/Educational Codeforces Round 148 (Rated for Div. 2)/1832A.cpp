#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    string a;
    cin >> a;
    int len = a.size();
    a = '0' + a;
    if(len == 4){
        if(a[1] != a[2]) {
            cout << "YES\n";
            return;
        }else {
            cout << "NO\n";
            return ;
        }
    }
    for(int i = 2; i <= len / 2; ++ i)if(a[i] != a[i - 1]){
        cout << "YES\n";
        return ;
    }
    cout << "NO\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
