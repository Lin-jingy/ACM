#include <bits/stdc++.h>

#define int long long


signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, k;
    std::cin >> n >> k;
    //std::vector<int> mpx, mpy;
    std::map<int, int> mpx, mpy;
    for(int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        mpx[x]++, mpy[y]++;
        //mpx.emplace_back(x);
        //mpy.emplace_back(y);
    }
    //std::sort(mpx.begin(), mpx.end());
    //std::sort(mpy.begin(), mpy.end());
    auto check1 = [&](int x) -> bool {
        int rk = k;
        std::map<int, int> mx(mpx);
        while(mx.rbegin()->first - mx.begin()->first > x) {
            if(mx.rbegin()->second >= mx.begin()->second) {
                int ch1 = (++mx.begin())->first - mx.begin()->first;
                int ch2 = mx.rbegin()->first - mx.begin()->first - x;
                int ch = std::min(ch1, ch2);
                int num = mx.begin()->second;
                int pos = mx.begin()->first;
                if(num * ch > rk) return false;
                rk -= num * ch;
                mx.erase(mx.begin());
                mx[pos + ch] += num;
            }else {
                int ch1 = mx.rbegin()->first - (++mx.rbegin())->first;
                int ch2 = mx.rbegin()->first - mx.begin()->first - x;
                int ch = std::min(ch1, ch2);
                int num = mx.rbegin()->second;
                int pos = mx.rbegin()->first;
                if(num * ch > rk) return false;
                rk -= num * ch;
                mx.erase(--mx.end());
                mx[pos - ch] += num;
            }
        }
        mx = mpy;
        while(mx.rbegin()->first - mx.begin()->first > x) {
            if(mx.rbegin()->second >= mx.begin()->second) {
                int ch1 = (++mx.begin())->first - mx.begin()->first;
                int ch2 = mx.rbegin()->first - mx.begin()->first - x;
                int ch = std::min(ch1, ch2);
                int num = mx.begin()->second;
                int pos = mx.begin()->first;
                if(num * ch > rk) return false;
                rk -= num * ch;
                mx.erase(mx.begin());
                mx[pos + ch] += num;
            }else {
                int ch1 = mx.rbegin()->first - (++mx.rbegin())->first;
                int ch2 = mx.rbegin()->first - mx.begin()->first - x;
                int ch = std::min(ch1, ch2);
                int num = mx.rbegin()->second;
                int pos = mx.rbegin()->first;
                if(num * ch > rk) return false;
                rk -= num * ch;
                mx.erase(--mx.end());
                mx[pos - ch] += num;
            }
        }
        return true;
    };
    int l = 0, r = 1e9, ans;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check1(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    std::cout << ans << '\n';

    return 0;
}
