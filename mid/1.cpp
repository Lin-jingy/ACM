#include<bits/stdc++.h>
using namespace std;
const int N=1001,mod=10301;
int n,a,b,f[N][N],ans;
int main(){
	cin>>n>>a>>b;
	for(int i=0;i<=n;i++)
		f[i][i]=1;
	for(int i=0;i<=n;i++)
		for(int j=i-1;j>=0;j--)
			f[i][j]=f[i][j+1]+f[i-j][j],f[i][j]%=mod;
	for(int i=a;i<=n-b;i++)
		ans+=(f[i][a]-f[i-1][a])*f[n-i][b]%mod,ans=(ans+mod)%mod;//注意答案可能出现负数
	cout<<ans;
	return 0;
}