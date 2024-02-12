#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5,mod=1e9+7;
int a[maxn][maxn];
int cnt[maxn][maxn][5];
bool vis[maxn][maxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void solve() {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    
    auto dfs = [&](auto self,int x,int y)->void{
        vis[x][y]=1;
        int ok=1;
        for(int i=0;i<4;i++){
            int tx=dx[i]+x;
            int ty=dy[i]+y;
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==a[x][y]+1){
                ok=0;
                if(!vis[tx][ty])self(self,tx,ty);
                for(int j=2;j<=4;j++){
                    cnt[x][y][j]+=cnt[tx][ty][j-1];
                    if(cnt[x][y][j]>=mod)cnt[x][y][j]-=mod;
                }
                cnt[x][y][4]+=cnt[tx][ty][4];
                if(cnt[x][y][4]>=mod)cnt[x][y][4]-=mod;
            }
        }
        cnt[x][y][1]=ok;
        return ;
    };

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j])dfs(dfs,i,j);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ok=1;
            for(int k=0;k<4;k++){
                int tx=dx[k]+i;
                int ty=dy[k]+j;
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
                    if(a[tx][ty]==a[i][j]-1)ok=0;
                }
            }
            if(ok){
                //cout<<i<<' '<<j<<' '<<cnt[i][j][4]<<endl;
                ans+=cnt[i][j][4];
                if(ans>=mod)ans-=mod;
            }
        }
    }
    cout<<ans%mod<<'\n';
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}