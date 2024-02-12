#include<bits/stdc++.h>

#define int long long

void solve() {
    int n, A, cf, cm, m;
    std::cin >> n >> A >> cf >> cm >> m;
    std::vector<int> a(n), r;
    for(auto &i:a) std::cin >> i;
    std::vector<int> ra(a);
    std::sort(a.begin(), a.end());
    int mx = 0, rm = m;
    std::map<int, int> mp;
    for(int i = n - 1; i >= 0; --i) {
        if(rm > A - a[i]) rm -= A - a[i], ++mx, r.push_back(a[i]);
        else {
            for(int j = 0; j <= i; ++j)mp[a[j]]++;
            break;
        }
    }
    std::sort(r.begin(), r.end(), std::greater<int>());
    if(mp.empty()) {
        std::cout << cf * n + cm * A << '\n';
        for(int i = 0; i < n; ++i) std::cout << A << ' ';
        return ;
    }
    int ans = 0, ff1 = 0, ff2 = 0;
    for(int i = mx; i >= 0; --i) {
        while(1) {
            if(mp.size() == 1) {
                int a1 = mp.begin()->first, num = mp.begin()->second;
                int st = rm / (a1 * num);
                rm -= st * (a1 * num);
                if(st != 0) {
                    mp.erase(mp.begin());
                    mp[a1 + st] += num;
                    mp[a1 + st] -= rm;
                    mp[a1 + st + 1] += rm;
                    rm = 0;
                }else {
                    mp.erase(mp.begin());
                    mp[a1] -= rm;
                    mp[a1 + 1] += rm;
                    rm = 0;
                }
                goto A;
            }   
            int a1 = mp.begin()->first, a2 = (++mp.begin())->first;
            int num = mp.begin()->second;
            if(rm == 0) goto A;
            if(rm <= (a2 - a1) * num) {
                int st = rm / num;
                rm -= st * ((a2 - a1) * num);
                mp.erase(mp.begin());
                mp[a1 + st] += num;
                mp[a1 + st] -= rm;
                mp[a1 + st + 1] += rm;
                rm = 0;
                break;
            }else {
                mp[a2] += num;
                mp.erase(mp.begin());
                rm -= (a2 - a1) * num;
            }
        }
        A:;
        if(cf * i + cm * mp.begin() ->first > ans) ans = cf * i + cm * mp.begin() ->first, ff1 = i, ff2 = mp.begin()->first;
        if(i == 0) break;
        mp[r.back()]++;
        rm += A - r.back();
        r.pop_back();
    }

    std::cout << ans << '\n';
    int mmm = 0;
    if(ff1 == 0) mmm = A;
    while(ff1--) {
        mmm = a.back();
        a.pop_back();
    }
    for(auto i:ra) {
        if(i >= mmm) std::cout << A << ' ';
        else std::cout << std::max(ff2, i) << ' ';
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}