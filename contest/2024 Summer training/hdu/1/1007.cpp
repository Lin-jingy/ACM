#include <bits/stdc++.h>

class BIT{
#define lowb(x) ((-x) & x)
private:
    int n;
    std::vector<int> c;
public:
    BIT() = default;
    BIT(int N): n(N), c(N + 1){}
    void add(int i, int z){ 
        for(; i <= n; i += lowb(i)) c[i] += z; 
    }
    int pre(int i){ 
        int sum = 0;
        for (; i > 0; i -= lowb(i)) sum += c[i];
        return sum; 
    }
    int sum(int i, int j){ 
        return pre(j) - pre(i - 1); 
    }
#undef lowb
} T;

struct node {
    int f, g, du;
    auto operator<=> (const node &other) const = default;
} v[200005], mv[200005];
// std::vector<node> v, mv;
int n;

void dfs(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    dfs(l, mid), dfs(mid + 1, r);
    int i, j;
    for(i = l, j = mid + 1; j <= r; ++j) {
        while(i <= mid and v[i].f < v[j].f) T.add(v[i++].g, 1);
        v[j].du += T.pre(v[j].g - 1);
    }
    while(--i >= l) T.add(v[i].g, -1);
    for(i = mid, j = r; i >= l; --i) {
        while(j > mid and v[i].f < v[j].f) T.add(v[j--].g, 1);
        v[i].du -= T.pre(n) - T.pre(v[i].g);
    }
    while(++j <= r) T.add(v[j].g, -1);
    // std::sort(v.begin() + l, v.begin() + r + 1);
    // std::merge(v.begin() + l, v.begin() + 1 + mid, v.begin() + 1 + mid, v.begin() + 1 + r, mv.begin() + l);
    // std::copy(mv.begin() + l, mv.begin() + 1 + r, v.begin() + l);
    std::merge(v + l, v + mid + 1, v + mid + 1, v + r + 1, mv + l);
    // std::copy(mv + l, mv + r + 1, v + l);
    memcpy(v + l, mv + l, sizeof(node) * (r - l + 1));
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n;
    // v.assign(n + 1, {});
    // mv.assign(n + 1, {});
    T = std::move(BIT(n + 1));
    for(int i = 1; i <= n; ++i) std::cin >> v[i].f;
    for(int i = 1; i <= n; ++i) std::cin >> v[i].g;
    for(int i = 1; i <= n; ++i) v[i].du = n - i;

    dfs(1, n);
    long long ans = (long long)n * (n - 1) * (n - 2) / 6;
    for(int i = 1; i <= n; ++i) ans -= (long long)v[i].du * (v[i].du - 1) / 2;
    std::cout << ans << '\n';
    return 0;
}