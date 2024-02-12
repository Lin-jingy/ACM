#include<bits/stdc++.h>

#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(auto &i:a) std::cin >> i;
    std::map<int, int> mp;
    std::vector<int> l(n), r(n);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        mp[a[i]]++;
        l[i] = mp[a[i]];
    }
    mp.clear();
    for(int i = n - 1; i >= 0; --i) {
        mp[a[i]]++;
        r[i] = mp[a[i]];
    }
    
    auto merge_sort = [&](auto merge_sort, int b, int e) ->void {
        if(b == e)return;
        int mid = (b + e) / 2, i = b, j = mid + 1, k = b;
        merge_sort(merge_sort, b, mid), merge_sort(merge_sort, mid + 1, e);
        while(i <= mid && j <= e)
        	if(l[i] <= r[j]) i++;
        	else j++, ans += mid - i + 1;
        std::sort(l.begin() + b, l.begin() + e + 1);
        std::sort(r.begin() + b, r.begin() + e + 1);
    };
    merge_sort(merge_sort, 0, n - 1);
    std::cout << ans << '\n';
    return 0;
}