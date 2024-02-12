#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;cin>>n;
    if(n==1){
        cout<<1<<'\n';
        return ;
    }
    vector<vector<int>>g(n+1);
    for(int i=2;i<=n;i++){
        int v;cin>>v;
        g[i].push_back(v);
        g[v].push_back(i);
    }

    queue<int>q;
    vector<int>vis(n+1);
    vector<int>f(n+1);
    vector<int>dep(n+1);
    vector<int>cnt(n+1);
    auto dfs = [&](auto self,int now,int father)->void{
        f[now]=father;
        dep[now]=dep[father]+1;
        cnt[dep[now]]++;
        for(auto v:g[now]){
            if(v==father)continue;
            self(self,v,now);
        }
    };
    dfs(dfs,1,0);
    
    int mx=1;
    for(int i=1;i<=n;i++){
        if(dep[i]>dep[mx])mx=i;
    }
    while(mx!=0){
        vis[mx]=1;
        mx=f[mx];
    }

    auto dfs2 = [&](auto self,int now,int father)->void{
        for(auto v:g[now]){
            if(v==father)continue;
            self(self,v,now);
        }
        if(g[now].size()==1){
            if(!vis[now]){
                q.push(now);
                vis[now]=1;
            }
        }
    };
    dfs2(dfs2,1,0);

    int ans=1;
    while(!q.empty()){
        int sz=q.size();
        for(int j=1;j<=sz;j++){
            int rt=q.front();
            q.pop();
            int fa=f[rt];
            if(vis[fa])continue;
            vis[fa]=1;
            q.push(fa);
            
        }
        ans++;
    }
    
    
    cout<<ans<<'\n';
    return ;
}

signed  main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}