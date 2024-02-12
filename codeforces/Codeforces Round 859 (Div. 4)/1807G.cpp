#include<bits/stdc++.h>

void solve(){
    int n, x;
    std::cin >> n;
    std::vector<int>a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    long long sum = 0;
    for(auto i:a){
        if(i == 1) {
            sum += i;
            continue;
        }
        if(i > sum){
            std::cout << "NO\n";
            return ;
        }
        sum += i;
    }
    std::cout << "YES\n";
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}