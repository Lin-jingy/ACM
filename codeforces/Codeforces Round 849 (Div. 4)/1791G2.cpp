// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// signed main(){
//     ios::sync_with_stdio(0),cin.tie(0);
//     int t;cin>>t;
//     while(t--){
//         vector<int>a,b,p;
//         int n,c;
//         cin>>n>>c;
//         int x;
//         for(int i=0;i<n;++i){cin>>x;a.emplace_back(x);}
//         for(int i=0;i<n;++i)b.emplace_back(a[i]+i+1);
//         int mins=0;
//         for(int i=1;i<n;++i){
//             if(b[i]<b[mins])mins=i;
//         }
//         int ans=0;
//         if(c>=b[mins])c-=b[mins],++ans;
//         for(int i=0;i<n;++i)
//             if(i!=mins)
//                 p.emplace_back(min(a[i]+i+1,a[i]+n-i));
//             else
//                 p.emplace_back(INT_MAX);
//         sort(p.begin(),p.end());
//         for(int i=0;i<n&&c>=0;++i){
//             if(c>=p[i])++ans,c-=p[i];
//         }
//         cout<<ans<<'\n';
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// bool fact(pair<int,int> a,pair<int,int> b){
//     return a.first<b.first;
// } 
// signed main(){
//     ios::sync_with_stdio(0),cin.tie(0);
//     int t;cin>>t;
//     while(t--){
//         vector<int>a;
//         vector<pair<int,int>>b,p;
//         int n,c;
//         cin>>n>>c;
//         int x;
//         for(int i=0;i<n;++i){cin>>x;a.emplace_back(x);}
//         for(int i=0;i<n;++i){
//             b.push_back({a[i]+i+1,i});
//             p.push_back({min(a[i]+i+1,a[i]+n-i),i});
//         }
//         sort(b.begin(),b.end(),fact);
//         sort(p.begin(),p.end(),fact);
//         int k=0,ans=0;
//         if(b[0].first<=c)ans=1;
//         for(int i=0;i<n;++i){
//             if(p[i].second!=b[i].second && p[i].first<=c-b[k].first){
//                 c-=p[i].first;
//                 ++ans;
//                 ++k;
//             }else if(p[i].second!=b[i].second && p[i].first>c-b[k].first)break;
//             else if(p[i].second==b[i].second && k+1<n && p[i].first<=c-b[++k].first){
//                 c-=p[i].first;
//                 ++ans;
//             }else if(p[i].second==b[i].second && k+1<n && p[i].first>c-b[++k].first)break;
//             else {ans=n;break;}
//         }
//         if(n==1 && a[0]+1>=c)cout<<"0\n";
//         else if(ans<=n)cout<<ans<<'\n';
//         else cout<<n<<'\n';
//     }
//     return 0;
// }

//对于每个传送器，我们花费的代价有两个：a[i]+i或者a[i]+n-i+1。
//若不考虑起始点为0的话，只需要将这两个花费取min然后排序即可。
//但是因为起始点为0，所以我们所选的第一个传送器它的花费必然是a[i]+i，
//因此我们枚举所有传送器作为第一个传送器的情况，
//然后用二分查找去找能够使用到的传送器的最大数量，
//但是这里有可能包括我们第一个传送器的价值，
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n ,m,h;
int s[200005],k[200005],cnt[200005];
int find(int x)
{
		int l=0,r=n;
		while(r>l)
		{
			int mid=l+r+1>>1;
			if(cnt[mid]<=x)l=mid;
			else r=mid-1;
		}
		return l;
}
 
void slove( ){
	int t;
	cin>>n>>m;
	map<int,int>q;
	for(int i =1;i<=n;i++){
	    cin>>s[i];
	    k[i]=min(s[i]+i,s[i]+n-i+1);
	    q[i]=k[i];//第i个人需要的最小的花费
	}	
	sort(k+1,k+1+n);
	for(int i =1;i<=n;i++)cnt[i]=cnt[i-1]+k[i];
	int sum=0;
	for(int i =1;i<=n;i++){
		int res=m;
		if(s[i]+i>res){
			continue;
		}
		res-=(s[i]+i);
		int si=find(res);
		if(k[si]<q[i])//如果最小花费大于第k个人的花费那么就说明一定用不到这种情况
		sum=max(sum,si+1);
		else sum=max(sum,find(res+q[i]));//否则就会用到这个机器，那么就加上他然后再查找一边即可
	}
	cout<<sum;
	cout<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	slove();
	return 0;
}