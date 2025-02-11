#include <bits/stdc++.h>

template <class T>
concept checkTreeNode = requires(T t, T ls, T rs, int l, int r, int d) {
    { t.pushUp(ls, rs) };
    { t.pushDown(ls, rs, l, r) };
    { t.rangeChange(l, r, d) };
    { t.update(rs) };
    { t = ls };
    { t.get() };
};
template <checkTreeNode T>
class SegmentTree {
#define getmid ((l + r) >> 1)
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define lsArgs ls(p), l, mid
#define rsArgs rs(p), mid + 1, r

   private:
    void pushUp(int p) { data[p].pushUp(data[ls(p)], data[rs(p)]); }
    void pushDown(int p, int l, int r) {
        data[p].pushDown(data[ls(p)], data[rs(p)], l, r);
    }
    template <class X>
    void build(int p, int l, int r, const std::vector<X> &v) {
        if (l == r) {
            data[p] = v[l];
            return;
        }
        int mid = getmid;
        build(lsArgs, v);
        build(rsArgs, v);
        pushUp(p);
    }
    void update(int p, int l, int r, int i, int j, int d) {
        if (i <= l && j >= r) {
            data[p].rangeChange(l, r, d);
            return;
        }
        pushDown(p, l, r);
        int mid = getmid;
        if (i <= mid) update(lsArgs, i, j, d);
        if (j > mid) update(rsArgs, i, j, d);
        pushUp(p);
    }

    void set(int p, int l, int r, int pos, int d) {
        if (l == r) return data[p] = d, void();
        pushDown(p, l, r);
        int mid = getmid;
        if (pos <= mid) set(lsArgs, pos, d);
        else set(rsArgs, pos, d);
        pushUp(p);
    }

    T query(int p, int l, int r, int i, int j) {
        if (i <= l && j >= r) return data[p];
        pushDown(p, l, r);
        int mid = getmid;
        T x;
        if (i <= mid) x.update(query(lsArgs, i, j));
        if (j > mid) x.update(query(rsArgs, i, j));
        return x;
    }

   public:
    SegmentTree() = default;

    SegmentTree(int n) : data(n << 2) {}

    template <class X>
    SegmentTree(const std::vector<X> &v)
        : n(v.size() - 1), data(v.size() << 2) {
        build(1, 1, n, v);
    }

    void update(int l, int r, int d) { update(1, 1, n, l, r, d); }
    auto query(int l, int r) { return query(1, 1, n, l, r).get(); }
    void set(int pos, int d) { set(1, 1, n, pos, d); }

   private:
    std::vector<T> data;
    int n;
};

struct node {
    int sum = 0, tag = 0;
    void pushUp(const node &ls, const node &rs) {}
    void pushDown(node &ls, node &rs, int l, int r) {}
    void rangeChange(int l, int r, int d) {  // update
    }
    void operator=(int x) {}       // build赋值
    void update(const node &x) {}  // query
    int get() {}                   // query
};

// 主席树（可持久化线段树）
class Lasting_tree {
    struct node {
        int L, R, sum;
    };

   private:
    std::vector<node> tree;
    std::vector<int> version;
    int f = 1;
    int up, down;
#define ls(p) tree[p].L
#define rs(p) tree[p].R
#define sum(p) tree[p].sum
    void pushUp(int p) { sum(p) = sum(ls(p)) + sum(rs(p)); }
    void update(int last, int now, int pos, int val, int l, int r) {
        if (l == r) return sum(now) = sum(last) + val, void();
        ls(now) = ls(last), rs(now) = rs(last);
        int mid = (l + r - 1) / 2;
        if (pos <= mid)
            ls(now) = ++f, update(ls(last), ls(now), pos, val, l, mid);
        else rs(now) = ++f, update(rs(last), rs(now), pos, val, mid + 1, r);
        pushUp(now);
    }
    int kth(int last, int now, int k, int l, int r) {
        if (l == r) return l;
        int mid = (l + r - 1) / 2;
        int SUM = sum(ls(now)) - sum(ls(last));
        if (SUM >= k) return kth(ls(last), ls(now), k, l, mid);
        else return kth(rs(last), rs(now), k - SUM, mid + 1, r);
    }

   public:
    Lasting_tree(int n, int Down, int Up)
        : tree(50 * n), version(n + 1), up(Up), down(Down) {}
    ~Lasting_tree() = default;
    void update(int last, int now, int pos, int val) {
        version[now] = ++f;
        update(version[last], version[now], pos, val, down, up);
    }
    int kth(int last, int now, int k) {
        return kth(version[last], version[now], k, down, up);
    }
#undef ls
#undef rs
#undef sum
};