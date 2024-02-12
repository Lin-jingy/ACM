#include<bits/stdc++.h>

#define int long long

struct node {
    int h, a, b, c, d, e, w, ad;
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::deque<node> a, b;
    while(n--) {
        node x;
        std::cin >> x.h >> x.a >> x.b >> x.c >> x.d >> x.e >> x.w;
        x.ad = 0;
        a.push_back(x);
    }
    while(m--) {
        node x;
        std::cin >> x.h >> x.a >> x.b >> x.c >> x.d >> x.e >> x.w;
        x.ad = 0;
        b.push_back(x);
    }
    int flag = 0;
    while(k--) {
        if(a.empty()) {
            flag = 2;
            break;
        }
        if(b.empty()) {
            flag = 1;
            break;
        }
        node x = a.front();
        a.pop_front();
        node y = b.front();
        b.pop_front();
        std::vector<int>v;
        v.push_back(std::max(x.a-y.c,0LL));
        v.push_back(std::max(x.b-y.d,0LL));
        if(x.ad >= x.e) v.push_back(x.w);
        int mx = 0;
        for(int i = 1; i < v.size(); ++i) {
            if(v[i] > v[mx]) mx = i;
        }
        if(mx == 2) {
            x.ad -= x.e;
            y.h -= x.w;
        }else {
            x.ad++;
            y.h -= v[mx];
        }
        if(y.h <= 0) {
            if(b.empty()) {
                flag = 1;
                break;
            }
            y = b.front();
            b.pop_front();
        }
        a.push_back(x);
        x = a.front();
        a.pop_front();

        v.clear();
        v.push_back(std::max(y.a-x.c, 0LL));
        v.push_back(std::max(y.b-x.d, 0LL));
        if(y.ad >= y.e) v.push_back(y.w);
        mx = 0;
        for(int i = 1; i < v.size(); ++i) {
            if(v[i] > v[mx]) mx = i;
        }
        if(mx == 2) {
            y.ad -= y.e;
            x.h -= y.w;
        }else {
            y.ad++;
            x.h -= v[mx];
        }
        if(x.h > 0) a.push_front(x);
        b.push_back(y);
    }
    if(flag == 2) {
        std::cout << "Bob\n";
    }else if(flag == 1) {
        std::cout << "Alice\n";
    }else {
        std::cout << "Draw\n";
    }

    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}