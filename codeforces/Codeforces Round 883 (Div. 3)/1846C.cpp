#include<bits/stdc++.h>

#define int long long

signed main(){
    int T;
    std::cin >> T;
    while(T--){
        int n, m, h;
        std::cin >> n >> m >> h;
        
        std::vector<std::vector<int>>a(n, std::vector<int>(m));
        for(int i(0); i < n; ++i) for(int j(0); j < m; ++j) std::cin >> a[i][j];
        for(int i(0); i < n; ++i) std::sort(a[i].begin(), a[i].end());

        //std::vector<std::pair<int, int>>p;
        int ans(1);
        std::pair<int, int>x;
        for(int i(0); i < n; ++i){
            std::pair<int, int>p;
            int t = 0;
            for(int j(0); j < m; ++j){
                if(t + a[i][j] <= h) t += a[i][j], p.first += t, p.second++;
            }
            if(!i) x = p;
            else {
                if(p.second > x.second) ++ans;
                else if(p.second == x.second and p.first < x.first) ++ans;
            }
        }

        std::cout << ans << '\n';



    }
}