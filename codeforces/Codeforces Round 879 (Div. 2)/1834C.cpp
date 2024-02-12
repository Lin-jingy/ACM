#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"
string a, b;
void solve(){
    int n;
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i)if(a[i] != b[i])goto B;
    cout << 0 << '\n';
    return;
    B:;
    int k = 0;
    int k1 = 0;
    int flag = 1;
    for(int i = 0; i < n; ++i)if(a[i] != a[n - i - 1] and b[i] != b[n - i - 1])flag = 0;
    for(int i = 0; i < n; ++i)if(a[i] != b[i])++k;
    if(k == 1)goto A;
    if(k % 2 == 0 and flag == 0)k = k * 2;
    else k = k * 2 - 1;
    A:;
    reverse(a.begin(), a.end());
    for(int i = 0; i < n; ++i)if(a[i] != b[i])++k1;
    if(k1 == 0){
        cout << 2 << '\n';
        return;
    }
    if(k1 % 2 == 0 or flag == 1)k1 = k1 * 2 - 1;
    else k1 = k1 * 2;
    cout << min(k, k1) << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
