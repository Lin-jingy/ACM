#include <bits/stdc++.h>

// 注意空间，尽量取消define int long long
class SAM {
   private:
    struct state {
        int len, fa;
        std::array<int, 26> nxt;
        // 或者使用std::map以节省空间
    };
    std::vector<state> v;
    int last = 1, tot = 1;

   public:
    SAM(int n) : v(n + n + 10) {}
    void add(char C) {
        int c = C - 'a';  // 注意映射关系
        int p = last, cur = last = ++tot;
        v[cur].len = v[p].len + 1;
        for (; p && !v[p].nxt[c]; p = v[p].fa) v[p].nxt[c] = cur;
        if (p == 0) v[cur].fa = 1;
        else {
            int q = v[p].nxt[c];
            if (v[p].len + 1 == v[q].len) v[cur].fa = q;
            else {
                int clone = ++tot;
                v[clone] = v[q];
                v[clone].len = v[p].len + 1;
                for (; p && v[p].nxt[c] == q; p = v[p].fa) v[p].nxt[c] = clone;
                v[cur].fa = v[q].fa = clone;
            }
        }
    }
};