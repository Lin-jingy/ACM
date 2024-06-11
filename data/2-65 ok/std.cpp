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
    int begin = 1;
    int end = 20;
    for(int i = begin; i <= end; ++i) solve(problemID, i, standard);

    return 0;
}
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;
 
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
 
const int P = 1e9 + 7;
struct Matrix {
  int a[4];
  int& operator[](int i) {
    return a[i];
  }
};
Matrix Id() {
  return {1, 0, 0, 1};
}
Matrix Mult(Matrix a, Matrix b) {
  Matrix m;
  m[0] = (a[0] * b[0] + a[1] * b[2]) % P;
  m[1] = (a[0] * b[1] + a[1] * b[3]) % P;
  m[2] = (a[2] * b[0] + a[3] * b[2]) % P;
  m[3] = (a[2] * b[1] + a[3] * b[3]) % P;
  return m;
}
 
Matrix Add(Matrix a, Matrix b) {
  Matrix m;
  REP (i, 4) {
    m[i] = (a[i] + b[i]) % P;
  }
  return m;
}
 
const int M = (1 << 17);
pair<Matrix, Matrix> drz[2 * M + 5];
    
Matrix spow(Matrix m, int b) {
  Matrix r = Id();
  while (b) {
    if (b % 2) {
      r = Mult(r, m);
    }
    m = Mult(m, m);
    b /= 2;
  }
  return r;
}
 
Matrix Sum(int a) {
  return Mult(drz[a].st, drz[a].nd);
}
 
void Upd(int a) {
  if (a >= M) { return; } 
  drz[a].st = Add(Sum(2 * a), Sum(2 * a + 1));
}
 
void Mult(int a, int b, Matrix m) {
  a += M - 1;
  b += M - 1;
  drz[a].nd = Mult(drz[a].nd, m);
  if (a != b) {
    drz[b].nd = Mult(drz[b].nd, m);
  }
  while (a) {
    if (a / 2 != b / 2) {
      if (a % 2 == 0) {
        drz[a + 1].nd = Mult(drz[a + 1].nd, m);
      }
      if (b % 2 == 1) {
        drz[b - 1].nd = Mult(drz[b - 1].nd, m);
      }
    }
    Upd(a);
    if (a != b) {
      Upd(b);
    }
    a /= 2;
    b /= 2;
  }
}
 
int Read(int a, int b) {
  a += M - 1;
  b += M - 1;
  Matrix l = Id();
  Matrix r{0, 0, 0, 0};
  if (a != b) {
    r = Id();
  }
  while (a) {
    l = Mult(l, drz[a].nd);
    r = Mult(r, drz[b].nd);
    if (a / 2 != b / 2) {
      if (a % 2 == 0) {
        l = Add(l, Sum(a + 1));
      }
      if (b % 2 == 1) {
        r = Add(r, Sum(b - 1));
      }
    }
    a /= 2;
    b /= 2;
  }
  Matrix s = Add(l, r);
  debug(s[0], s[1], s[2], s[3]);
  return s[1];
}
void solve(str problemID, int dataID, model op) {
    str address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/{}/data/{}.in",problemID,dataID);
    str address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/{}/data/{}.out",problemID,dataID);
    log(dataID);
    if(op == check) freopen(address1.c_str(), "r", stdin);
    else if(op == generator) freopen(address1.c_str(), "w", stdout);
    else {
        freopen(address1.c_str(), "r", stdin);
        freopen(address2.c_str(), "w", stdout);
    }
    Rand r;
    std::cin.clear();
    // !begin test
    for(int i = 0; i < (2 * M + 5); ++i) {
        drz[i] = {{0,0,0,0},{0,0,0,0}};
    }
    REP (i, 2 * M + 5) {
    drz[i].st = drz[i].nd = Id();
  }
  FORD (i, M - 1, 1) {
    Upd(i);
  }
  int n, m;
  cin>>n>>m;
  
  Matrix fib{1, 1, 1, 0};
  RE (i, n) {
    int a;
    cin>>a;
    Mult(i, i, spow(fib, a));
    //drz[i - 1].nd = spow(fib, a);
  }
  RE (i, m) {
    int t, l, r;
    cin>>t>>l>>r;
    if (t == 1) {
      int x;
      cin>>x;
      Mult(l, r, spow(fib, x));
    } else {
      std::cout << Read(l, r) << std::endl;
    }
  }

    // !end test

    fclose(stdin);
    fclose(stdout);
    log("ok-------------");

}