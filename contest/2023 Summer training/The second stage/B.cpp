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

const int N = 1e5 + 5;
int a[N];

int C(int a, int b){ // C a取b
    int k = 1;
    for(int i = a - b + 1; i <= a; ++i) k *= i;
    for(int i = 1; i <= b; ++i) k /= i;
    return k;
}


void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int k1 = 1, k2 = 1, k3 = 1;
    int ff = 0, ff1 = 0;
    for(int i = 2; i <= n; ++i){
        if(a[i] == a[1]) ++k1;
        else {
            ff = i;
            break;
        }
    }
    if(k1 >= 3){
        cout << C(k1, 3);
        return;
    }
    for(int i = ff + 1; i <= n; ++i){
        if(a[i] == a[ff]) ++k2;
        else {
            ff1 = i;
            break;
        }
    }
    if(k1 == 2){
        cout << k2;
        return;
    }
    if(k1 == 1 and k2 >= 2){
        cout << C(k2, 2);
        return;
    }
    for(int i = ff1 + 1; i <= n; ++i){
        if(a[i] == a[ff1]) ++k3;
        else break;
    }
    if(k1 == 1 and k2 == 1){
        cout << k3;
        return;
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
