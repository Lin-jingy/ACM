#include<bits/stdc++.h>

void solve(){
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int>p(26, -1);
    for(int i = 0; i < n; ++i){
        if(p[s[i] - 'a'] == -1) p[s[i] - 'a'] = i % 2;
        else if(p[s[i] - 'a'] != i % 2) goto A;
    }
    std::cout << "YES\n";
    return ;
    A:;
    fill(p.begin(), p.end(), -1);
    for(int i = 0; i < n; ++i){
        if(p[s[i] - 'a'] == -1) p[s[i] - 'a'] = 1 - (i % 2);
        else if(p[s[i] - 'a'] != 1 - (i % 2)) {
            std::cout << "NO\n";
            return ;
        }
    }
    std::cout << "YES\n";
    return ;
}
signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--)solve();
    return 0;
}