#include<iostream>
#include<queue>

using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(0)

class node{
public:
    string a;
    int interval;
    int time;
    bool operator< (const node &s)const{
        if(time!=s.time)return time>s.time;
        else return a>s.a;
    }
};

// struct cmp{
//     bool operator() (const node &a, const node &b)const{
//         if(a.time!=b.time)return a.time>b.time;
//         else return a.a>b.a;
//     }
// };

priority_queue<node,vector<node>>q;

void solve(){
    string lo;
    node x;
    while(cin>>lo){
        if(lo=="#")break;
        cin>>x.a>>x.interval;
        x.time=x.interval;
        q.push(x);
    }
    int n;
    cin>>n;
    while(n--){
        cout<<q.top().a<<'\n';
        node x=q.top();
        x.time+=x.interval;
        q.pop();
        q.push(x);
    }
}
signed main(){
    quick;
    solve();

    return 0;
}