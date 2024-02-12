//60%AC
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int a[200005];
// priority_queue<int>l;
// signed main(){
//     int n,m,k;cin>>n>>m>>k;
//     for(int i=0;i<n;++i)cin>>a[i];
//     sort(a,a+n);
//     for(int i=0;i<k-1;++i)l.push(a[i]);
//     int flag=a[k-1];
//     while(m--){
//         int t;cin>>t;
//         if(t==1){
//             int x;cin>>x;
//             if(x<=flag){
//                 l.push(x);
//                 flag=l.top();
//                 l.pop();
//             }
//         }else{
//             if(k>n)cout<<"-1"<<'\n';
//             else cout<<flag<<'\n';
//         }
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int n, m, k,x,y;
int main(){
    cin >> n >> m >> k;
	while(n--)cin >> x, q.push(x);
	while (m--){
        while (q.size() > k)q.pop();
		cin >> x;
		if (x==1)cin >> y, q.push(y);
		else
		{
			if (q.size() < k)cout << "-1\n";
			else cout << q.top() << '\n';
		}
	}
}