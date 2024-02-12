#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n + 1), pre(n + 1);
    int ans0 = 0, ans1 = 0;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    std::string s;
    std::cin >> s;
    for(int i = 1; i <= n; ++i){
        if(s[i - 1] == '1') ans1 ^= a[i];
        else ans0 ^= a[i];
    }
    int q;
    std::cin >> q;
    while(q--){
        int op;
        std::cin >> op;
        if(op == 1){
            int l, r;
            std::cin >> l >> r;
            ans0 ^= (pre[r] ^ pre[l - 1]);
            ans1 ^= (pre[r] ^ pre[l - 1]);
        }else{
            int g;
            std::cin >> g;
            std::cout << (g ? ans1 : ans0) << ' ';
        }
    }
    std::cout << '\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}