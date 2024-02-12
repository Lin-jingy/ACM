#include<bits/stdc++.h>

int main(){
    int n, l, r, x, ans = 0;
    std::cin >> n >> l >> r;

    auto sg = [&](int x){
        x %= l + r ;
        return x / l;
    };

    for(int i = 1; i <= n; ++i) std::cin >> x, ans ^= sg(x);

    std::cout << (ans ? "First":"Second");

    return 0;
}