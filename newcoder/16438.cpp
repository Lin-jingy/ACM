#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int a,b,ans=0;
    int m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	cin>>a>>b;
	for(int i=1;i<=12;i++){
	    for(int j=1;j<=m[i];j++){
            int x=0,y=0;
		    x=j%10*1000+j/10*100+i%10*10+i/10;
            y=x*10000+i*100+j;
		    if(y>=a&&y<=b)ans++;
	    }
    }
	cout<<ans;
	return 0;
}