#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 2e5 + 5;
int a[N], b[N];
int p1[2 * N], p2[2 * N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    for(int i = 1; i <= n; ++ i)cin >> b[i];
    for(int i = 1; i <= 2 * n; ++ i)p1[i] = 0, p2[i] = 0;
    int k = 1;
	p1[a[1]] = 1;
    for(int i = 2; i <= n; ++ i){
        if(a[i] == a[i - 1])++ k;
        else k = 1;
        p1[a[i]] = max(p1[a[i]], k);
    }   
    k = 1;
	p2[b[1]] = 1;
    for(int i = 2; i <= n; ++ i){
        if(b[i] == b[i - 1])++ k;
        else k = 1;
        p2[b[i]] = max(p2[b[i]], k);
    } 
    int mx = 0;
    for(int i = 1; i <= 2 * n; ++ i)mx = max(mx, p1[i] + p2[i]);
    cout << mx << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
