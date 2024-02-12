#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans;
int a[100000005];
signed main(){
    std::ios::sync_with_stdio(false);
    int l,m;
	cin>>l>>m;
	for(;m--;){
        int x,y;
		cin>>x>>y;
		a[x]++;a[y+1]--;//差分
	}
    int sum=0;
    for(int i=0;i<=l;i++){//前缀和
        sum+=a[i];
		if(sum<=0)ans++;
	}
    cout<<ans;
}