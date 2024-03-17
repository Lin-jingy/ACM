#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma clang diagnostic ignored "-Wunused-value"
// #pragma clang diagnostic ignored "-Wshift-op-parentheses"
#define LOG(x) if(!(x)){std::cout<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define LOG(x)
#endif
#define int long long
#define rep(i,b,e) for(int i=b;i<(int)(e);++i)
#define range(i,b,e,step) for(int i=b;(b<e?i<e:i>e);i+=(b<e?step:-step))
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX;
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream&in,std::vector<T>&v) 
{for(auto &i:v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream&out,const std::vector<T>&v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T,class FUN>void foreach
(std::vector<T>&v,FUN fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template <class T>void sort(std::vector<T>&v) {std::sort(v.begin(),v.end());}
template <class T,class FUN>void sort(std::vector<T>&v,FUN fun) 
{std::sort(v.begin(),v.end(),fun);}template<class T>void input
(T begin,T end){while(begin!=end)std::cin>>*begin++;}
using Pii = std::pair<int, int>;

enum OPTION {
    Nature,
    Single,
    Double,
};
class StringHash {
private:
    std::vector<int> hashcode_1, hashcode_2, p_1, p_2;
    int base_1 = 131; 
    int base_2 = 133331;
    OPTION op;
    int mod_1;
    int mod_2;
    constexpr bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
    constexpr int findPrime(int n) {
        while (!isprime(n)) n++;
        return n;
    }
    void init_nature(const std::string &s) {
        hashcode_1.assign(s.size() + 1, {});
        p_1.assign(s.size() + 1, {});
        p_1[0] = hashcode_1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = hashcode_1[i - 1] * base_1 + s[i - 1];
            p_1[i] = p_1[i - 1] * base_1;
        }
    }
    void init_single(const std::string &s) {
        hashcode_1.assign(s.size() + 1, {});
        p_1.assign(s.size() + 1, {});
        p_1[0] = hashcode_1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = (1LL * hashcode_1[i - 1] * base_1 + s[i - 1]) % mod_1;
            p_1[i] = 1LL * p_1[i - 1] * base_1 % mod_1;
        }
    }
    void init_double(const std::string &s) {
        hashcode_1.assign(s.size() + 1, {});
        hashcode_2.assign(s.size() + 1, {});
        p_1.assign(s.size() + 1, {});
        p_2.assign(s.size() + 1, {});
        p_1[0] = p_2[0] = hashcode_1[0] = hashcode_2[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = (1LL * hashcode_1[i - 1] * base_1 + s[i - 1]) % mod_1;
            hashcode_2[i] = (1LL * hashcode_2[i - 1] * base_2 + s[i - 1]) % mod_2;
            p_1[i] = 1LL * p_1[i - 1] * base_1 % mod_1;
            p_2[i] = 1LL * p_2[i - 1] * base_2 % mod_2;
        }
    }
    std::pair<int, int> get_nature(int l, int r) {
        return {hashcode_1[r] - hashcode_1[l - 1] * p_1[r - l + 1], 0LL};
    }
    std::pair<int, int> get_single(int l, int r) {
        return {(hashcode_1[r] + (mod_1 - hashcode_1[l - 1]) * p_1[r - l + 1]) % mod_1, 0LL};
    }
    std::pair<int, int> get_double(int l, int r) {
        return {(hashcode_1[r] + 1LL * (mod_1 - hashcode_1[l - 1]) * p_1[r - l + 1]) % mod_1,
        (hashcode_2[r] + 1LL * (mod_2 - hashcode_2[l - 1]) * p_2[r - l + 1]) % mod_2};
    }
public:
    StringHash(const std::string &s, enum OPTION option) : op(option){
        static bool first = true;
        static int MOD_1;
        static int MOD_2;
        if(first) {
            first = false;
            std::mt19937 rnd(time(0));
            MOD_1 = findPrime(rnd() % 900000000 + 100000000);
            MOD_2 = findPrime(rnd() % 900000000 + 100000000);
        }
        mod_1 = MOD_1;
        mod_2 = MOD_2;
        if(op == OPTION::Nature) init_nature(s);
        else if(op == OPTION::Single) init_single(s);
        else if(op == OPTION::Double) init_double(s);
    }
    std::pair<int, int> get(int l, int r) {
        ++l, ++r;
        if(op == OPTION::Nature) return get_nature(l, r);
        else if(op == OPTION::Single) return get_single(l, r);
        else if(op == OPTION::Double) return get_double(l, r);
        return {0, 0};
    }
    std::pair<int, int> getAll() {
        if(op == OPTION::Double) return {hashcode_1.back(), hashcode_2.back()};
        else return {hashcode_1.back(), 0};
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::string rs = s;
    std::reverse(All(rs));
    s = ' ' + s;
    rs = ' ' + rs;
    StringHash hashS(s, OPTION::Double);
    StringHash hashRS(rs, OPTION::Double);
    vec<vec<int>> p(n + 1, vec<int>(26));
    vec<vec<int>> p0(n + 1, vec<int>(26));
    vec<vec<int>> p1(n + 1, vec<int>(26));
    rep(i, 1, n + 1) {
        rep(j, 0, 26) p[i][j] += p[i - 1][j];
        p[i][s[i] - 'a']++;
    }
    rep(i, 1, n + 1) {
        rep(j, 0, 26) p0[i][j] += p0[i - 1][j];
        if(i % 2 == 1) p0[i][s[i] - 'a']++;
    }
    rep(i, 2, n + 1) {
        rep(j, 0, 26) p1[i][j] += p1[i - 1][j];
        if(i % 2 == 0) p1[i][s[i] - 'a']++;
    }
    for(int i = 1; i <= q; ++i) {
        int l, r;
        std::cin >> l >> r;
        int mx1 = 0, mx2 = 0;
        rep(i, 0, 26) {
            if(p[r][i] - p[l - 1][i] == r - l + 1) {
                std::cout << "0\n";
                goto NEXT;
            }
        }
        rep(i, 0, 26) {
            mx1 = std::max(p0[r][i] - p0[l - 1][i], mx1);
            mx2 = std::max(p1[r][i] - p1[l - 1][i], mx2);
        }
        if(mx1 + mx2 == r - l + 1) {
            int len = r - l + 1;
            if(len % 2 == 1) --len;
            std::cout << (2 + len) * (len / 2) / 2 << '\n';
            goto NEXT;
        }
        if(hashS.get(l, r) == hashRS.get(n - r  + 1, n - l + 1)) {
            std::cout << (2 + r - l) * (r - l - 1) / 2 << '\n';
        } else {
            std::cout << (2 + r - l + 1) * (r - l) / 2 << '\n';
        }
        NEXT:;
    }

    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}