/* 游戏 */
#include<bits/stdc++.h>

using namespace std;

class Timer {
private:
    std::chrono::system_clock::time_point begin;
public:
    Timer() { begin = std::chrono::system_clock::now(); }
    ~Timer() {
        auto end = std::chrono::system_clock::now();
        auto time = std::chrono::duration<double, std::nano>(end - begin).count();
        std::clog << "\nThe program takes: " << time / 1e9 << " s\n";
    }
    double get() {
        auto end = std::chrono::system_clock::now();
        auto time = std::chrono::duration<double, std::nano>(end - begin).count();
        return time / 1e9;
    }
};
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
// #define int long long
using pii = pair<int,int>;
//#define endl "\n"
#define dbg(x...) do{cout<<#x<<" -> ";err(x);}while(0)

void err() { cout << '\n'; }

template<class T, class... Ts>
void err(T arg, Ts... args) {
    cout << arg << ' ';
    err(args...);
}

using vi = vector<int>;
constexpr int P = 998244353, G = 3, N = 4e6 + 5, M = 1e6 + 1, NT = 1e7+5;

namespace PolyNTT {
    vi w, rev;

    int qpow(int x, int r ) {
        int re = 1;
        while(r) {
            if(r & 1) re = (int) (1ll*re*x%P);
            x = (int) (1ll*x*x%P), r>>=1;
        }
        return re;
    }

    int ck(int x) { return x >= P ? x-P : x; }
    int ck_(int x) { return x < 0 ? x+P : x; }

    void print(vi f) {
        int sz = (int) f.size();
        for(int i = 0; i < sz; i++) cout << f[i] << " \n"[i == sz - 1];
    }

    void pre(int k) {
        int lim = (1<<k);
        w.resize(lim), rev.resize(lim);
        for(int i = 0; i < lim; i++) rev[i] = (rev[i>>1]>>1)|((i&1)<<(k-1));
        for(int l = 1; l < lim; l<<=1) {
            int p = qpow(G, (P-1)/(l<<1)); w[l] = 1;
            for(int i = 1; i < l; i++) w[l+i] = (int) (1ll*w[l+i-1]*p%P);
        }
    }

    void NTT(vi &f) {
        int lim = (int) f.size();
        for(int i = 0; i < lim; i++) if(i < rev[i]) swap(f[i], f[rev[i]]);
        for(int l = 1; l < lim; l<<=1)
            for(int i = 0; i < lim; i+=(l<<1))
                for(int j = 0; j < l; j++) {
                    int x = f[i+j], y = (int) (1ll*f[i+j+l]*w[j+l]%P);
                    f[i+j] = ck(x+y), f[i+j+l] = ck_(x-y);
                }
    }

    vi operator* (vi f, vi g) {
        int n = (int) (f.size() + g.size() - 1), k = 0, lim = 1;
        while(lim < n) lim <<= 1, k++;
        f.resize(lim), g.resize(lim);
        pre(k);        NTT(f); NTT(g);
        for(int i = 0; i < lim; i++) f[i] = (int) (1ll*f[i]*g[i]%P);
        NTT(f); reverse(f.begin()+1, f.end());
        int Inv = qpow(lim, P-2); f.resize(n);
        for(int i = 0; i < n; i++) f[i] = (int) (1ll*f[i]*Inv%P);
        return f;
    }

}
using namespace PolyNTT;

int cnt[M], a[NT], inv[NT];

void mainPre() {
    inv[0] = inv[1] = 1;
    for(int i = 2; i <= NT-5; i++) inv[i] = 1ll*(P-P/i)*inv[P%i]%P;
}

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> f(M), g(M);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int fm = 0, P_2 = qpow(2, P-2);
    for(int i = 1; i <= M; i++) {
        f[i] = cnt[i], g[i] = cnt[M-i];
        fm +=  2ll * cnt[i]*(cnt[i]-1)%P*P_2%P;
       if(fm >= P) fm -= P;
    }
    f = f*g;

    f[M] = fm;
    cout << "?\n";
/*
    int Cn2 = 1ll*n*(n-1)%P*P_2%P, p3 = qpow(Cn2, P-2);
    int p1 = 1ll*(n-2)*p3%P, p2 = 1ll*(n-2)*p3%P, p2_ = qpow(p2, P-2);
    
    a[0] = qpow(p2, t);
    a[1] = 1ll * qpow(p2, t-1) * p3%P * t%P;
    for(int i = 1; i <= t; i++) {
        a[i+1] = (1ll*(t-i)*p3%P*a[i]%P + 1ll*(2*t-i+1)*p1%P*a[i-1]%P + P)%P;
        a[i] = 1ll*a[i]*p2_%P*inv[i+1]%P;
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        if(t-i < 0) break;
        ans += 1ll*f[i+M]*a[t-i]%P;
        if(ans >= P) ans -= P;
    }
    cout << ans << endl;*/
}

signed main() {
    Timer _;
    mainPre();
    IOS;
    int T = 1;
//    cin >> T;
    // while(T--) solve();
    return 0;
}