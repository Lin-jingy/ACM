#include<iostream>
#include<queue>

using namespace std;
#define int long long 
int a[100000];
priority_queue<int>mq;//大顶
priority_queue<int,vector<int>,greater<int> >q;//小顶

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    int x,k=1;
    int si=0;
    for(int i=1;i<=m;++i){
        cin>>x;
        while((int)q.size()+(int)mq.size()<x)q.push(a[k++]);
        while(!q.empty()and !mq.empty() and q.top()<mq.top()){
            q.push(mq.top());
            mq.pop();
            mq.push(q.top());
            q.pop();
        }
        while((int)mq.size()<i-1){
            mq.push(q.top());
            q.pop();
        }
        cout<<q.top()<<'\n';
    }


}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    solve();
    return 0;
}