#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n;
    cin >> n;
    int x;
	priority_queue<int>q;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while(q.size() >= 2){
        if(q.top() == 1)break;
        int k1 = q.top();
        q.pop();
        if(q.top() == 1){
            ans += k1;
            break;
        }
        k1 *= q.top();
        q.pop();
        q.push(k1);
        q.push(1);
    }
    while(!q.empty())ans += q.top(), q.pop();
    cout << ans * 2022 << '\n';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
