#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
 
using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 3e5 + 5;
int a[N];
 
void solve(){
    int n;
    cin >> n;
    a[0] = -1;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        if(a[i] == a[i - 1])-- n, -- i;
    }
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    int ans = n;
    for(int i = 2; i < n; ++ i){
        if(a[i] > a[i - 1] and a[i] < a[i + 1])--ans;
        else if(a[i] < a[i - 1] and a[i] > a[i + 1])--ans;
    }
    cout << ans << '\n';
}
 
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}