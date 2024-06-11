#include <bits/stdc++.h>

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
#if defined(_WIN64)
#define log(...)print(#__VA_ARGS__" ::",__VA_ARGS__)<<std::endl
template<class...Ts>auto&print(Ts...ts){return((std::clog<<ts<<" "),...);}
#define ensure(x)if(!(x)){std::cerr<<"error at:"<<__LINE__<<std::endl<<#x<<std::endl;exit(-1);}
#else
#define sure(x)111
#define log(...)111
#endif
enum model {
    generator = 0,
    check = 1,
    standard = 2
};
class Rand {
private:
    std::mt19937_64 rnd;
public:
    Rand() : rnd((std::chrono::high_resolution_clock::now()).time_since_epoch().count()) {}
    int get(int l, int r) { return rnd() % (r - l + 1) + l; }
    int operator()() { return rnd(); }
    std::mt19937_64 data() { return rnd; }
};
void print(auto x) { std::cout << x << ' ';}
void println(auto x) { std::cout << x << std::endl; }
void println(auto x, auto y) { std::cout << x << ' ' << y << std::endl; }
void ranges_print(int n, int l, int r) {
    Rand R;
    for(int i = 1; i < n; ++i) print(R.get(l, r));
    println(R.get(l, r));
}
void println(vec<int>& x) {
    for(int i = 0; i < x.size() - 1; ++i) print(x[i]);
    println(x.back());
}
void solve(str problemID, int dataID, model op);

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    str problemID = "2-65";
    int begin = 17;
    int end = 17;
    for(int i = begin; i <= end; ++i) solve(problemID, i, model::generator);

    return 0;
}

void solve(str problemID, int dataID, model op) {
    str address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/{}/data/{}.in",problemID,dataID);
    str address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/{}/data/{}.out",problemID,dataID);
    log(dataID);
    if(op == model::check) freopen(address1.c_str(), "r", stdin);
    else if(op == model::generator) freopen(address1.c_str(), "w", stdout);
    else {
        freopen(address1.c_str(), "r", stdin);
        freopen(address2.c_str(), "w", stdout);
    }
    Rand r;

    // !begin test

    int n = 100'000;
    int m = 100'000;
    println(n, m);
    for(int i = 1; i < n; ++i) {
        print(1'000'000'000 - i + 1);
    }
    println(1'000'000'000 - n + 1);
    for(int i = 1; i < m; ++i) {
        print(2);
        println(1, n);
    }
    print(2);
    println(1, n);

    // !end test

    fclose(stdin);
    fclose(stdout);
    log("ok-------------");

}