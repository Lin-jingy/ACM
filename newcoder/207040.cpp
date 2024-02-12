#include<bits/stdc++.h>
using namespace std;
#define int long long
int s=0,a[100005]={0};
signed main(){
	int x,n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x,a[i]=a[i-1]+x,s+=x;
	cin>>x;
	for(int i=1,x=1;i<n;i++)
	{
		while(a[i]-a[x-1]>s/2)ans=max(ans,s-a[i]+a[x-1]),x++;
		ans=max(ans,a[i]-a[x-1]);
	}
	cout<<ans;
	return 0;
}