#include <bits/stdc++.h>

template <typename Node>
class SegmentTree {
#define ls (p << 1)
#define rs (p << 1 | 1)

   private:
    const int n;
    std::vector<Node> tree;

    void build(int p, int l, int r) {
        if (l == r) {
        }
    }

   public:
    SegmentTree(int _n) : n(_n), tree(_n << 2) {}
};
