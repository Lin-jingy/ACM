//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 1e5 + 5;
int a[N], n;

class SegmentTree{
private:
    inline int ls(int x){return x << 1;}
    inline int rs(int x){return x << 1|1;}
    int f[N << 2];//?维护的区间值
    int mx[N << 2];
public:

    inline void up(int k){
        mx[k]=max(mx[ls(k)],mx[rs(k)]);
        f[k]=f[ls(k)]+f[rs(k)];
    }

    inline void build(int k,int l,int r){
        if(l==r){
            f[k]=mx[k]=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(ls(k),l,mid);
        build(rs(k),mid+1,r);
        up(k);
    }

    inline void change(int k,int l,int r,int L,int R){
        if(l==r && l>=L && r<=R){
            f[k]=mx[k]=sqrt(f[k]);
            return ;
        }   
        int mid=(l+r)>>1;
        if(L<=mid && mx[ls(k)]>1) change(ls(k),l,mid,L,R);
        if(mid<R && mx[rs(k)]>1) change(rs(k),mid+1,r,L,R);
        up(k);
    }

    inline int query(int k,int l,int r,int L,int R){
        if(L<=l && r<=R) return f[k];
        int mid=(l+r)>>1;
        int ans=0;
        if(L<=mid) ans+=query(ls(k),l,mid,L,R);
        if(mid<R) ans+=query(rs(k),mid+1,r,L,R);
        return ans;
    }

};

SegmentTree T;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    T.build(1, 1, n);
    int m;
    cin >> m;
    while(m--){
        int op, x, y;
        cin >> op >> x >> y;
        if(x > y) swap(x, y);
        if(op == 0){
            T.change(1, 1, n, x, y);
            //for(int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
        } else {
            cout << T.query(1, 1, n, x, y) << '\n';
        }
    }
    //for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
    //cout << T.query(1, 1, n, 4, 5);
    //for(int i = 1; i <= n; ++i)for(int j = i; j <= n; ++j) cout << i << ' ' << j << ' ' << T.query(1, 1, n, i, j) << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
