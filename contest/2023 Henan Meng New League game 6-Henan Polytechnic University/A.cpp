#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;

    std::vector<int>a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    // std::vector<int>pre(n + 1);
    // for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] ^ a[i];

    std::vector<std::vector<int>>pre(n + 1);
    pre[0] = std::vector<int>(32);
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1];
        for(int j = 0; j < 31; ++j){
            if((a[i] >> j) & 1) pre[i][j]++;
        }
    }
    int q;
    std::cin >> q;
    while(q--){
        int l, r;
        std::cin >> l >> r;
        int len = r - l + 1;
        std::vector<int>p = pre[r];
        for(int i = 0; i < 31; ++i) p[i] -= pre[l - 1][i];
        int k = 0;
        for(int i = 0; i < 31; ++i) if(p[i] >= (len + 1) / 2) k += (1 << i);


        int ans = ((1ll << 31) - 1 - k);

        std::cout << ans << '\n';
    }

}