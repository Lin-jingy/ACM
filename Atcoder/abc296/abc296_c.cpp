#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int a[200005];
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; --i) {
        if(mp.count(a[i]-k)){
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";

}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}