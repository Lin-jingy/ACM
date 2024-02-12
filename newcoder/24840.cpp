#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans[100005];
stack<int> s;
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    s.push(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&a[i]>=a[s.top()])s.pop();
        if (!s.empty())ans[i] = s.top();
        s.push(i);
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<endl;
    return 0;
}