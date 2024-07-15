#include <bits/stdc++.h>



static std::vector<std::vector<int>> 
Tarjan(std::vector<std::vector<int>> &v) {
    int cnt = 0;
    std::vector<std::vector<int>> component;
    std::vector<int> dfn(v.size()), low(v.size());
    std::vector<bool> instack(v.size());
    std::stack<int> s;
    auto tarjan = [&](auto self, int p) ->void {
        dfn[p] = low[p] = ++cnt;
        s.push(p);
        instack[p] = true;
        for (auto i:v[p]) {
            if (!dfn[i]) {
                self(self, i);
                low[p] = std::min(low[p], low[i]);
            } else if (instack[i]) {
                low[p] = std::min(low[p], dfn[i]);
            }
        }
        if (dfn[p] == low[p]) {
            component.push_back({});
            int node;
            do {
                node = s.top();
                s.pop();
                instack[node] = false;
                component.back().push_back(node);
            } while (node != p);
        }
    };
    tarjan(tarjan, 1);
    return component;
}