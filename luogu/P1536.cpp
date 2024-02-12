#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 1005;

class UFS {
public:
    int f[N],siz[N];
    void init(int n) {for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;}
    int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y) {if(!same(x,y))siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);}
    int qsz(int x){return siz[find(x)];}
};

void solve(){
    int n, m;
    while(cin >> n >> m){
        UFS t;
        t.init(n);
        while(m--){
            int x, y;
            cin >> x >> y;
            t.merge(x, y);
        }
        unordered_set<int>s;
        for(int i = 1; i <= n; ++i)s.insert(t.find(t.f[i]));
        cout << s.size() - 1 << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
