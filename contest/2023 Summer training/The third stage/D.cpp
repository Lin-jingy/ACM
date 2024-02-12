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

struct pos{
    int x, y, z;
}a[N];

class node{
    public:
    int a, b, dis;
};

bool cmp(node x, node y){
    if(x.dis != y.dis) return x.dis < y.dis;
    else{
        if(a[x.a].x == a[y.a].x and a[x.a].y == a[y.a].y) return a[x.a].z < a[y.a].z;
        else if(a[x.a].x == a[y.b].x and a[x.a].y == a[y.b].y) return a[x.a].z < a[y.b].z;
        else if(a[x.b].x == a[y.a].x and a[x.b].y == a[y.a].y) return a[x.b].z < a[y.a].z;
        else if(a[x.b].x == a[y.b].x and a[x.b].y == a[y.b].y) return a[x.b].z < a[y.b].z;
        else return x.a < y.a;
        
    }
}

inline int dis(pos a, pos b){
    return abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y);
}

void solve(){
    int n;
    cin >> n;
    vector<node>v;
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y >> a[i].z;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)continue;
            v.push_back({min(i, j), max(i, j), dis(a[i], a[j])});
        }
    }
    sort(v.begin(), v.end(), cmp);
    list<node>l;
    for(auto i:v)l.push_back(i);
    vector<PII>ans;
    while(!l.empty()){
        auto k = l.front();
        l.pop_front();
        ans.push_back({k.a, k.b});
        for(auto i = l.begin(); i != l.end();){
            if(i->a == k.a or i->a == k.b or i->b == k.a or i->b == k.b) i = l.erase(i);
            else ++i;
        } 
    }
    for(auto i:ans){
        cout << i.first << ' ' << i.second << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
