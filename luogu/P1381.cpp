#include <bits/stdc++.h>
#include<bits/extc++.h>
#include <functional>

#define int long long
#define rep(i,b,e)for(int i=b;i<(e);++i)
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x)emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX
template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;template<class T,size_t S>using arr=std::array<T,S>;class Timer {private:std::chrono::system_clock::time_point begin;public:Timer() { begin = std::chrono::system_clock::now(); }~Timer() {auto end = std::chrono::system_clock::now();auto time = std::chrono::duration<double, std::nano>(end - begin).count();std::clog << "\nThe program takes: " << time / 1e9 << " s\n";}double get() {auto end = std::chrono::system_clock::now();auto time = std::chrono::duration<double, std::nano>(end - begin).count();return time / 1e9;}};
#define vec(type,x,sz,val)std::vector<type>x(sz,val);
#define vvec(type,x,sz1,sz2,val)std::vector<std::vector<type>>x(sz1,std::vector<type>(sz2,val));
#define log(...)PRINT(#__VA_ARGS__" ::",__VA_ARGS__)<<std::endl
template<class...Ts>auto&PRINT(Ts...ts){return((std::clog<<ts<<" "),...);}
#define ensure(x)if(!(x)){std::cerr<<"ensure error:("<<#x<<")->at line:"<<__LINE__<<std::endl;exit(-1);}
template <class _KEY, class _Compare = std::less<_KEY>>
using pbds_set = __gnu_pbds::tree<_KEY, __gnu_pbds::null_type, _Compare,
__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template <class _KEY, class _VALUE, class _Compare = std::less<_KEY>>
using pbds_map = __gnu_pbds::tree<_KEY, _VALUE, _Compare,__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;

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
        p_1[0] = hashcode_1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = hashcode_1[i - 1] * base_1 + s[i - 1];
            p_1[i] = p_1[i - 1] * base_1;
        }
    }
    void init_single(const std::string &s) {
        p_1[0] = hashcode_1[0] = 1;
        for(int i = 1; i <= s.size(); ++i) {
            hashcode_1[i] = (1LL * hashcode_1[i - 1] * base_1 + s[i - 1]) % mod_1;
            p_1[i] = 1LL * p_1[i - 1] * base_1 % mod_1;
        }
    }
    void init_double(const std::string &s) {
        hashcode_2.assign(s.size() + 1, {});
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
    StringHash(const std::string &s, OPTION option) : op(option), hashcode_1(s.size() + 1), p_1(s.size() + 1){
        static int MOD_1;
        static int MOD_2;
        if(!MOD_1) {
            std::mt19937 rnd(time(0));
            MOD_1 = findPrime(rnd() % 900000000 + 100000000);
            MOD_2 = findPrime(rnd() % 900000000 + 100000000);
        }
        mod_1 = MOD_1;
        mod_2 = MOD_2;
        if(op == Nature) init_nature(s);
        else if(op == Single) init_single(s);
        else if(op == Double) init_double(s);
    }
    std::pair<int, int> get(int l, int r) {
        ++l, ++r;
        if(op == Nature) return get_nature(l, r);
        else if(op == Single) return get_single(l, r);
        else if(op == Double) return get_double(l, r);
        return {0, 0};
    }
    std::pair<int, int> getAll() {
        if(op == Double) return {hashcode_1.back(), hashcode_2.back()};
        else return {hashcode_1.back(), 0};
    }
};
void solve() {
    int n;
    std::cin >> n;
    std::set<Pii> s;
    for(int i = 1; i <= n; ++i) {
        str x;
        std::cin >> x;
        s.insert(StringHash(x, Single).getAll());
    }
    int m;
    std::cin >> m;
    vec<Pii> v(m + 1);
    for(int i = 1; i <= m; ++i) {
        str x;
        std::cin >> x;
        v[i] = StringHash(x, Single).getAll();
    }
    int l = 0, r = n;
    int ans1 = 0, ans2 = 0;
    auto check = [&](int mid) {
        std::map<Pii, int> mp;
        std::deque<int> dq;
        int ans = m + 1;
        for(int i = 1; i <= m; ++i) {
            if(mp.size() == mid) ans = std::min(ans, (int)dq.size());
            if(mp.size() <= mid) {
                dq.pb(i);
                if(s.count(v[i])) mp[v[i]]++;
            }
            if(mp.size() > mid) {
                if(s.count(v[dq.front()])) mp[v[dq.front()]]--;
                dq.pop_front();
            }
        }
        if(ans <= n) {
            ans1 = mid;
            ans2 = ans;
        }
        return ans <= n;
    };
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    std::cout << std::format("{} {}\n", ans1, ans2);

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
