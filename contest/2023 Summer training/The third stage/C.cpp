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

const int N = 3e4 + 5;
int a[N];
int n, k;

bool check(int x){
    int last = 0;
    int sk = k;
    for(int i = 1; i <= n and sk > 0; ++i){
        sk -= (last + a[i]) / x;
        if(a[i] + last >= x)last = (last + a[i]) % x;
        else last = a[i];
    }
    if(sk <= 0)return true;
    else return false;
}

void solve(){
    cin >> n >> k;
    int sum = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    int ans = 0;
    int l = 1, r = sum / k;
    if(sum < n)l = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid))l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans * k << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
