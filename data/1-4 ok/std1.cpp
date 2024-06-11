#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 100005
#define int long long
using namespace std;
int n,X,Y,Z,a[N];
int calc(int x){
	int l=0,ls=0,r=0,rs=0;
	rep(i,1,n)if(a[i]>x)r++,rs+=a[i];else l++,ls+=a[i];
	l=x*l-ls;r=rs-x*r;
	int res=min(l,r);
	return min(l*X+r*Y,res*Z+(l-res)*X+(r-res)*Y);
}
bool check(int x){
	return calc(x)<calc(x+1);
}
void solve(){
	scanf("%lld%lld%lld%lld",&n,&X,&Y,&Z);
	rep(i,1,n)scanf("%lld",&a[i]);
	int l=1,r=1e9,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",min(calc(ans),min(calc(ans-1),calc(ans+1))));
}
signed main(){
    for(int i = 1; i <= 22; ++i) {
        string s = format("C:/Users/123/Desktop/programming/VScode/ACM/data/4 ok/data/{}.in", i);
        string s1 = format("C:/Users/123/Desktop/programming/VScode/ACM/data/4 ok/data/r{}.out", i);
        freopen(s.data(), "r", stdin);
        freopen(s1.data(), "w", stdout);


        solve();

        fclose(stdin);
        fclose(stdout);
        std::clog << i << std::endl;



    }

}