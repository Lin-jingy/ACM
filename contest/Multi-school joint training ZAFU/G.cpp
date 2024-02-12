#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 5;
int n, x, mx, si;
int sk[N];
vector<int>v[N], a;

void fact(){
    for(int i = 0; i < n; ++ i){
        vector<int>mid;
        int kk = sk[i];
        while(kk){
            mid.emplace_back(kk % 2);
            kk /= 2;
        }
        while(mid.size() < si)mid.emplace_back(0);
        reverse(mid.begin(), mid.end());
        v[i] = mid;
    }
}

void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; ++ i){
        cin >> sk[i];
        mx = max(mx, sk[i]);
        a.emplace_back(i);
    }
    while(mx){
        si++;
        mx /= 2;
    }
    fact();
    int ans = 0;
    for(int i = 0; i <= si; ++ i){
        if((int)a.size() <= x)break;
        int sum = 0;
        for(auto it = a.begin(); it != a.end(); ++ it)if(v[*it][i] == 1) ++ sum;
        if(sum > x){
            for(auto it = a.begin(); it != a.end();){
                if(v[*it][i] == 0) it = a.erase(it);
                else ++ it;
            }
        }else if(sum == x){
            for(auto it = a.begin(); it != a.end();){
                if(v[*it][i] == 0) it = a.erase(it);
                else ++ it;
            }
            for(auto j:a){
                if(ans == 0)ans = sk[j];
                else ans &= sk[j];
            }
            cout << ans;
            return;
        }
    }
    for(int i = 0; i < x; ++ i){
        if(ans == 0)ans = sk[a[i]];
        else ans &= sk[a[i]];
    }
    cout << ans;
    return;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
