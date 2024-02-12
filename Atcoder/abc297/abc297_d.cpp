#include<bits/stdc++.h>

#define int long long

void solve(){
    int a, b;
    std::cin >> a >> b;
    int sum = 0;
    while(a != b){
        if(a > b)std::swap(a, b);
        if(a == 1) sum += b - 1, b = 1;
        else {
            if((b - a) / a >= 1){
                sum += (b - a) / a;
                b -= (b - a) / a * a;
            }else sum++, b -= a;
            
        }
    }
    std::cout << sum;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}