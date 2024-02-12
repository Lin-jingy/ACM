#include<bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n;
    
    std::vector<int>a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    std::vector<int>x, y;
    for(int i = 0; i < n; ++i){
        if(a[i] == a.front()) x.push_back(a[i]);
        else y.push_back(a[i]);
    }

    if(!x.empty() and !y.empty()){
        std::cout << x.size() << ' ' << y.size() << '\n';
        for(auto i:x) std::cout << i << ' ';
        std::cout << '\n';
        for(auto i:y) std::cout << i << ' ';
        std::cout << '\n';
    }else std::cout << -1 << '\n';
    
}

int main(){
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}