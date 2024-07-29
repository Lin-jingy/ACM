#pragma GCC optimize(3,"Ofast","inline")

#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, P = 998244353;
int p[N], pc[N][2], f[N], t;
char s[N];

signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    scanf("%d%s", &t, s+1);
    int n = strlen(s+1);
    if(n >= t) {
        for(int i = 0; i <= t; i++) cout << "0 ";
        cout << "\n";
        return 0;
    }
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1]) j = p[j];
        if (s[j + 1] == s[i]) j++;
        p[i] = j;
    }
    f[0] = 1;
    t-=n;
    for(int i = 0; i < n; i++) {
        pc[i][s[i+1]-'a'] = i+1;
        pc[i][(s[i+1]-'a')^1] = pc[p[i]][(s[i+1]-'a')^1];
        int v = i - pc[i][(s[i+1]-'a')^1] + 1;
        for (int j = t; j >= v; j--) {
            f[j] += f[j-v];
            if(f[j] >= P) f[j] -= P;
        }
    }
    for(int i = 0; i < n; i++) cout << "0 ";
    for (int i = 0; i <= t; i++) cout << f[i] << ' ';
    cout << '\n';
    return 0;
}