#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn*maxn];

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
void solve(){
	int n = read(), m = read();
	if(n>m)swap(n,m);
	for(int i=1;i<=n*m;i++)a[i] = read();
	sort(a+1,a+1+n*m);
	int mx1=a[n*m];
	int mx2=a[n*m-1];
	int mi1=a[1];
	int mi2=a[2];
	int ans1=(mx1-mi1)*(m-1)*n+(mx1-mi2)*(n-1);
	int ans2=(mx1-mi1)*(m-1)*n+(mx2-mi1)*(n-1);
	int ans=max(ans1,ans2);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;t = read();
	while(t--)solve();
	return 0;
}

