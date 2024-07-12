#include <bits/stdc++.h>

class Lasting_tree {
    struct node { int L, R, sum; };
private:
    std::vector<node> tree;
	std::vector<int> version;
    int n;
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
    int query(int last, int now, int l, int r, int i, int j) {
        if (l == r) return sum(l);
        int mid = (l + r - 1) / 2;
        int SUM = 0;
        if(i <= mid) SUM += query(last, now, l, mid, i, j);
        if(j > mid) SUM += query(last, now, mid + 1, r, i, j);
        return SUM;
    }
public:
    Lasting_tree(int n, int Down, int Up) : tree(50 * n), version(n + 1), up(Up), down(Down){
        this->n = n;
    }
    ~Lasting_tree() = default;
	void update(int last, int now, int pos, int val) {
		version[now] = ++f;
		update(version[last], version[now], pos, val, down, up);
	}
    int Query(int last, int now, int l, int r) { return query(last, now, 1, n, l, r); }
#undef ls
#undef rs
#undef sum
};

int main() {
    Lasting_tree T()
}