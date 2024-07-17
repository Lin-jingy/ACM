#include <bits/stdc++.h>

#define int long long 

class Lasting_tree {
    struct node { int L, R, cnt, sum; };
private:
    std::vector<node> tree;
	std::vector<int> version;
	int f = 1;
	int up, down;
    #define ls(p) tree[p].L
    #define rs(p) tree[p].R
    #define cnt(p) tree[p].cnt
    #define sum(p) tree[p].sum
    void pushUp(int p) { sum(p) = sum(ls(p)) + sum(rs(p)), cnt(p) = cnt(ls(p)) + cnt(rs(p)); }
    void update(int last, int now, int pos, int l, int r) {
        if (l == r) return sum(now) = sum(last) + l, cnt(now) = cnt(last) + 1, void();
        ls(now) = ls(last), rs(now) = rs(last);
        int mid = (l + r - 1) / 2;
        if (pos <= mid) ls(now) = ++f, update(ls(last), ls(now), pos, l, mid);
        else rs(now) = ++f, update(rs(last), rs(now), pos, mid + 1, r);
        pushUp(now);
    }
    int kth(int last, int now, int k, int l, int r) {
        if (l == r) return sum(now) - sum(last);
        int mid = (l + r - 1) / 2;
        int sum = sum(rs(now)) - sum(rs(last));
        if(sum >= k) return kth(rs(last), rs(now), k, mid + 1, r);
        else return kth(ls(last), rs(now), k - sum, l, mid);
    }
public:
    Lasting_tree(int n, int Down, int Up) : tree(50 * n), version(n + 1), up(Up), down(Down){}
    ~Lasting_tree() = default;
	void update(int last, int now, int pos) {
		version[now] = ++f;
		update(version[last], version[now], pos, down, up);
	}
	int kth(int last, int now, int k) {
		return kth(version[last], version[now], k, down, up);
	}
#undef ls
#undef rs
#undef sum
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            
        }
    }


    return 0;
}