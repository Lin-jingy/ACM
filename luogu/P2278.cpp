#include<bits/stdc++.h>
using namespace std;
#define int long long
struct fact{
    int process;
    int arrive_time;
    int use_time;
    int priority;
    int time_remaining;
    node(int process,int arrive_time,int use_time,int priority,int time_remaining):process(process){}
};
bool need1(fact a,fact b){
    if(a.priority!=b.priority)return a.priority>b.priority;
    else return a.process<b.process;
}
queue<fact>q;
priority_queue<fact,vector<fact>,need1>s;
signed main(){
    fact x;
    fact mid;
    while(cin>>x.process>>x.arrive_time>>x.use_time>>x.priority){x.time_remaining=x.use_time; q.push(x);}//数据读取
    //数据处理
    
    x=q.back();
    if(x.priority<q.back().priority&&x.arrive_time+x.use_time>q.back().arrive_time){
        
    }
    return 0;
}