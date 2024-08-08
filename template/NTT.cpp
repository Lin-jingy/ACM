#include <bits/stdc++.h>

template <long long mod = 998244353>
class NTT {
    using i64 = long long;
    using vcp = std::vector<std::complex<double>>;

   private:
    constexpr static double Pi = std::numbers::pi;
    constexpr static i64 qpow(i64 a, i64 b = mod - 2) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    constexpr static int generator() {
        std::vector<i64> fact;
        i64 phi = mod - 1, n = phi;
        for (i64 i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                fact.push_back(i);
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) fact.push_back(n);
        for (i64 res = 2; res <= mod; ++res) {
            bool ok = true;
            for (i64 factor : fact) {
                if (qpow(res, phi / factor) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) return res;
        }
        assert(0);
        return -1;
    }
    constexpr static i64 G = generator();
    constexpr static i64 invG = qpow(G, mod - 2);
    constexpr static void dft(std::vector<i64> &f, bool flag,
                              const std::vector<i64> &tr) {
        int n = f.size();
        for (int i = 0; i < n; i++)
            if (i < tr[i]) std::swap(f[i], f[tr[i]]);
        for (int p = 2; p <= n; p <<= 1) {
            int len = p >> 1;
            i64 tG = qpow(flag ? G : invG, (mod - 1) / p);
            for (int k = 0; k < n; k += p) {
                i64 buf = 1;
                for (int l = k; l < k + len; l++) {
                    int tt = buf * f[len + l] % mod;
                    f[len + l] = f[l] - tt;
                    if (f[len + l] < 0) f[len + l] += mod;
                    f[l] = f[l] + tt;
                    if (f[l] > mod) f[l] -= mod;
                    buf = (buf * tG) % mod;
                }
            }
        }
    }

   public:
    constexpr static std::vector<int> mul(const std::vector<int> &a,
                                          const std::vector<int> &b) {
        int lena = a.size(), lenb = b.size(), size;
        for (size = 1; size <= lena + lenb - 2; size <<= 1)
            ;
        std::vector<i64> fa(size), fb(size), tr(size);
        for (int i = 0; i < size; i++)
            tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? size >> 1 : 0);
        std::copy(a.begin(), a.end(), fa.begin());
        std::copy(b.begin(), b.end(), fb.begin());
        dft(fa, 1, tr), dft(fb, 1, tr);
        for (int i = 0; i < size; ++i) fa[i] = fa[i] * fb[i] % mod;
        dft(fa, 0, tr);
        std::vector<int> result(lena + lenb - 1);
        int invn = qpow(size);
        for (int i = 0; i <= lena + lenb - 2; ++i)
            result[i] = (fa[i] * invn) % mod;
        return result;
    }
    constexpr static std::vector<int> inv(const std::vector<int> &a) {
        if (!k) return vi(1, qpow(f[0], P - 2));
        int lim = (1 << k);
        f.resize(lim);
        vi g = INV(f, k - 1), h(lim);
        f.resize(lim << 1), g.resize(lim << 1);
        for (int i = 0; i < (lim >> 1); i++) h[i] = ck(2 * g[i]);
        pre(k + 1);
        NTT(g), NTT(f);
        for (int i = 0; i < (lim << 1); i++) g[i] = (int)(1ll * f[i] * g[i] % P * g[i] % P);
        NTT(g);
        reverse(g.begin() + 1, g.end());
        g.resize(lim);
        int Inv = inv[lim << 1];
        for (int i = 0; i < lim; i++) h[i] = ck_(h[i] - (int)(1ll * g[i] * Inv % P)) % P;
        return h;
    }
};
