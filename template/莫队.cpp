#include <bits/stdc++.h>

//块的大小,一般为sqrt(n)
int size;
struct Query {
    int l, r, id;
    friend bool operator< (const Query &x, const Query &y) {
        if(x.l / size != y.l / size) return x.l < y.l;
        if((x.l / size) & 1) return x.r < y.r;
        return x.r > y.r;
    }
};

constexpr int N = 1e5 + 5;
int c[N]; // 原数组

void add(int val) {}
void del(int val) {}

int main() {
    std::vector<Query> q;
    //input c, input query
    // ...
    int L = 1, R = 0;
    for(auto [l, r, id] : q) {
        //...
        while(L > l) add(c[--L]);
        while(R < r) add(c[++R]);
        while(L < l) del(c[L++]);
        while(R > r) del(c[R--]);
        //...
    }

}