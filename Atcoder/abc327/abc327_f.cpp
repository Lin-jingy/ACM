#include <bits/stdc++.h>

//#define int long long
const int N = 2e5 + 5;
class SegmentTree{
private:
    inline int ls(int x){return x << 1;}
    inline int rs(int x){return x << 1|1;}
    int f[N << 2];//?维护的区间值
    int tag[N << 2];//?标记
    inline void push_up(int p){//?自下而上传递区间值
        f[p] = std::max(f[ls(p)], f[rs(p)]);
    }
    inline void addTag(int p, int l, int r, int d){ //?给节点p打上tag标记，并更新区间值
        tag[p] += d;
        f[p] += d;
    }
    void push_down(int p, int l, int r){//?将tag传递给子树
        //无法覆盖的情况
        if(tag[p]){ // 存在遗留tag
            int mid = l + r >> 1;
            addTag(ls(p), l, mid, tag[p]);
            addTag(rs(p), mid + 1, r, tag[p]);
            tag[p] = 0; //传递后自身标记清零
        }
    }

public:
    // void build(int p, int l, int r){//?建树
    //     tag[p] = 0;
    //     if(l == r){
    //         f[p] = a[l];
    //         return;
    //     }
    //     int mid = l + r >> 1;
    //     build(ls(p), l, mid);
    //     build(rs(p), mid + 1, r);
    //     push_up(p);//更新值
    // }
    void update(int p, int l, int r, int i, int j, int d){//?区间[i, j]加d
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
    int query(int p, int l, int r, int i, int j){//?查询[i,j]区间值
        if(l >= i and r <= j) return f[p];
        push_down(p, l, r);
        int mid = l + r >> 1;
        int res = 0;
        if(i <= mid) res += query(ls(p), l, mid, i, j);
        if(j > mid) res += query(rs(p), mid + 1, r, i, j);
        return res;
    }
}T;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, D, W;
    std::cin >> n >> D >> W;
    std::vector<std::pair<int, int>> v(n);
    for(auto &[t, x]:v) std::cin >> t >> x;
    std::sort(v.begin(), v.end());
    std::deque<std::pair<int, int>> dq;
    int ans = 0;
    for(auto [t, x]:v) {
        dq.push_back({t, x});
        T.update(1, 1, N, x, x + W - 1, 1);
        while(!dq.empty() and t - dq.front().first > D - 1) {
            T.update(1, 1, N, dq.front().second, dq.front().second + W - 1, -1);
            dq.pop_front();
        }
        ans = std::max(T.query(1, 1, N, 1, N), ans);
    }
    std::cout << ans << '\n';
    return 0;
}
