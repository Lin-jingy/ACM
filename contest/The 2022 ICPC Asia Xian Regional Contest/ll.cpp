#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e6 +5;

vector<int>t[maxn];
int dep[maxn],fa[maxn],top[maxn],sz[maxn];

void dfs1(int p,int d = 1)
{
    int size = 1,ma = 0;
    dep[p] = d;
    for (auto i : t[p]) {
        if (!dep[i]) {
            dfs1(p,d + 1);
            fa[i] = p;
            size += sz[i];
            if (sz[i] > ma) {
                
            }
        }
    }
}

void solve() {
    int n;cin >> n;
    for (int i = 1;i < n;i++) {
        int x;cin >> x;
        t[i].push_back(x);
        t[x].push_back(i);
    }
    dfs1(1,0);
    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}