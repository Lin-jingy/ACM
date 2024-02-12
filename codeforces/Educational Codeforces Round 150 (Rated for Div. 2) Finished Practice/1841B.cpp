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
const int N = 2e5 + 5;
int a[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    cout << 1;
    int flag = INT_MAX;
    int mx = a[1];
    for(int i = 2; i <= n; ++i){
        if(a[i] >= mx)cout << 1, mx = a[i];
        else if(a[i] > a[1])cout << 0;
        else {
            flag = i;
            break;
        }
    }
    int mn = 0;
    for(int i = flag; i <= n; ++i){
        if(a[i] >= mn and a[i] <= a[1]){
            cout << 1;
            mn = a[i];
        }else cout << 0;
    }
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
