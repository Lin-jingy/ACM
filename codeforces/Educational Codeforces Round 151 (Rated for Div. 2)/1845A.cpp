#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    if(x != 1){
        yes;
        cout << n << '\n';
        while(n--)cout << 1 << ' ';
        cout << '\n';
    }else{
        if(n % 2 == 0){
            if(k == 1){
                no;
                return;
            }
            yes;
            cout << n / 2 << '\n';
            for(int i = 1; i <= n; i += 2) cout << 2 << ' ';
            cout << '\n';
        }else if(n >= 5){
            if(k < 3){
                no;
                return;
            }
            yes;
            cout << (n - 3) / 2 + 1 << '\n';
            cout << 3 << ' ';
            n -= 3;
            for(int i = 1; i <= n; i += 2) cout << 2 << '\n';
        }else{
            if(n == 3 and k >= 3){
                yes;
                cout << 1 << '\n';
                cout << 3 << '\n';
                return;
            }else{
                no;
                return;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
