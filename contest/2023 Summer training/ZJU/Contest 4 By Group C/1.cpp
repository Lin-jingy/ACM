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

const int N = 3e5 + 5;
int a[N], sum, n, k;

bool check(int x){
    int mid = (sum + x) / n;
    if(mid < a[(n + 1) / 2])return false;
    for(int j = (n + 1) / 2; j <= n; ++j){
        if(a[j] < mid) x -= mid - a[j];
        else break;
        if(x < 0)break;
    }
    if(x >= 0)return true;
    else return false;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    sort(a + 1, a + 1 + n);
    int be = n - sum % n;
    if(be == n) be = 0;
    int l = 0, r = (k - be) / n;
    int ans = -1;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid * n + be))r = mid - 1, ans = mid * n + be;
        else l = mid + 1;
    }
    if(ans <= k)cout << ans;
    else cout << -1;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
