#include <bits/stdc++.h>
#include "../testlib.h"

using i64 = long long;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
	inf.name = ouf.name = ans.name = "";
    int x = inf.readInt(3, 1'000'000);
    int n = ouf.readInt(0, 100'000);
    std::unordered_set<i64> s;
    s.insert(x);

    for(int i = 1; i <= n; ++i) {
        i64 a = ouf.readLong(0LL, 5'000'000'000'000'000'000);
        char op = ouf.readChar();
        i64 b = ouf.readLong(0LL, 5'000'000'000'000'000'000);
        if(!s.count(a) or !s.count(b)) {
            quitf(_wa, "The selected number is illegal");
            return 0;
        }
        if(op == '^') s.insert(a ^ b);
        if(op == '+') s.insert(a + b);
    }
    
    if(s.count(1)) quitf(_ok, "AC");
    else quitf(_wa, "Not getting one");

    return 0;
}