#include <bits/stdc++.h>

template<class T = long long, size_t MOD = LONG_LONG_MAX>
class Martix {
public:
    int n, m;
	std::vector<std::vector<T>> a;
    Martix() = default;
    Martix(int N, int M): n(N), m(M), a(N + 1, std::vector<T>(M + 1)) {}
    Martix(std::vector<std::vector<T>> &other): 
        n(other.size() - 1), m(other.front().size() - 1), a(other) {}
	Martix operator* (const Martix &other) const {
        if(m != other.n) 
            throw std::domain_error("Columns and rows are not equal and cannot be multiplied");
        Martix res(n, other.m);
		for (int i = 1; i <= res.n; i++)
			for (int j = 1; j <= res.m; j++)
				for (int k = 1; k <= m; k++)
					res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j] % MOD) % MOD;
		return res;
	}
    Martix& operator= (const Martix &other) { n = other.n, m = other.m, a = other.a; return *this; }
    Martix& operator= (std::vector<std::vector<T>> &other) { return *this = Martix(other); }
	Martix operator^ (T x) const {
        if(n != m) throw std::domain_error("Columns and rows are not equal and cannot be multiplied");
		Martix res(n, n);
        for(int i = 1; i <= n; ++i) res.a[i][i] = 1;
        Martix a = *this;
		while (x) {
			if (x & 1) res = res * a;
			a = a * a;
			x >>= 1;
		} 
		return res;
	}
    std::ostream& operator<< (std::ostream &out) const {
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= m; ++j) 
                out << a[i][j] << " \n"[j == m];
        return out;
    }
};
template<class T = long long, size_t MOD = LONG_LONG_MAX>
std::ostream& operator<< (std::ostream &out, const Martix<T, MOD> &data) {
    data.operator<< (out);
    return out;
}
