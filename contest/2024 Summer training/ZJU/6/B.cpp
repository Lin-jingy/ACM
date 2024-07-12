#include <bits/stdc++.h>

int n, m, a, b, c, xa, xb, xc;
std::vector<std::array<int, 4>> ans;

std::pair<int, int> calc(int x, int y) {
    return {(x - 1) * 1000, (y - 1) * 1000};
}

void init1() {
    ans.push_back({0, 1, 1, 1001});
    ans.push_back({1000, 0, 1001, 1000});
    ans.push_back({0, 0, 1000, 1});
    ans.push_back({1, 1000, 1001, 1001});
    xb -= 4;
}

void init2() {
    ans.push_back({0, 0, 1, 1001});
    ans.push_back({1000, 0, 1001, 1001});
    ans.push_back({1, 0, 1000, 1});
    ans.push_back({1, 1000, 1000, 1001});
    xa -= 2;
    xc -= 2;
}

void init3() {
    ans.push_back({0, 1, 1, 1001});
    ans.push_back({1000, 1, 1001, 1000});
    ans.push_back({0, 0, 1001, 1});
    ans.push_back({1, 1000, 1001, 1001});
    xa--, xb -= 2, xc--;
}

void build_left() {
    for(int i = 2; i <= n; ++i) {
        auto [bx, by] = calc(i, 1);
        if(xc) {
            ans.push_back({bx + 1, by, bx + 1000, by + 1});
            ans.push_back({bx + 1, by + 1000, bx + 1000, by + 1001});
            ans.push_back({bx + 1000, by, bx + 1001, by + 1001});
            xa -= 2;
            xc--;
        } else {
            ans.push_back({bx + 1, by, bx + 1001, by + 1});
            ans.push_back({bx + 1, by + 1000, bx + 1001, by + 1001});
            ans.push_back({bx + 1000, by + 1, bx + 1001, by + 1000});
            xa--;
            xb -= 2;
        } 
    }
}

void build_right() {
    for(int i = 2; i <= m; ++i) {
        auto [bx, by] = calc(1, i);
        if(xc) {
            ans.push_back({bx, by + 1, bx + 1, by + 1000});
            ans.push_back({bx + 1000, by + 1, bx + 1001, by + 1000});
            ans.push_back({bx, by + 1000, bx + 1001, by + 1001});
            xa -= 2;
            xc--;
        } else {
            ans.push_back({bx, by + 1, bx + 1, by + 1001});
            ans.push_back({bx + 1000, by + 1, bx + 1001, by + 1001});
            ans.push_back({bx + 1, by + 1000, bx + 1000, by + 1001});
            xa--;
            xb -= 2;
        }
    }
}

void build_other() {
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            auto [bx, by] = calc(i, j);
            ans.push_back({bx + 1000, by + 1, bx + 1001, by + 1000});
            ans.push_back({bx + 1, by + 1000, bx + 1001, by + 1001});
            --xa, --xb;
        }
    }
}
int maxx, maxy;
void print() {
    assert(ans.size() == 2 * n * m + n + m);
    assert(ans.size() == a + b + c);
    for(auto [a,b,c,d]:ans) {
        assert(a <= maxx and b <= maxy and c <= maxx and d <= maxy);
        std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
    // exit(0);
} 

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m >> a >> b >> c;
    maxx = 1000 * n + 1, maxy = 1000 * m + 1;

    xa = a, xb = b, xc = c;
    ans.clear();
    init1();
    build_left();
    build_right();
    build_other();
    if(xa == 0 and xb == 0 and xc == 0) {
        print();
        return 0;
    }

    xa = a, xb = b, xc = c;
    ans.clear();
    init2();
    build_left();
    build_right();
    build_other();
    if(xa == 0 and xb == 0 and xc == 0) {
        print();
        return 0;
    }


    xa = a, xb = b, xc = c;
    ans.clear();
    init3();
    build_left();
    build_right();
    build_other();
    if(xa == 0 and xb == 0 and xc == 0) {
        print();
        return 0;
    }
    
    assert(0);



    return 0;
}