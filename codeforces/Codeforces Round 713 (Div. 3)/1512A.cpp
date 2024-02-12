#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
int a[105];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    int k = count(a + 1, a + 1 + n, a[1]);
    if(k == n - 1){
        for(int i = 2; i <= n; ++ i)if(a[i] != a[1]){
            cout << i << '\n';
            return; 
        }
    }else cout << 1 << '\n';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
