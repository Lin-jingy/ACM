#include <bits/stdc++.h>
typedef long long lint;

inline lint read() {
	lint x = 0, f = 0; char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = 1;
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return f ? -x : x;
}

const int p = 1e9 + 7;
lint n;
int m, K;
int t, ans;

struct mat {
	int row, col;
	int a[32][32];
	mat() {
		memset(a, 0, sizeof(a));
	}
	void init() {
		*this = mat();
		row = col = t;
		for (int i = 0; i < t; ++i)
			a[i][i] = 1;
	}
	mat operator * (const mat &x) const {
		mat ans = mat(); ans.row = row; ans.col = col;
		for (int i = 0; i < row; ++i) 
			for (int j = 0; j < col; ++j)
				for (int k = 0; k < col; ++k)
					(ans.a[i][j] += (1ll * a[i][k] * x.a[k][j]) % p) %= p;
		return ans;
	}
	mat operator ^ (lint n) {
		mat ans = mat(); 
		ans.init();
		mat base = *this;
		for (; n; n >>= 1, base = base * base)
			if (n & 1) ans = ans * base;
		return ans;
	}
} ;

int main() {
	n = read(); m = read(); K = read();
	t = 1 << m;
	mat b = mat(); b.row = b.col = t;
	for (int i = 0, j; i < t; ++i) {
		if (__builtin_popcount(i) > K) continue;
		j = i >> 1;
		// j -> i
		b.a[j][i] = 1;
		j = (i >> 1) | (1 << (m - 1));
		if (__builtin_popcount(j) <= K)
			b.a[j][i] = 1;
	}

	mat c = (b ^ n);
	for (int i = 0; i < t; ++i) {
		ans = (ans + c.a[i][i]) % p;
	}
	printf("%d\n", ans);
	return 0;
}