#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    int k1 = 0, k2 = 0;
    for(auto i:a){
        if(i == 'T') ++ k1;
        else ++ k2;
    }
    if(k1 < k2)cout << 'A';
    else if(k1 > k2)cout << 'T';
    else{
        for(auto i:a){
            if(i == 'T')-- k1;
            else -- k2;
            if(k1 == 0){
                cout << 'T';
                return;
            }else if(k2 == 0){
                cout << 'A';
                return;
            }
        }
    }

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
