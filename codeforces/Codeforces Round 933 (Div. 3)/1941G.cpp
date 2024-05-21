#include <bits/stdc++.h>

#define int long long
#define rep(i,b,e)for(int i=b;i<e;++i)
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x)emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX
template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}using Pii=std::pair<int,int>;
#if defined(_WIN64)
#define log(x...)do{std::clog<<#x<<" -> ";_log(x);}while(0)
void _log(){std::clog<<std::endl<<std::endl;}template<class T,class...Ts>void _log(T arg,Ts...args){std::clog<<arg<<' ';_log(args...);}
#define sure(x)if(!(x)){std::cerr<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define log(x...)
#define sure(x)
#endif

void solve() {
	int n, m;
    std::cin >> n >> m;
    vec<vec<Pii>> g(n + m + 10);
    vec<int> dis(n + m + 10, inf);
    vec<bool> st(n + m + 10);
	int cnt = n;
	
	umap<int, int> col;
	while (m--) {
		int u, v, w; 
        std::cin >> u >> v >> w;
		if (!col.count(w)) col[w] = ++ cnt;
		g[u].push_back({col[w], 1});
		g[v].push_back({col[w], 1});
		g[col[w]].push_back({u, 0});
		g[col[w]].push_back({v, 0});
	}
	int s, t; 
    std::cin >> s >> t;
	
	std::deque<int> q;
	q.push_back(s);
	dis[s] = 0;
	while (q.size()) {
		int u = q.front();
		q.pop_front();
        if (st[u]) continue;
        st[u] = 1;
		for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
	}
    std::cout << dis[t] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
