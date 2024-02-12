#include<bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 5;

signed main(){
    int n, q;
    std::cin >> n >> q;

    const int block = sqrt(n);

    class node{public:i64 l, r, id;};
    auto cmp = [&](node a, node b){
        if(a.l / block == b.l / block) return a.r < b.r;
        else return a.l  < b.l;
    };

    std::vector<int>a(n + 1);
    node *qes = (node*)malloc((q + 10) * sizeof (node));

    for(int i(1); i <= n; ++i) std::cin >> a[i];
    for(int i(1); i <= q; ++i) std::cin >> qes[i].l >> qes[i].r, qes[i].id = i;

    std::sort(qes + 1, qes + 1 + q, cmp);

    i64 ans(0);
    std::vector<int>cnt(N);
    std::vector<i64>p(q + 1);
    auto add = [&](i64 id){
	    cnt[a[id]]++;
	    if(cnt[a[id]] >= 3) ans += (1ll * cnt[a[id]] - 1) * (1ll * cnt[a[id]] - 2) / 2;
    };   
    auto del = [&](i64 id){
	    if(cnt[a[id]] >= 3) ans -= (1ll * cnt[a[id]] - 1) * (1ll * cnt[a[id]] - 2) / 2;
	    cnt[a[id]]--;
    };
    int l = 1, r = 0;
    for(int i(1); i <= q; ++i){
        while(r < qes[i].r) add(++r);
		while(r > qes[i].r) del(r--);
		while(l < qes[i].l) del(l++);
		while(l > qes[i].l) add(--l);
		p[qes[i].id] = ans;
    }
    for(int i(1); i <= q; ++i) std::cout << p[i] << '\n';

    return 0;
}