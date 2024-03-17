#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma clang diagnostic ignored "-Wunused-value"
// #pragma clang diagnostic ignored "-Wshift-op-parentheses"
#define LOG(x) if(!(x)){std::cout<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define LOG(x)
#endif
#define rep(i,b,e) for(int i=b;i<(int)(e);++i)
#define range(i,b,e,step) for(int i=b;(b<e?i<e:i>e);i+=(b<e?step:-step))
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX;
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream&in,std::vector<T>&v) 
{for(auto &i:v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream&out,const std::vector<T>&v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T,class FUN>void foreach
(std::vector<T>&v,FUN fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template <class T>void sort(std::vector<T>&v) {std::sort(v.begin(),v.end());}
template <class T,class FUN>void sort(std::vector<T>&v,FUN fun) 
{std::sort(v.begin(),v.end(),fun);}template<class T>void input
(T begin,T end){while(begin!=end)std::cin>>*begin++;}
using Pii = std::pair<int, int>;

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

struct node {
    int l, r, id;
};

void solve() {
    int n, k;
    std::cin >> n >> k;
    vec<node> v(n + 1);
    rep(i, 1, n + 1) std::cin >> v[i].l >> v[i].r, v[i].id = i;
    std::sort(v.begin() + 1, v.end(), [](node a, node b) {
        return a.l < b.l;
    });
    Lasting_tree T(n + 1, -1e9, 1e9);
    rep(i, 1, n + 1) {
        T.update(i - 1, i, v[i].r, 1);
    }
    int mx = 0, L;
    rep(i, k, n + 1) {
        int K = T.kth(0, i, i - k + 1);
        if(K - v[i].l + 1 > mx) {
            mx = K - v[i].l + 1;
            L = v[i].l;
        }
    }
    int R = L + mx - 1;
    std::cout << mx << '\n';
    if(mx == 0) {
        for(int i = 1; i <= k; ++i) {
            std::cout << v[i].id << ' ';
        }
    } else {
        rep(i, 1, n + 1) {
            if(k == 0) break;
            if(v[i].l <= L and v[i].r >= R) std::cout << v[i].id << ' ', --k;
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
