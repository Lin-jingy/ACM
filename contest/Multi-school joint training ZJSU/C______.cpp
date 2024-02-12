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
        if(n >= m)k1 += n / m, n %= m, flag = 1;
        else k2 += m / n - 1, m = m % n + n, flag = 2;
    }
    if(n + m == k){
        if(flag == 1 and k1 == 1)cout << "lovely\n";
        else if(flag == 1)cout << "type-c\n";
        else if(flag == 2 and k2 == 1)cout << "type-c\n";
        else if(flag == 2)cout << "lovely\n";
    }else cout << "draw\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
