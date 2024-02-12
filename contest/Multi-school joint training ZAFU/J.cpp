#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N =2e5 + 5;
int a[N], p[N];
vector<int>ans;

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        p[a[i]] = i;
    }
    int s = 0;
    for(int i = 1; i <= n; ++ i){
        if(p[i] == i)continue;
        s ++;
        ans.emplace_back(i);
        ans.emplace_back(p[i]);
        p[a[i]] = p[i];
        swap(a[p[i]], a[i]);
        if(p[i] - i > 1){
            s ++;
            ans.emplace_back(i + 1);
            ans.emplace_back(p[i] - 1); 
        }
        
    }
    cout << s << '\n';
    for(int i = 0; i < 2 * s; i ++){
        if(i % 2 == 0)cout << ans[i] << ' ';
        else cout << ans[i] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
