#include <bits/stdc++.h>

class BIT{
#define lowb(x) ((-x) & x)
private:
    int n;
    std::vector<int> c;
public:
    BIT() = default;
    BIT(int N):n(N), c(N+1){}
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
    int a, b, c, ans, cnt;
    auto operator<=> (const node &other) const = default;
};
std::vector<node> v, mv;

void dfs(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    dfs(l, mid);
    dfs(mid + 1, r);
    int i, j;
    for(i = l, j = mid + 1; j <= r; ++j) {
        while(i <= mid and v[i].b <= v[j].b) T.add(v[i].c, v[i].cnt), ++i; 
        v[j].ans += T.pre(v[j].c);
    }
    while(--i >= l) T.add(v[i].c, -v[i].cnt);
    std::merge(v.begin() + l, v.begin() + mid + 1, v.begin() + mid + 1, v.begin() + r + 1, mv.begin() + l, [](const node &a, const node &b) {
        if(a.b != b.b) return a.b < b.b;
        else return a.c < b.c;
    });
    std::copy(mv.begin() + l, mv.begin() + r + 1, v.begin() + l);
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    T = std::move(BIT(k + 1));
    v.assign(n + 1, {});
    mv.push_back({});

    for(int i = 1; i <= n; ++i) std::cin >> v[i].a >> v[i].b >> v[i].c;
    std::sort(v.begin() + 1, v.end());

    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        ++cnt;
        if(v[i].a != v[i + 1].a or v[i].b != v[i + 1].b or v[i].c != v[i + 1].c) {
            mv.push_back(v[i]);
            mv.back().cnt = cnt;
            cnt = 0;
        }
    }
    mv.swap(v);

    dfs(1, v.size() - 1);
    std::vector<int> ans(n);
    for(int i = 1; i < v.size(); ++i) {
        ans[v[i].ans + v[i].cnt - 1] += v[i].cnt;
    }
    for(int i = 0; i < n; ++i) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}