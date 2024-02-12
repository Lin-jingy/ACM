// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

void print(std::vector<PII> &ans){
    std::cout << ans.size() << '\n';
    for(auto i:ans) std::cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}

void solve(){
    int n;
    std::cin >> n;
    std::vector<int>a(n);
    int mx(-inf), mn(inf);
    int mxi, mni;
    int num1(0), num0(0);
    for(int i(0); i < n; ++i) {
        std::cin >> a[i];
        a[i] > 0 ? ++num1 : ++num0;
        if(a[i] > mx) mx = a[i], mxi = i;
        if(a[i] < mn) mn = a[i], mni = i;
    }
    std::vector<PII>ans;
    std::vector<int>aa(a);
    if(mx > 0 and mn < 0){
        //全部转为正数
        std::vector<PII>ans1;
        if(num0 <= 7){
            while(abs(mx) <= 20){
                a[mxi] += mx;
                mx += mx;
                ans1.push_back({mxi, mxi});
            }
        }
        for(int i(0); i < n; ++i){
            while(a[i] < 0){
                a[i] += a[mxi];
                ans1.push_back({i, mxi});
            }
        }
        //全部转为负数
        std::vector<PII>ans2;
        if(num1 <= 7){
            while(abs(mn) <= 20){
                aa[mni] += mn;
                mn += mn;
                ans2.push_back({mni, mni});
            }
        }
        for(int i(0); i < n; ++i){
            while(aa[i] > 0){
                aa[i] += aa[mni];
                ans2.push_back({i, mni});
            }
        }
        if(ans1.size() > ans2.size()){
            ans = ans2;
            goto B;
        }else{
            ans = ans1;
            goto A;
        }
    }

    if(mn >= 0){//全为正数
        A:;
        for(int i = 1; i < n; ++i) if(a[i] < a[i - 1]) a[i] += a[i - 1], ans.push_back({i, i - 1});
        print(ans);
        return;
    }

    if(mx <= 0){//全为负数
        B:;
        for(int i = n - 2; i >= 0; --i) if(aa[i] > aa[i + 1]) aa[i] += aa[i + 1], ans.push_back({i, i + 1});
        print(ans);
        return;
    }
    
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
