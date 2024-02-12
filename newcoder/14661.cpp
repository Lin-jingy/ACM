#include<bits/stdc++.h>
using namespace std;
deque <int> q;
int main()
{
	int n,m,a,x;
	cin>>n>>m;
	while(m--)
	{
		cin>>x;
		if(x==1) cin>>a,q.push_front(a);
		if(x==2) q.pop_front();
		if(x==3) cin>>a,q.push_back(a);
		if(x==4) q.pop_back();
		if(x==5) reverse(q.begin(),q.end());
		if(x==6)
		{
			cout<<q.size()<<endl;
			for(int i=0;i<q.size();i++)
				cout<<q[i]<<" ";
			cout<<endl;
		}
		if(x==7)
			sort(q.begin(),q.end());
	}
    return 0;
}
