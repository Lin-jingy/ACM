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

struct node{int x, y;};
inline auto dis(node a, node b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve(){
    node a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    bool ok = false;
    if(dis(a, b) + dis(b, c) == dis(c, a)){
        if(a.x == b.x and b.y == c.y)ok = 1;
        if(a.y == b.y and b.x == c.x)ok = 1;
    }
    if(dis(a, c) + dis(b, c) == dis(b, a)){
        if(a.x == c.x and b.y == c.y)ok = 1;
        if(a.y == c.y and b.x == c.x)ok = 1;
    }
    if(dis(c, a) + dis(a, b) == dis(c, b)){
        if(c.x == a.x and a.y == b.y)ok = 1;
        if(c.y == a.y and a.x == b.x)ok = 1;
    }
    if(!ok)yes;
    else no;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
