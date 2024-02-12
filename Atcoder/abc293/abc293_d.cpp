#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;
#define int long long 
const int N = 2e5 + 5;
int n, m, f[N], ans;
unordered_set<int>s;

void init(){for(int i = 1; i <= n; ++ i)f[i] = i;}

int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

void add(int x, int y){
    x = find(x);
    y = find(y);
    if(f[x] == f[y])s.insert(f[x]), ans ++;
    f[x] = y;
}

void solve(){
    cin >> n >> m;
    init();
    int x, y;
    string a, b;
    while(m--){
        cin >> x >> a >> y >> b;
        add(x, y);
    }
    unordered_set<int>st;
    for(int i = 1; i <= n; ++ i){
        if(!s.count(find(i)))st.insert(find(i));
    }
    cout << ans << ' ' << st.size();
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}