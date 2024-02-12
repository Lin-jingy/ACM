#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 5;
int f[4 * N], v[4 * N], a[N];

void buildtree(int k, int l, int r){
    if(l == r){
        f[k] = a[l];
        return;
    }
    int mid = l + r >> 1;
    buildtree(2 * k, l, mid);
    buildtree(2 * k + 1, mid + 1, r);
    f[k] = f[2 * k] + f[2 * k + 1];
}

void insert(int k, int l, int r, int x, int y, int z){
    if(l == x and r == y){
        v[k] += z;
        return;
    }
    f[k] += (y - x + 1) * z;
    int mid = l + r >> 1;
    if(y <= mid)insert(2 * k, l, mid, x, y, z);
    else if(x > mid)insert(2 * k + 1, mid + 1, r, x, y, z);
    else insert(2 * k, l, mid, x, mid, z), insert(2 * k + 1, mid + 1, r, mid + 1, y, z);
}

int calc(int k, int l, int r, int x, int y, int z){
    z += v[k];
    if(l == x and r == y)return f[k] + z * (y - x  + 1);
    int mid = l + r >> 1;
    if(y <= mid)return calc(2 * k, l, mid, x, y, z);
    else if(x > mid)return calc(2 * k + 1, mid + 1, r, x, y, z);
    else return calc(2 * k, l, mid, x, mid, z) + calc(2 * k + 1, mid + 1, r, mid + 1, y, z);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)cin >> a[i];
    buildtree(1, 1, n);
    int x, y, op, k;
    while(m--){
        cin >> op >> x >> y;
        if(op == 1){
            cin >> k;
            insert(1, 1, n, x, y, k);
        }else{
            cout << calc(1, 1, n, x, y, 0) << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
