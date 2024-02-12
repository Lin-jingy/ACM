#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while (t--){
		int x,y,xp,yp;
		cin>>x>>y>>xp>>yp;
		int a=max(abs(xp-x),abs(xp));
		int b=max(abs(yp-y),abs(yp));
		int s=a*b+x*y;
		int ka=min(a,x);
		int kb=min(b,y);
		double ans=0;
		ans=double(ka*kb)*1.0/(s-ka*kb);
		cout<<ans<<'\n';
	}
}