#include<bits/stdc++.h>

#define int long long 
using PII = std::pair<int, int>;

void solve(){
    std::string a;
    std::cin >> a;
    PII b = {-1, 0}, r = {-1, 0};
    int flag = 0;
    for(int i = 0; i < a.size(); ++ i){
        if(a[i] == 'B'){
            if(b.first == -1)b.first = i;
            else b.second = i;
        }
        if(a[i] == 'R'){
            if(r.first == -1)r.first = i;
            else r.second = i;
        }
        if(a[i] == 'K')flag = i;
    }
    if(b.first % 2 != b.second % 2 and flag > r.first and flag < r.second)std::cout << "Yes";
    else std::cout << "No";
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}