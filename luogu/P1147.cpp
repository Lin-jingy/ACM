#include<bits/stdc++.h>

#define int long long 
using PII = std::pair<int, int>;
const int N = 2e6 + 5;
int a[N];
std::vector<PII>v;

void solve(){
    int n;
    std::cin >> n;
    for(int i = 1; i < N; ++ i)a[i] = a[i - 1] + i;
    auto it = std::upper_bound(a + 1, a + N, n) - a;
    for(int i = it; i < N; ++i){
        for(int j = i - 1; j >= 1; -- j){
            if(a[i] - a[j - 1] == n)v.push_back({j, i});
            if(a[i] - a[j - 1] > n)break;
        }
    }
    std::sort(v.begin(), v.end());
    for(auto i : v){
        std::cout << i.first << ' ' << i.second << '\n';
    }
}

signed main(){
    solve();
    return 0;
}