#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e6 + 5;
vector<int>a(N), p(N); 

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i], p[a[i]]++;
    int sum = 0;
    for(int i = 1; i <= 1e6; ++ i){
        if(p[i])continue;
        int ans = -1;
        for(int j = 2 * i; j <= 1e6; j += i){
            if(!p[j])continue;
            if(ans == -1)ans = j / i;
            else ans = __gcd(ans, j / i);
            if(ans == 1){
                p[i] = 1;
                ++ sum;
                goto A;
            }
        }
        A:;
    }
    cout << sum ;

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
