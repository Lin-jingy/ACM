// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int c[100005],a[100005],b[100005];
// signed main(){
// 	std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
//     int n,m;
//     cin>>n>>m;
//     int x;
//     for(int i=0;i<n;++i){
//         cin>>x;
//         c[i]=x%m;
//     }
//     for(int i=0;i<n/2;++i){
//         if((c[i]+c[n-1-i])%2==1 and m%2==0){cout<<"NO\n";return 0;}
//         for(int j=0;;++j){
//             if(((c[i]+c[n-1-i])%m+j*m)%2==0){
//                 a[i]=(c[i]+c[n-1-i]+j*m)/2;
//                 b[i]=m+c[i]-a[i];
//                 a[n-1-i]=a[i];
//                 b[n-1-i]=m-b[i];
// //                 if((a[i]+b[i])%m!=c[i] or (a[n-1-i]+b[n-1-i])%m!=c[n-1-i]){cout<<"NO\n";return 0;}
//                 break;
//             }
//             if(j==5){cout<<"NO\n";return 0;}
//         }
//     }
//     if(n%2==1){
//         if(m==2){
//             b[n/2]=1;
//             a[n/2]=1;
//             if((a[n/2]+b[n/2])%2!=c[n/2]){
//                 cout<<"NO\n";
//                 return 0;
//             }
//         }else{
//             cout<<"NO\n";
//             return 0;
//         }
//     }
//     cout<<"YES\n";
//     for(int i=0;i<n-1;++i)cout<<a[i]<<' ';
//     cout<<a[n-1]<<'\n';
//     for(int i=0;i<n-1;++i)cout<<b[i]<<' ';
//     cout<<b[n-1]<<'\n';
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N],b[N],c[N];
int n,m;
signed main()
{
	cin>>n>>m;
	int i,j;
	for (i=1;i<=n;++i) cin>>a[i];
	for (i=1,j=n;i<=j;i++,j--){
		int sum=a[i]+a[j];
		if(sum%2!=0) sum+=m;
		int x=(m+sum/2)%m;
		int y=(a[i]+m-x)%m;
		b[i]=x; b[j]=x;
		c[i]=y; c[j]=(-1)*y;
		if ((x-y+m)%m!=a[j]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	for(i=1;i<=n;++i) cout<<b[i]<<" ";
	cout<<"\n";
	for(i=1;i<=n;++i) cout<<c[i]<<" ";
	return 0;
}