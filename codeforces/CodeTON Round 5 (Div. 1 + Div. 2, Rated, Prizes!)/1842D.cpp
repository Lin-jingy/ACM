#include<bits/stdc++.h>
using namespace std;

#define int long long
const int inf=4557430888798830398;
const int N = 5e5 + 5;
vector<pair<int,int>> G[N];
int dis[N<<2];
bool vis[N<<2];
int n,m,k;
int a[N];

struct node{
	int dis,id;
	friend bool operator < (node a,node b){
		return a.dis>b.dis;
	}
};

void dij(int s){
	memset(vis,0,sizeof vis);
	priority_queue<node> q;
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
    q.push({0,s});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:G[u]){
			int k=i.first,w=i.second;
			if(dis[k]>dis[u]+w){
				dis[k]=dis[u]+w;
				q.push({dis[k],k});
			}
		}
	}
}

struct node2 {
    int sta[110],t;
};

vector<node2> ans;

signed main(){
	cin >> n >> m;
	for(int i(1); i <= m; i++){
		int u, v, w;
        cin >> u >> v >> w;
		G[u].push_back({v, w});
        G[v].push_back({u, w});
	}
	dij(n);
	if(dis[1]>=inf) {
        cout << "inf";
        return 0;
    }
	cout << dis[1] << ' ';
    while(dis[1]!=0){
	    int _min=inf;
	    for(int i=1;i<=n;i++) if(dis[i]>0&&dis[i]<_min) _min=dis[i];
		node2 a;
		for(int i=1;i<=n;i++) a.sta[i]=dis[i]>0;
		a.t=_min;
		ans.push_back(a);
		for(int i=1;i<=n;i++) dis[i]-=_min;
	}
	cout << ans.size() << '\n';
	for(auto it:ans){
	    for(int i(1); i <= n; i++) cout << it.sta[i];
	    cout << ' ' << it.t << '\n';
	}
    return 0;
}