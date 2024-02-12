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
    string a, b;
    cin >> a >> b;
    int lena = a.size(), lenb = b.size();
    int ans = 0;
    if(lena < lenb){
        ans += 9 * lena;
        int k = 0, k1 = 0;
        for(int i = 0; i < lenb - lena; ++i)k += (b[i] - '0');
        k1 += b[0] - '0';
        for(int i = 1; i < lenb - lena; ++i)k1 += 9;
        ans += max(k, k1);
    }else{
        while(!a.empty() and *a.begin() == *b.begin())a.erase(0, 1), b.erase(0, 1);
        if(a.empty())goto A;
        ans += 9 * ((int)a.size() - 1);
        ans += abs(b[0] - a[0]);
    }
    A:;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
