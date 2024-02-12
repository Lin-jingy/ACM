//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
//#define int long long //卡MLE
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

int n, m;
const int N = 1005;
int a[N][N];

class SegmentTree{
private:
    inline int ls(int x){return x << 1;}
    inline int rs(int x){return x << 1|1;}
    int f[N << 2];//?维护的区间值
    int tag[N << 2];//?标记

    inline void push_up(int p){//?自下而上传递区间值
        f[p] = f[ls(p)] + f[rs(p)]; // 求区间和
        /* 
        !求区间最值
        f[p] = max(f[ls(p)], f[rs(p)]);
        */
    }

    inline void addTag(int p, int l, int r, int d){ //?给节点p打上tag标记，并更新区间值
        tag[p] += d;
        f[p] += d * (r - l + 1);
    }

    inline void push_down(int p, int l, int r){//?将tag传递给子树
        //无法覆盖的情况
        if(tag[p]){ // 存在遗留tag
            int mid = l + r >> 1;
            addTag(ls(p), l, mid, tag[p]);
            addTag(rs(p), mid + 1, r, tag[p]);
            tag[p] = 0; //传递后自身标记清零
        }
    }

public:

    inline void build(int p, int l, int r, int t){//?建树
        tag[p] = 0;
        if(l == r){
            f[p] = a[t][l];
            return;
        }
        int mid = l + r >> 1;
        build(ls(p), l, mid, t);
        build(rs(p), mid + 1, r, t);
        push_up(p);//更新值
    }

    inline void update(int p, int l, int r, int i, int j, int d){//?区间[i, j]加d
        if(i <= l and r <= j){
            addTag(p, l, r, d);
            return;
        }
        push_down(p, l, r);
        int mid = l + r >> 1;
        if(i <= mid) update(ls(p), l, mid, i, j, d);
        if(j > mid) update(rs(p), mid + 1, r, i, j, d);
        push_up(p);//更新当前区间值
    }

    inline int query(int p, int l, int r, int i, int j){//?查询[i,j]区间值
        if(l >= i and r <= j) return f[p];
        push_down(p, l, r);
        int mid = l + r >> 1;
        int res = 0;
        if(i <= mid) res += query(ls(p), l, mid, i, j);
        if(j > mid) res += query(rs(p), mid + 1, r, i, j);
        return res;
    }

};

SegmentTree T[N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> a[i][j];
        T[i].build(1, 1, n, i);
    }
    int op, x1, y1, x2, y2;
    //int k = T[2].query(1, 1, n, 1, 6);
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> x1 >> y1;
            if(a[x1][y1] == 1) T[x1].update(1, 1, n, y1, y1, -1), a[x1][y1] = 0;
            else T[x1].update(1, 1, n, y1, y1, 1), a[x1][y1] = 1;
        }else{
            cin >> x1 >> y1 >> x2 >> y2;
            int sum = 0;
            for(int i = x1; i <= x2; ++i){
                sum += T[i].query(1, 1, n, y1, y2);
            }
            cout << sum << '\n';
        }
    }
    
    
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
