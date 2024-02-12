/*
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 5e5 + 5;
int a[N], f[4 * N];

void buildtree(int k, int l, int r){
    if(l == r){
        f[k] = a[l];
        return;
    }
    int mid = l + r >> 1;
    buildtree(k * 2, l, mid);
    buildtree(k * 2 + 1, mid + 1, r);
    f[k] = f[2 * k] + f[2 * k + 1];
}

void add(int k, int l, int r, int x, int y){
    f[k] += y;
    if(l == r)return;
    int mid = l + r >> 1;
    if(x <= mid)add(2 * k, l, mid, x, y);
    else add(2 * k + 1, mid + 1, r, x, y);
}

int calc(int k, int l, int r, int b, int e){
    if(l == b and r == e)return f[k];
    int mid = l + r >> 1;
    if(e <= mid)return calc(2 * k, l, mid, b, e);
    else if(b > mid)return calc(2 * k + 1, mid + 1, r, b ,e);
    else return calc(2 * k, l, mid, b, mid) + calc(2 * k + 1, mid + 1, r, mid + 1, e);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    buildtree(1, 1, n);
    int op, x, y;
    while(m --){
        cin >> op >> x >> y;
        if(op == 1)add(1, 1, n, x, y);
        else cout << calc(1, 1, n, x, y) << '\n';
    }

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
*/

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"
#define lowbit(x) (x & (-x))

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int>a(n + 1), f(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    auto init = [&](int n){
        for (int i = 1; i <= n; i++) 
            for (int j = i; j <= n; j += lowbit(j)) 
                f[j] += a[i];
    };
    auto add = [&](int pos, int k){
        a[pos] += k;
        for(; pos <= n; pos += lowbit(pos)) f[pos] += k;
    };
    auto pre = [&](int x){
        int sum = 0;
        for(; x > 0; x -= lowbit(x)) sum += f[x];
        return sum;
    };
    auto query = [&](int l, int r){
        return pre(r) - pre(l - 1);
    };
    init(n);
    while(m--){
        int op, x, y;
        std::cin >> op >> x >> y;
        if(op == 1) add(x, y);
        else std::cout << query(x, y) << '\n';
    }
    return 0;
}
