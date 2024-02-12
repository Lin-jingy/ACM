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
string a[2];

void solve(){
    int n;
    cin >> n;
    cin >> a[0];
    cin >> a[1];

    int s[2] = {1, 0};
    for(int i = 0; i < n; ++i){
        if(a[0][i] == 'B' and s[0] == 1){
            if(a[1][i] == 'B') s[0] = 0, s[1] = 1;
        }else if(a[1][i] == 'B' and s[1] == 1){
            if(a[0][i] == 'B') s[0] = 1, s[1] = 0;
        }else goto B;
    }
    goto A;
    B:;
    s[0] = 0, s[1] = 1;
    for(int i = 0; i < n; ++i){
        if(a[0][i] == 'B' and s[0] == 1){
            if(a[1][i] == 'B') s[0] = 0, s[1] = 1;
        }else if(a[1][i] == 'B' and s[1] == 1){
            if(a[0][i] == 'B') s[0] = 1, s[1] = 0;
        }else goto C;
    }
    A:;
    yes;
    return;
    C:;
    no;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
