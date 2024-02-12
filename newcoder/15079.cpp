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

int a[4] = {2, 5, 11, 13};
int n;

void solve(){
    int ans = n;
    for(int i = 0; i < 4; ++i) ans -= n / a[i];
    for(int i = 0; i < 4; ++i){
        for(int j = i + 1; j < 4; ++j){
            ans += n / (a[i] * a[j]);
        }
    }

    for(int i = 0; i < 4; ++i){
        for(int j = i + 1; j < 4; ++j){
            for(int k = j + 1; k < 4; ++k){
                ans -= n / (a[i] * a[j] * a[k]);
            }
        }
    }

    ans += n / (a[0] * a[1] * a[2] * a[3]);
    cout << ans << '\n';
    
        
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >> n)solve();
    return 0;
}
