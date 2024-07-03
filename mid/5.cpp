#include<iostream>
#include<cstdio>
#include<cstring>
#define N 157
using namespace std;
int n,now,ans;
int high[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			char in;
			scanf(" %c",&in);
			if(in=='W')
				++high[j];
			else
				high[j]=0;
		}
		for(int j=1;j<=n;++j)
		{
			now=high[j];
			for(int k=j;k<=n;++k)
			{
				if(!high[k])
					break;
				now=min(now,high[k]);
				ans+=now;
			}
		}
	}
	printf("%d",ans);
	return 0;
}