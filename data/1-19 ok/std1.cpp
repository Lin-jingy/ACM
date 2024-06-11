#include<bits/stdc++.h>
using ll = long long;
#define int long long
const int N = 5e5+5,mod = 998244353;
using namespace std;
int T,n,a[N],st[N],tp,sm[N],f[N],g[N];
void los(){
    cin >> n;tp = 0;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    f[0] = sm[0] = 1;
    for(int i = 1;i <= n;i ++){
        while(tp && a[st[tp]] > a[i]) tp --;
        int j = st[tp];if(j) g[i] = (f[j] + g[j]) % mod; else g[i] = 0;
        f[i] = (sm[i-1] - (j == 0 ? 0 : sm[j-1]) + g[j] + mod) % mod,
        sm[i] = (sm[i-1] + f[i]) % mod,st[++tp] = i;
    }cout << (f[n] + g[n]) % mod << std::endl;
}signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i = 1; i <= 12; ++i) {
        std::string address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/19/data/{}.in", i);
        std::string address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/19/data/{}.out", i);
        freopen(address1.c_str(), "r", stdin);
        freopen(address2.c_str(), "w", stdout);

        T = 0;
        n = 0;
        memset(a, 0, sizeof(a));
        memset(st, 0, sizeof(st));
        tp = 0;
        memset(sm, 0, sizeof(sm));
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));





        for(cin >> T;T --;) los();
        fclose(stdin);
        fclose(stdout);
    }
}