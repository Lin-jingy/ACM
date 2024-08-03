#include <bits/stdc++.h>

/**
 * @brief 求强连通分量
 * @param v 图
 * @note  O(n) 针对有向图
 * @return 割点编号
 */
static std::vector<int> Tarjan(std::vector<std::vector<int>> &v) {
    int cnt = 0, f = 0;
    std::vector<int> dfn(v.size()), low(v.size()), belong(v.size());
    std::stack<int> s;
    auto tarjan = [&](auto self, int p) -> void {
        dfn[p] = low[p] = ++cnt;  // 给时间戳
        s.push(p);
        for (auto i : v[p]) {
            if (!dfn[i]) {  // 未访问过
                self(self, i);
                low[p] = std::min(low[p], low[i]);
            } else if (!belong[i]) {
                low[p] = std::min(low[p], dfn[i]);
            }
        }
        if (dfn[p] == low[p]) {
            ++f;
            int node;
            do {
                node = s.top();
                s.pop();
                belong[node] = f;
            } while (node != p);
        }
    };
    tarjan(tarjan, 1);
    return belong;
}

/**
 * @brief 求割点
 * @param v 图
 * @param n 点数
 * @note  O(n) 针对有向图
 * @return 割点编号
 */
static std::vector<int> Tarjan(std::vector<std::vector<int>> &v, int n) {
    int cnt = 0;
    std::vector<int> dfn(v.size()), low(v.size());
    std::vector<int> result;
    int root = 0;
    auto tarjan = [&](auto self, int p) -> void {
        dfn[p] = low[p] = ++cnt;
        int son = 0;
        bool isG = 0;
        for (auto i : v[p]) {
            if (!dfn[i]) {
                ++son;
                self(self, i);
                low[p] = std::min(low[p], low[i]);
                if (low[i] >= dfn[p] and p != root) isG = 1;
            } else
                low[p] = std::min(low[p], dfn[i]);
        }
        if (son >= 2 and p == root) isG = 1;
        if (isG) result.push_back(p);
    };
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) root = i, tarjan(tarjan, i);
    }
    return result;
}