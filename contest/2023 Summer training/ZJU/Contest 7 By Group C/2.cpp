//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 5e5 + 5;
int a[N];

class node{
    public:
    int l, r, val;
    friend bool operator< (node a, node b){
        if(a.r != b.r) return a.r > b.r;
    }
}p[N];

bool cmp(node a, node b){
    if(a.l != b.l) return a.l < b.l;
    else return a.r < b.r;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> p[i].val >> p[i].l >> p[i].r;
    sort(p + 1, p + 1 + n, cmp);
    priority_queue<node>q;
    int flag = 0;
    int ans = 0;
    
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
