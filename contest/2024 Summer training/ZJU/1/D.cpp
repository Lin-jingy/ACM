#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;

class BIT{
#define lowb(x)((-x)&x)
private:int n;std::vector<int>c;std::vector<int>*a;
public:BIT(int N,std::vector<int>*A):n(N),c(n+1),a(A){
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=lowb(j))c[j]+=(*a)[i];}
void add(int i,int z){ (*a)[i]+=z;for(;i<=n;i+=lowb(i))c[i]+=z; }
int pre(int i){ int sum=0;for(;i>0;i-=lowb(i))sum+=c[i];return sum; }
int sum(int i,int j){ return pre(j) - pre(i - 1); }
#undef lowb
};


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    std::set<int> r0;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if(a[i] == 0) r0.insert(i);
    }
    BIT T(n + 1, &a);
    std::bitset<N> bit;
    for(int i = 1, x = 0; i <= n; ++i) {
        x += a[i];
        bit.set(x);
    }
    bit.set(0);
    while(q--) {
        int op;
        std::cin >> op;
        if(op == 1) {
            int x;
            std::cin >> x;
            if(x == 0) {
                if(r0.empty()) std::cout << -1 << '\n';
                else std::cout << *r0.begin() << ' ' << *r0.begin() << '\n';
                continue;
            }
            auto mid = (bit >> x) & bit;
            if(mid.count() == 0) {
                std::cout << -1 << '\n';
                continue;
            }
            int lval = mid._Find_first();
            int rval = lval + x;
            int Lpos, Rpos;
            {
                int l = 0, r = n;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(T.pre(mid) <= lval) l = mid + 1, Lpos = mid;
                    else r = mid - 1;
                }
            }
            {
                int l = 0, r = n;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(T.pre(mid) <= rval) l = mid + 1, Rpos = mid;
                    else r = mid - 1;
                }
            }
            std::cout << Lpos + 1 << ' ' << Rpos << '\n';
        } else {
            int pos, v;
            std::cin >> pos >> v;
            int lastPre = T.pre(pos);
            int ch = v - a[pos];
            bool it = bit[lastPre];
            auto rem = (bit << (N - lastPre)) >> (N - lastPre);
            bit = (bit >> lastPre) << lastPre;
            if(ch > 0) bit <<= ch;
            else bit >>= (-ch);
            bit |= rem;
            if(a[pos] == 0) bit[lastPre] = it;
            if(a[pos] == 0) r0.erase(pos);
            if(v == 0) r0.insert(pos);
            T.add(pos, v - a[pos]);
        }
    }

    return 0;
}