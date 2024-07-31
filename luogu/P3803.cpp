#include <bits/stdc++.h>
#include <complex>

template <class T>
class FFT {
private:
    using vcp = std::vector<std::complex<double>>;
    constexpr static double Pi = std::numbers::pi_v<double>;

    static void dft(vcp &f, bool flag) {
        int n = f.size();
        std::vector<T> tr(n);
        for(int i = 0; i < n; i++) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
        for (int i = 0; i < n; i++)
            if (i < tr[i]) std::swap(f[i], f[tr[i]]);
        for(int p = 2; p <= n; p <<= 1){
            int len = p >> 1;
            std::complex<double> tG(cos(2*Pi/p),sin(2*Pi/p));
            if(!flag) tG.imag(-tG.imag());
            for(int k = 0; k < n; k += p){
                std::complex<double> buf(1,0);
                for(int l = k; l < k + len; l++){
                    std::complex<double> tt = buf * f[len + l];
                    f[len + l] = f[l] - tt;
                    f[l] = f[l] + tt;
                    buf *= tG;
                }
            }
        }
    }
public:
    static std::vector<T> mul(const std::vector<T> &a, const std::vector<T> &b) {
        int lena = a.size(), lenb = b.size(), size;
        for(size = 1; size <= lena + lenb - 2; size <<= 1);
        vcp fa(size), fb(size);
        for(int i = 0; i < lena; ++i) fa[i].real(a[i]);
        for(int i = 0; i < lenb; ++i) fb[i].real(b[i]);
        dft(fa, 1), dft(fb, 1);
        for(int i = 0; i < size; ++i) fa[i] *= fb[i];
        dft(fa, 0);
        std::vector<T> result(lena + lenb - 1);
        for(int i = 0; i <= lena + lenb - 2; ++i) result[i] = fa[i].real() / size + 0.5;
        return result;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> a(n + 1), b(m + 1);
    for(int i = 0; i <= n; ++i) std::cin >> a[i];
    for(int i = 0; i <= m; ++i) std::cin >> b[i];

    auto x = FFT<long long>::mul(a, b);
    for(auto i:x) std::cout << i << ' ';

    return 0;
}