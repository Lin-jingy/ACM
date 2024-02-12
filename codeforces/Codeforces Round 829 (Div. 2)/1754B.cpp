//#pragma GCC optimize(3)
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

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    int flag = (n + 1) / 2;
    for(int i = 0; i < n; i += 2) a[i] = flag--;
    flag = (n + 1) / 2 + 1;
    for(int i = n - 1 - n % 2; i >= 0; i -=2) a[i] = flag++;
    for(auto i:a) cout << i << ' ';
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
