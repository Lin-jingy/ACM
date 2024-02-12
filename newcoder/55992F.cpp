#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    string a, b;
    while(cin >> a >> b){
        int f1 = 0,f2 = 0;
        int lena = a.size(), lenb = b.size();
        for(int i = 0; i < lena; ++ i)a += a[i];
        for(int i = 0; i < lenb; ++ i)b += b[i];
        while(a.size() < b.size())a += a[f1 ++];
        while(a.size() > b.size())b += b[f1 ++];
        if(a > b)cout << ">\n";
        else if(a < b)cout << "<\n";
        else cout << "=\n";
    }
}

signed main(){
    solve();
    return 0;
}