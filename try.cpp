#include<bits/stdc++.h>
#define R register
#define N 1000008
#define ls o<<1
#define rs o<<1|1
using namespace std;
int tr[N<<2],ans,n,sum[N];
inline void up(int o){tr[o]=min(tr[ls],tr[rs]);return;};
void build(int o,int l,int r)
{
	if(l==r)
	{
		tr[o]=sum[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	up(o);
}
int query(int o,int l,int r,int x,int y)
{
	if(x<=l and y>=r)return tr[o];
	int mid=(l+r)>>1,res=2147483647;
	if(x<=mid)res=min(res,query(ls,l,mid,x,y));
	if(y>mid)res=min(res,query(rs,mid+1,r,x,y));
	return res;
}
int main()
{
	scanf("%d",&n);
	for(R int i=1,x;i<=n;i++)scanf("%d",&x),sum[i]=sum[i-1]+x;
	build(1,1,n);
	for(R int i=2;i<=n;i++)
	{
		if(query(1,1,n,i,n)-sum[i-1]<0)continue;
		if(sum[n]-sum[i-1]+query(1,1,n,1,i-1)>=0)
			ans++;
	}	
	printf("%d",ans+(tr[1]>=0));
}