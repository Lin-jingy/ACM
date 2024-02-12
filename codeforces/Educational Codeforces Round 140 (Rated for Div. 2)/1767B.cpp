#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 2e5 + 5;
int a[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 2, a + 1 + n);
    for(int i = 2; i <= n; ++i){
        if(a[1] >= a[i]) continue;
        a[1] = (a[1] + a[i] + 1) / 2;
    }
    cout << a[1] << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
