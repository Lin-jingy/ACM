#include <bits/stdc++.h>

#define int long long

int ch(char s) {
    if (s >= '0' and s <= '9') return s - '0';
    return s - 'A' + 10;
}

char sg(int x) {
    if (x >= 0 and x <= 9) return '0' + x;
    return 'A' + x - 10;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::string s;
    std::cin >> n >> s >> m;
    int i10 = 0;
    int mid = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        i10 += mid * ch(s[i]);
        mid *= n;
    }
    std::vector<char> ans;
    while (i10) {
        ans.emplace_back(sg(i10 % m));
        i10 /= m;
    }
    while (!ans.empty() and ans.back() == 0) ans.pop_back();
    std::reverse(ans.begin(), ans.end());
    for (auto i : ans) std::cout << i;

    return 0;
}
