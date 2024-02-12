//TLE代码
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main(){
//     int t;cin>>t;
//     for(int ii=0;ii<t;++ii){
//         int n;cin>>n;
//         int k=1;
//         vector<string>v;
//         vector<string>::iterator it;
//         int ans=0;
//         for(int i=0;i<n;++i){
//             string zt,name;
//             cin>>zt>>name;
//             if(zt=="in"){v.push_back(name);++ans;++k;}
//             else{
//                 if(name==*v.begin()){
//                     v.erase(v.begin());
//                 }else{
//                     --ans;
//                     for(it=v.begin();it!=v.end();++it){
//                         if(*it==name){
//                             v.erase(it);
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//         cout<<ans;
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

string op,name;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
	    int res=n/2;
        queue<string>q;
map<string,int>mp;
		for(int i=1;i<=n;i++)
		{
			cin >> op >> name;
			if(op=="in")
			{
				q.push(name);
			}
			else if(op=="out")
			{
				while(mp[q.front()]) q.pop();
				if(q.front()!=name) res--;
				mp[name]=1;
			}
		}
		cout << res << endl;
	}
}