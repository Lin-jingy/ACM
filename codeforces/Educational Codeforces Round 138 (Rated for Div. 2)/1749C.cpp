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

const int N = 105;
int a[N], n;
multiset<int>s;

bool check(int x) {
    multiset<int>p(s);
    for(int i = 1; i <= x; ++i) {
        int k = x - i + 1;
        auto it = p.upper_bound(k);
        if(it == p.begin()) return false;
        else p.erase(--it);
        if(!p.empty()){
            int mid = *p.begin() + k;
            p.erase(p.begin());
            p.insert(mid);
        }
        
    }
    return true;
}

void solve() {
    cin >> n;
    s.clear();
    for(int i = 1, x; i <= n; ++i) cin >> x, s.insert(x);
    int l = 0, r = 100;
    int ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
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
