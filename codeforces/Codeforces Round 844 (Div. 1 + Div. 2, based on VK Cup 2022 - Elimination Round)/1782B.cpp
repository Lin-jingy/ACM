#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
int k[200005];
signed main() {
	std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
	cin >> t;
	for(int kk=0;kk<t;++kk) {
        cin >> n;
        int pd[200005]={0},x=0;
		for(int i=0;i<n;++i){
            cin>>x;
            pd[x]++;
        }
        int ans=0;
        if(pd[0]==0)ans++;
        k[0]=pd[0];
        for(int i=1;i<n;++i){
            k[i]=k[i-1]+pd[i];
            if(!pd[i]&&k[i]==i)ans++;
        }
        cout<<ans+1<<'\n';
	}
	return 0;
}