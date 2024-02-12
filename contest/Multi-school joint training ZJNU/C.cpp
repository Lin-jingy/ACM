#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
int a[100005];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    if(n % 3 != 0){
        cout << "No\n";
        return;
    }
    sort(a + 1, a + 1 + n);
    int k1 = 0, k2 = 0, k3 = 0;
    for(int i = 1; i <= n / 3; ++ i)k1 += a[i];
    for(int i = n / 3 + 1; i <= n / 3 * 2; ++ i)k2 += a[i];
    for(int i = n / 3 * 2 + 1; i <= n; ++ i)k3 += a[i];
    if(k1 != k2 and k2 != k3 and k1 != k3){
        cout << "Yes\n";
        for(int i = 1; i <= n / 3; ++ i)cout << a[i] << ' ';
        cout << '\n';
        for(int i = n / 3 + 1; i <= n / 3 * 2; ++ i)cout << a[i] << ' ';
        cout << '\n';
        for(int i = n / 3 * 2 + 1; i <= n; ++ i)cout << a[i] << ' ';
        cout << '\n';
    }else{
        swap(a[1],a[n]);
        k1 = 0, k2 = 0, k3 = 0;
        for(int i = 1; i <= n / 3; ++ i)k1 += a[i];
        for(int i = n / 3 + 1; i <= n / 3 * 2; ++ i)k2 += a[i];
        for(int i = n / 3 * 2 + 1; i <= n; ++ i)k3 += a[i];
        if(k1 != k2 and k2 != k3 and k1 != k3){
            cout << "Yes\n";
            for(int i = 1; i <= n / 3; ++ i)cout << a[i] << ' ';
            cout << '\n';
            for(int i = n / 3 + 1; i <= n / 3 * 2; ++ i)cout << a[i] << ' ';
            cout << '\n';
            for(int i = n / 3 * 2 + 1; i <= n; ++ i)cout << a[i] << ' ';
            cout << '\n';
        }else cout << "No\n";
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
