#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int k1 = 0, k2 = 0;
    int flag = 0;
    if(n + m < k){
        cout << "draw\n";
        return;
    }
    while(n != 0 and m != 0 and n + m != k){
        if(n >= m)n -= m, k1++, flag = 1;
        else m -= n, k2 ++, flag = 2;
    }
    if(n + m == k and (k1 > 1 or k1 <= 1 and flag != 1))cout << "type-c\n";
    else if(n + m == k) cout << "lovely\n";
    else cout << "draw\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
