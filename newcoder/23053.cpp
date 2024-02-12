//TLE
// #include<bits/stdc++.h>
// using namespace std;
// signed main(){
//     ios::sync_with_stdio(false);
//     string a;cin>>a;
//     int n;cin>>n;
//     for(int i=0;i<n;++i){
//         string x;cin>>x;
//         if(a.find(x)==-1){
//             int lena=a.size();
//             int lenx=x.size();
//             int k=0;
//             for(int j=0;j<lena;++j){
//                 if(a[j]==x[k])++k;
//                 if(k>=lenx)break;
//             }
//             if(k==lenx)cout<<"Yes"<<'\n';
//             else cout<<"No"<<'\n';
//         }
//         else cout<<"Yes"<<'\n';
//     }
//     return 0;
// }
#include<bits/stdc++.h>
int main()
{
	std::string str,t;
	int m,T,i;
	std::cin>>str>>T;
	while(T--)
	{
		m=0;std::cin>>t;
		for(i=0;i<str.size();i++)
		{
			if(str[i]==t[m]) m++;
			if(m>=t.size()) break;
		}
		printf("%s\n",(m>=t.size())?"Yes":"No");
	}
}