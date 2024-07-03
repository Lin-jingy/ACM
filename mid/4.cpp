#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define ls tree[rt].lson
#define rs tree[rt].rson
#define rt1 rt<<1
#define rt2 (rt<<1)|1
using namespace std;
struct Tree
{
	bool tag[30];
	int s[30];
	int lson;
	int rson;
}tree[400005];
struct node
{
	int v[30];
}zero;
int n,q;
int a[100005];
char s[100005];
void pushdown(int rt)
{
	if(ls==rs)
	{
		return;
	}
	for(int i=1;i<=26;i++)
	{
		if(tree[rt].tag[i])
		{
			for(int j=1;j<=26;j++)
			{
				tree[rt1].tag[j]=0;
				tree[rt1].s[j]=0;
				tree[rt2].tag[j]=0;
				tree[rt2].s[j]=0;
			}
			tree[rt1].tag[i]=1;
			tree[rt2].tag[i]=1;
			tree[rt1].s[i]=tree[rt1].rson-tree[rt1].lson+1;
			tree[rt2].s[i]=tree[rt2].rson-tree[rt2].lson+1;
			tree[rt].tag[i]=0;
			break;
		}
	}
}
void buildtree(int rt,int l,int r)
{
	tree[rt].lson=l;
	tree[rt].rson=r;
	if(l==r)
	{
		tree[rt].s[a[l]]=1;
		return;
	}
	int mid=(l+r)>>1;
	buildtree(rt1,l,mid);
	buildtree(rt2,mid+1,r);
	for(int i=1;i<=26;i++)
	{
		tree[rt].s[i]=tree[rt1].s[i]+tree[rt2].s[i];
	}
}
node add(node x,node y)
{
	node ret=zero;
	for(int i=1;i<=26;i++)
	{
		ret.v[i]=x.v[i]+y.v[i];
	}
	return ret;
}
node query(int rt,int l,int r)
{
	if(ls>r||rs<l)
	{
		return zero;
	}else if(ls>=l&&rs<=r)
	{
		node ret=zero;
		for(int i=1;i<=26;i++)
		{
			ret.v[i]=tree[rt].s[i];
		}
		return ret;
	}
	pushdown(rt);
	int mid=(ls+rs)>>1;
	return add(query(rt1,l,r),query(rt2,l,r));
}
void update(int rt,int l,int r,int val)
{
	if(ls>r||rs<l)
	{
		return;
	}
	if(ls>=l&&rs<=r)
	{
		for(int i=1;i<=26;i++)
		{
			tree[rt].s[i]=0;
			tree[rt].tag[i]=0;
		}
		tree[rt].tag[val]=1;
		tree[rt].s[val]=rs-ls+1;
		return;
	}
	pushdown(rt);
	int mid=(ls+rs)>>1;
	if(l<=mid)
	{
		update(rt1,l,r,val);
	}
	if(r>mid)
	{
		update(rt2,l,r,val);
	}
	for(int i=1;i<=26;i++)
	{
		tree[rt].s[i]=tree[rt1].s[i]+tree[rt2].s[i];
	}
}
void pushit(int rt)
{
	pushdown(rt);
	if(ls==rs)
	{
		return;
	}
	pushit(rt1);
	pushit(rt2);
}
void print(int rt)
{
	if(ls==rs)
	{
		for(int i=1;i<=26;i++)
		{
			if(tree[rt].s[i])
			{
				printf("%c",i-1+'a');
				return;
			}
		}
	}
	print(rt1);
	print(rt2);
}
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
//	freopen("third.in","r",stdin);
//	freopen("third.out","w",stdout);
	n=read(),q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i]-'a'+1;
	}
	buildtree(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read(),typ=read();
		node temp=query(1,l,r);
		if(typ==1)
		{
			for(int j=1;j<=26;j++)
			{
				update(1,l,l+temp.v[j]-1,j);
				l+=temp.v[j];
			}
		}else
		{
			for(int j=26;j>=1;j--)
			{
				update(1,l,l+temp.v[j]-1,j);
				l+=temp.v[j];
			}
		}
	}
	pushit(1);
	print(1);
	printf("\n");
	return 0;
}