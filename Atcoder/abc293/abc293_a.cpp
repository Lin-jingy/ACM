#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    string a;
    cin >> a;
    int len = a.size();
    a = '0' + a;
    for(int i = 1; i <= a.size(); ++ i){
        if(2 * i > len)break;
        swap(a[2 * i], a[2 * i - 1]);
    }
    for(int i = 1;i <= len; ++ i)cout << a[i];
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    solve();
    return 0;
}