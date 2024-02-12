#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n, m;
    cin >> n >> m;
    queue<int>q;
    q.push(n);
    int k = 0;
    while(!q.empty()){
        int x = q.front();
        if(x == m){
            cout << "YES\n";
            return;
        }
        q.pop();
        if(x % 3 == 0){
            ++k;
            q.push(x / 3);
            q.push(x / 3 * 2);
        }
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
