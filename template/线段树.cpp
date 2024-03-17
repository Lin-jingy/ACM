#include <bits/stdc++.h>


class SegmentTree {
private:
    struct Treenode {
        int f, tag;
    };
    std::vector<Treenode> v;
    std::vector<int> a;
#define f(x) (v[x].f)
#define tag(x) (v[x].tag)
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void pushDown(int p, int l, int r) {
        if (!tag(p)) return;
        int mid = (l + r) >> 1;
        f(ls(p)) += tag(p) * (mid - l + 1);
        f(rs(p)) += tag(p) * (r - mid);
        tag(ls(p)) += tag(p);
        tag(rs(p)) += tag(p);
        tag(p) = 0;
    }
    void pushUp(int p) {
        f(p) = f(ls(p)) + f(rs(p));
    }

public:
    SegmentTree(int n) {
        a.assign(n + 10, 0);
        v.assign(n << 3, {});
    }
    void build(int p, int l, int r) {
        if (l == r) {
            f(p) = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        pushUp(p);
    }
    void update(int p, int l, int r, int i, int j, int d) {
        pushDown(p, l, r);
        if (i <= l and j >= r) {
            tag(p) = tag(p) + d;
            f(p) = f(p) + d * (r - l + 1);
            return;
        }
        int mid = (l + r) >> 1;
        if (i <= mid) update(ls(p), l, mid, i, j, d);
        if (j > mid) update(rs(p), mid + 1, r, i, j, d);
        pushUp(p);
    }
    int query(int p, int l, int r, int i, int j) {
        if (i <= l and j >= r) return f(p);
        pushDown(p, l, r);
        int mid = (l + r) >> 1, sum = 0;
        if (i <= mid) sum += query(ls(p), l, mid, i, j);
        if (j > mid) sum += query(rs(p), mid + 1, r, i, j);
        return sum;
    }
};


//主席树（可持久化线段树）
class Lasting_tree {
    struct node { int L, R, sum; };
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
        if (pos <= mid) ls(now) = ++f, update(ls(last), ls(now), pos, val, l, mid);
        else rs(now) = ++f, update(rs(last), rs(now), pos, val, mid + 1, r);
        pushUp(now);
    }
    int kth(int last, int now, int k, int l, int r) {
        if (l == r) return l;
        int mid = (l + r - 1) / 2;
        int SUM = sum(ls(now)) - sum(ls(last));
        if(SUM >= k) return kth(ls(last), ls(now), k, l, mid);
        else return kth(rs(last), rs(now), k - SUM, mid + 1, r);
    }
public:
    Lasting_tree(int n, int Down, int Up) : tree(50 * n), version(n + 1), up(Up), down(Down){}
    ~Lasting_tree() = default;
	void update(int last, int now, int pos, int val) {
		version[now] = ++f;
		update(version[last], version[now], pos, val, down, up);
	}
	int kth(int last, int now, int k) {
		return kth(version[last], version[now], k, down, up);
	}
};