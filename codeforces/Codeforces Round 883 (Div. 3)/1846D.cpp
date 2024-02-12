#include<bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int T;
    std::cin >> T;

    while(T--){
        int n;
        double d, h;
        std::cin >> n >> d >> h;
        std::vector<int>a(n);
        for(int i(0); i < n; ++i) std::cin >> a[i];

        std::sort(a.begin(), a.end());

        double ans = 0;
        for(int i = 0; i < n; ++i){
            if(i == n - 1 or a[i] + h <= a[i + 1]) ans += d * h / 2;
            else ans += (d + ((1 - (a[i + 1] - a[i]) / h) * d)) * (a[i + 1] - a[i]) / 2;
        }
        printf("%.7lf\n", ans);
        //std::cout << ans << '\n';
    }
}