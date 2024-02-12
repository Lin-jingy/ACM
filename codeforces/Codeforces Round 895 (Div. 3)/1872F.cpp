//WA
// #include<bits/stdc++.h>

// #define int long long

// const int N = 1e5;

// class DSU {
// private:
//     int f[N],siz[N];
// public:
//     void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
//     int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
//     bool same(int x,int y){return find(x)==find(y);}
//     void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
//     int qsz(int x){return siz[find(x)];}
// }T;

// void solve(){
//     int n;
//     std::cin >> n;
//     T.init(n);
//     std::vector<int>a(n + 1), c(n + 1);
//     for(int i = 1; i <= n; ++i) std::cin >> a[i], T.merge(i, a[i]);
//     for(int i = 1; i <= n; ++i) std::cin >> c[i];
//     std::vector<std::vector<int>>v;
//     std::unordered_map<int, int>mp;
//     for(int i = 1; i <= n; ++i){
//         if(mp.count(T.find(i))) v[mp[T.find(i)]].emplace_back(i);
//         else {
//             mp[T.find(i)] = v.size();
//             v.push_back(std::vector<int>{i});
//         }
//     }
//     for(auto i:v){
//         int mn = i.front();
//         for(auto j:i) if(c[mn] > c[j]) mn = j;
//         for(auto j:i) if(j != mn) std::cout << j << ' ';
//         std::cout << mn << ' ';
//     }
//     std::cout << '\n';
// }

// signed main(){
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
//     int T;
//     std::cin >> T;
//     while(T--) solve();
//     return 0;
// }


#include <bits/stdc++.h>

const int N = 1e5 + 10;
int a[N], c[N];
int d[N], minn = 1e9 + 10, id = -1;
bool st[N];

void dfs(int u){
    if (st[u]) return;
    st[u] = true;
    int j = a[u];
    if (minn > c[j]) minn = c[j], id = j;
    dfs(j);
}
void solve(){
    std::queue<int> q;
    std::vector<int> ans;
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; i++) st[i] = false, d[i] = 0;
    for (int i = 1; i <= n; i++) std::cin >> a[i], d[a[i]]++;
    for (int i = 1; i <= n; i++) std::cin >> c[i];
    for (int i = 1; i <= n; i++) if (!d[i]) q.push(i);
    while (q.size()){
        int t = q.front();
        ans.push_back(t);
        st[t] = true;
        q.pop();
        if (--d[a[t]] == 0) q.push(a[t]);
    }
    for (int i = 1; i <= n; i++)
        if (!st[i]){
            minn = c[i];
            id = i;
            dfs(i);
            int x = a[id];
            do{
                ans.push_back(x);
                x = a[x];
            } while (x != a[id]);
        }
    for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << ' ';
    std::cout << '\n';
}
signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; 
    std::cin >> T;
    while (T--) solve();
    return 0;
}