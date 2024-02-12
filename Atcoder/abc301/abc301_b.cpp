#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n;
    cin >> n;
    int a[105];
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    cout << a[1] << ' ';
    for(int i = 2; i <= n; ++ i){
        if(a[i - 1] < a[i])for(int j = a[i - 1] + 1; j < a[i]; ++ j)cout << j << ' ';
        else for(int j = a[i - 1] - 1; j > a[i]; -- j)cout << j << ' ';
        cout << a[i] << ' ';
    }

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
