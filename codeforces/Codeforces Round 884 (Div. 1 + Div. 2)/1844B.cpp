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

const int N = 2e5 + 5;
int a[N];

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << '\n';
    }else if(n == 2){
        cout << 2 << ' ' << 1 << '\n';
    }else {
        cout << 2 << ' ';
        int k = n - 3;
        int flag = 3;
        for(int i = 1; i <= k / 2; ++i){
            if(flag != 3) cout << flag++ << ' ';
            else ++flag, --i;
        }
        cout << 1 << ' ';
        for(int i = 1; i <= k - k / 2; ++i){
            if(flag != 3) cout << flag++ << ' ';
            else ++flag, --i;
        }
        cout << 3 << '\n';
    }

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
