#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

auto sum(int x){
    int k = 0;
    while(x){
        k += x % 10;
        x /= 10;
    }
    return k;
}

void solve(){
    int n;
    cin >> n;
    for(int i = n; ; ++i){
        if(__gcd(i, sum(i)) != 1){
            cout << i << '\n';
            return ;
        }
    }

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
