#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,v[110],w[110];
int ans;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> dp(110);
		for(int k=1;k<=n;k++){
			if(k==i) continue;
			for(int j=m;j>=v[k];j--){
				dp[j]=max(dp[j],dp[j-v[k]]+w[k]);
			}
		}
		ans=dp[m]-dp[m-v[i]]-w[i]+1;
		if(ans<0){
			cout<<'0'<<'\n';
		}else{
			cout<<ans<<'\n';
		}
	}
	return 0;
}