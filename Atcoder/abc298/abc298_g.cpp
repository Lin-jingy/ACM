#include <bits/stdc++.h>

#define int long long
int n,m,T,ans=1e18,minn;
int f[10][10][10][10][40];
int sum[10][10];

inline int get(int a,int b,int c,int d){
    return sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
}

int dfs(int a,int b,int c,int d,int k){
    if (k > (c-a+1)*(d-b+1)-1) return 1e18;
    int &val=f[a][b][c][d][k];
    if (val!=-1) return val;
    val=1e18;
    if (!k) {
        if (get(a,b,c,d)>=minn) val=get(a,b,c,d);
        return val;
    }
    for (int i(a); i < c; ++i){
        for (int j(0); j <= k-1; ++j){
            val=std::min(val,std::max(dfs(a,b,i,d,j),dfs(i+1,b,c,d,k-1-j)));
            val=std::min(val,std::max(dfs(i+1,b,c,d,j),dfs(a,b,i,d,k-1-j)));
        }
    }
    for (int i(b); i < d; ++i){
        for (int j(0); j <= k-1; ++j){
            val=std::min(val,std::max(dfs(a,b,c,i,j),dfs(a,i+1,c,d,k-1-j)));
            val=std::min(val,std::max(dfs(a,i+1,c,d,j),dfs(a,b,c,i,k-1-j)));
        }
    }
    return val;
}

signed main(){

    std::cin >> n >> m >> T;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            std::cin >> sum[i][j];
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for (int i(1); i <= n; ++i){
        for (int j(1); j <= m; ++j){
            for (int a(i); a <= n; ++a){
                for (int b(j); b <= m; ++b){
                    memset(f,-1,sizeof f);
                    minn = get(i,j,a,b);
                    int res = dfs(1,1,n,m,T);
                    if (res >= 0) ans = std::min(ans, res - minn);
                }
            }
        }
    }
    
    std::cout << ans << '\n';

    return 0;
}