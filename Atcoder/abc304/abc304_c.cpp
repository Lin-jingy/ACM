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

const int N = 3000;
int p[N];
PII a[N];

inline auto dis(PII a, PII b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

void solve(){
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    queue<int>q;
    p[1] = 1;
    q.push(1);
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(int i = 1; i <= n; ++i)
            if(dis(a[pos], a[i]) <= d * d and !p[i]) 
                q.push(i), p[i] = 1;
    }
    for(int i = 1; i <= n; ++i){
        if(p[i])yes;
        else no;
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
