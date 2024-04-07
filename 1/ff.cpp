#include <bits/stdc++.h>
#include <vector>
#define lobwit(x) ((x)&-(x))
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
    cout<<#x<<" -> "; \
    err(x); \
}while(0)
void err(){
    cout<<endl<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
    cout<<fixed<<setprecision(10)<<arg<<' ';
    err(args...);
}
struct node{
    int l,r,cnt,val1,val2;
};
void solve() {
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>stk;
    vector<int>ll(n+1),rr(n+1);
    vector<int>t(n+1);
    auto add = [&](int x)->void{
        while(x<=n){
            t[x]++;
            x+=lobwit(x);
        }
    };
    auto ask = [&](int x)->int{
        int res=0;
        while(x){
            res+=t[x];
            x-=lobwit(x);
        }
        return res;
    };
    for(int i=1;i<=n;i++){
        ll[a[i]]+=ask(a[i]);
        add(a[i]);
    }
    t=vector<int>(n+1);
    for(int i=n;i>=1;i--){
        rr[a[i]]=ask(a[i]);
        add(a[i]);
    }
    // for(int i=1;i<=n;i++){
    //     dbg(ll[i],rr[i]);
    // }
    int sum=0;
    for(int i=1;i<=n;i++)sum+=min(ll[i],rr[i]);

    vector<int>root(n+1);
    int tot=0;
    vector<node>tr(n*32);
    auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
        u=++tot;
        tr[u]=tr[v];
        tr[u].cnt++;
        tr[u].val1+=min(ll[x]-1,rr[x]+1)-min(ll[x],rr[x]);
        tr[u].val2+=min(ll[x]+1,rr[x]-1)-min(ll[x],rr[x]);
        if(l==r)return ;
        int mid=(l+r)>>1;
        if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
        else self(self,tr[u].r,tr[v].r,mid+1,r,x);
    };
    auto query1 = [&](auto self,int u,int v,int l,int r,int x)->int{
        //dbg(l,r);
        if(l==r)return tr[u].cnt-tr[v].cnt;
        int mid=(l+r)>>1;
        int d=tr[tr[u].l].cnt-tr[tr[v].l].cnt;
        if(x<=mid)return self(self,tr[u].l,tr[v].l,l,mid,x);
        else return self(self,tr[u].r,tr[v].r,mid+1,r,x)+d;
    };
    auto query2 = [&](auto self,int u,int v,int l,int r,int x,int y)->int{
        if(x<=l&&r<=y)return tr[u].val1-tr[v].val1;
        int mid=(l+r)>>1;
        int res=0;
        if(x<=mid)res+=self(self,tr[u].l,tr[v].l,l,mid,x,y);
        if(y>mid) res+=self(self,tr[u].r,tr[v].r,mid+1,r,x,y);
        return res;
    };
    auto query3 = [&](auto self,int u,int v,int l,int r,int x,int y)->int{
        if(x<=l&&r<=y)return tr[u].val2-tr[v].val2;
        int mid=(l+r)>>1;
        int res=0;
        if(x<=mid)res+=self(self,tr[u].l,tr[v].l,l,mid,x,y);
        if(y>mid) res+=self(self,tr[u].r,tr[v].r,mid+1,r,x,y);
        return res;
    };
    for(int i=1;i<=n;i++){
        updata(updata,root[i],root[i-1],1,n,a[i]);
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        if(l>r)swap(l,r);
        int ans=sum;
        ans-=min(ll[a[l]],rr[a[l]]);
        ans-=min(ll[a[r]],rr[a[r]]);
        int cnt1,cnt2;
        if(a[l]!=1){
            cnt1=query1(query1,root[r],root[0],1,n,a[l]-1);
            //if(a[r]<a[l])cnt1++;
            cnt2=a[l]-1-cnt1;
            //dbg(a[l],cnt1,cnt2);
            ans+=min(cnt1,cnt2);
        }
        if(a[r]!=1){
            cnt1=query1(query1,root[l-1],root[0],1,n,a[r]-1);
            cnt2=a[r]-1-cnt1;
            //dbg(a[r],cnt1,cnt2);
            ans+=min(cnt1,cnt2);
        }
        //dbg(i,ans);
        int t=0;
        if(a[l]>a[r])t=1;
        l++,r--;
        if(l<=r){
            if(!t){
                ans+=query2(query2,root[r],root[l-1],1,n,a[l-1],a[r+1]);
            }else{
                ans+=query3(query3,root[r],root[l-1],1,n,a[r+1],a[l-1]);
            }
        }
        cout<<ans<<'\n';
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}
