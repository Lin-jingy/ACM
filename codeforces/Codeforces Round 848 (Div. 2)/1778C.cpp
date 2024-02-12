#include<bits/stdc++.h>

std::string a, b;
std::set<char> us, mp;
int n, k;
long long ans;

void dfs(std::set<char>::iterator it, int num) {
    if(num == k) {
        std::string s = a;
        for(int i = 0; i < n; ++i) {
            if(us.count(s[i])) s[i] = b[i];
        }
        int kk = 0;
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == b[i]) ++kk;
            else sum += (1ll * kk * (1 + kk)) / 2, kk = 0;
        }
        sum += (1ll * kk * (1 + kk)) / 2;
        ans = std::max(ans, sum);
        return ;
    }
    for(auto i = it; i != mp.end(); ++i) {
        us.insert(*i);
        dfs(++i, num + 1);
        us.erase(*(--i));
    }
}

void solve() {
    std::cin >> n >> k;
    std::cin >> a >> b;
    mp.clear();
    ans = 0;             

    for(int i = 0; i < n; ++i) mp.insert(a[i]);

    if(mp.size() <= k) {
        std::cout << (1ll * n * (1 + n)) / 2 << '\n';
        return ;
    }
    dfs(mp.begin(), 0);
    std::cout << ans << '\n';


}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}