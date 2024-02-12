#include<bits/stdc++.h>

#define int long long 
const int N = 2e5 + 5;

std::multiset<int>s[N];
std::set<int>st[N];

void solve(){
    int n, q;
    std::cin >> n >> q;
    while(q--){
        int op, x, y;
        std::cin >> op;
        if(op == 1){
            std::cin >> x >> y;
            s[y].insert(x);
            st[x].insert(y);
        }else if(op == 2){
            std::cin >> x;
            for(auto i : s[x])std::cout << i << ' ';
            std::cout << '\n';
        }else if(op == 3){
            std::cin >> x;
            for(auto i : st[x])std::cout << i << ' ';
            std::cout << '\n';
        }
    }
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}