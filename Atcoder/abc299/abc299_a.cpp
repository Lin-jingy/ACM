#include<bits/stdc++.h>

#define int long long 
using PII = std::pair<int, int>;

void solve(){
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;
    PII k = {-1, -1};
    int flag = 0;
    for(int i = 0; i < a.size(); ++ i){
        if(a[i] == '|'){
            if(k.first == -1)k.first = i;
            else k.second = i;
        }
        if(a[i] == '*')flag = i;
    }
    if(flag >= k.first and flag <= k.second)std::cout << "in";
    else std::cout << "out";

}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}