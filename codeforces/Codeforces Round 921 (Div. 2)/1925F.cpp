#include <bits/stdc++.h>

#define int long long
constexpr int mod = 999999893;

int qpow(int a, int b) {
    int sum = 1;
    while(b) {
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

class node {
public:
	int a, b;
	node(int x, int y) : a(x), b(y) {}
    friend node operator+ (node a, node b) {
        return node((a.a + b.a) % mod, (a.b + b.b) % mod);
    }
    friend node operator- (node a, node b) {
        return node((a.a - b.a + mod) % mod, (a.b - b.b + mod) % mod);
    }
    friend node operator* (node a, node b) {
	    return node((a.a * b.a + a.b * b.b * 2) % mod, (a.a * b.b + a.b * b.a) % mod);
    }
    friend node operator* (node a, int b) {
	    return node(a.a * b % mod, a.b * b % mod);
    }
    friend node operator/ (node x, int y) {
        return {x.a * qpow(y, mod - 2) % mod, x.b * qpow(y, mod - 2) % mod};
    }
    friend node operator/ (node x, node y) {
        return x * node(y.a, mod - y.b) * qpow((y.a * y.a - y.b * y.b * 2) % mod, mod - 2);
    }
};

inline node qpow(node a, int b) {
	node sum(1, 0);
	while (b) {
		if (b & 1) sum = sum * a;
		b >>= 1;
		a = a * a;
	}
	return sum;
}

void solve() {
	int n;
    std::cin >> n;
	node M = (node(1, 0) - qpow(node(0, 1), n - 1)) * node(2, 0) / node(1, mod - 1);
	node V = M + node(0, 2);
	std::cout << ((M / V).b + mod) % mod << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}