#include<bits/stdc++.h>

#define int long long 
const int N = 2e5 + 5;
using PII = std::pair<int, int>;
std::vector<PII>v;

class node{
public:
    int color, rank;
};

node a[N];

void solve(){
    int n, t;
    std::cin >> n >> t;    
    for(int i = 1; i <= n; ++ i)std::cin >> a[i].color;
    for(int i = 1; i <= n; ++ i)std::cin >> a[i].rank;
    int mx = 0, mxt = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i].color == t){
            if(mxt == 0 or a[i].rank > a[mxt].rank)mxt = i;
        }else if(a[i].color == a[1].color){
            if(mx == 0 or a[i].rank > a[mx].rank)mx = i;
        }  
    }
    if(mxt == 0)std::cout << mx;
    else std::cout << mxt;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}