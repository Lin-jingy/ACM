#include <bits/stdc++.h>

class DSU {
private:
    std::vector<int> f, siz;
public:
    DSU(int n):f(n + 1),siz(n + 1, 1) {
        for(int i = 1; i <= n; i++) f[i] = i;
    }
    int find(int x){ return x == f[x] ? x : f[x] = find(f[x]); }
    bool same(int x,int y){ return find(x) == find(y); }
    void merge(int x,int y) {
        if(!same(x, y)) siz[find(y)] += siz[find(x)], f[find(x)] = find(y);
    }
    int qsz(int x){ return siz[find(x)]; }
};