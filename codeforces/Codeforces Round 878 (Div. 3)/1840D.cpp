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
int n;
int a[N];

bool check(int x){
    int mn = a[1] + x;
    int mx = a[n] - x;
    int k = 0;
    for(int i = 2; i < n; ++i){
        if(abs(a[i] - mn) <= x)continue;
        if(abs(mx - a[i]) <= x)continue;
        if(k == 0)k = a[i] + x;
        else if(abs(k - a[i]) <= x)continue;
        else return false;
    }
    return true;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int flag = 1;
    for(int i = 2; i <= n; ++i)if(a[i] != a[i - 1])++flag;
    if(flag <= 3){
        cout << 0 << '\n';
        return;
    }
    int l = 0, r = INT_MAX;
    int ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid))r = mid - 1, ans = mid;
        else l = mid + 1;
    }  
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
