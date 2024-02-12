#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 2e3 + 5;
priority_queue<int>q;

void solve(){
    int n;
    cin >> n;
    int x, ans = 0, flag = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        if(x < 0)q.push(-x);
        flag += x;
        ++ ans;
        while(!q.empty() and flag < 0)flag += q.top(), q.pop(), -- ans;
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
