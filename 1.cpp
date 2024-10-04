#include <bits/stdc++.h>

using Pii = std::pair<int, int>;

class DSU {
   private:
    std::vector<int> f;
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

   public:
    DSU(int n) : f(n + 1) {
        for (int i = 0; i <= n; i++) f[i] = i;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) {
        if (!same(x, y)) f[find(x)] = find(y);
    }
};

template <class K, class V>
struct std::hash<std::pair<K, V>> {
    size_t operator()(const std::pair<K, V> &p) const {
        return std::hash<K>{}(p.first) ^ std::hash<V>{}(p.second);
    }
};

struct node {
    int dis;
    int from, to;
    bool operator<(const node &rhs) const { return dis > rhs.dis; }
};

int getDis(Pii a, Pii b) {
    return std::sqrt((a.first - b.first) * (a.first - b.first) +
                     (a.second - b.second) * (a.second - b.second));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;  // n组
    std::cin >> n;
    std::vector<std::vector<Pii>> v(n);
    std::vector<Pii> list;

    std::unordered_map<Pii, int> mp;

    Pii tmp;

    int tot = 0;
    int f = 0;
    for (int i = 0; i < n; ++i) {
        int m;  // 每组的点数
        std::cin >> m;
        tot += m;
        for (int j = 0; j < m; ++j) {
            std::cin >> tmp.first >> tmp.second;
            v[i].push_back(tmp);
            list.push_back(tmp);
            mp[tmp] = f++;
        }
    }

    DSU T(tot + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < v[i].size(); ++j) {
            T.merge(mp[v[i][j - 1]], mp[v[i][j]]);
        }
    }

    std::priority_queue<node> q;

    for (int i = 0; i < list.size(); ++i)
        for (int j = i + 1; j < list.size(); ++j)
            q.emplace(getDis(list[i], list[j]), i, j);

    std::unordered_set<std::pair<int, int>> ans;

    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (T.same(t.from, t.to)) continue;
        T.merge(t.from, t.to);
        ans.insert(list[t.from]);
        ans.insert(list[t.to]);
    }

    for (auto [x, y] : ans) std::cout << x << ' ' << y << '\n';

    return 0;
}
