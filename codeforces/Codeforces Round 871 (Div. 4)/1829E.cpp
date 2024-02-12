#include<bits/stdc++.h>

using namespace std;
#define int long long 
const int N = 1e3 + 5;
int a[N][N], st[N][N];
int k, n, m;

int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

void dfs(int x, int y){
    if(st[x][y] or a[x][y] == 0)return;
    st[x][y] = 1;
    k += a[x][y];
    if(x - 1 >= 1)dfs(x - 1, y);
    if(x + 1 <= n)dfs(x + 1, y);
    if(y - 1 >= 1)dfs(x, y - 1);
    if(y + 1 <= m)dfs(x, y + 1);
}


void solve(){
    n = read(), m = read();
    for(int i = 1; i <= n; ++ i)for(int j = 1; j <= m; ++ j)a[i][j] = read(), st[i][j] = 0;
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            k = 0;
            if(st[i][j])continue;
            dfs(i, j);
            ans = max(ans, k);
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    t = read();
    while(t--)solve();
    return 0;
}