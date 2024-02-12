
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define quick ios::sync_with_stdio(0),cin.tie(0);
const int N = 5e3 + 5;
int a[N];
int k = 1;
int p[N];
void solve() {
    int n; cin >> n;
    cin >> a[1];
    p[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        int it = lower_bound(p + 1, p + 1 + k, a[i]) - p;
        p[it] = a[i];
        if (it > k)++k;
    }
    cout << k;
    return;
}
signed main() {
    quick;
    solve();
    return 0;
}




//#include<bits/stdc++.h>
//int a[5005], p[5005], k = 1, n, it;
//signed main() {
//    std::cin >> n >> a[1];
//    p[1] = a[1];
//    for (int i = 2; i <= n; ++i) {
//        std::cin >> a[i];
//        it = std::lower_bound(p + 1, p + 1 + k, a[i]) - p;
//        p[it] = a[i];
//        if (it > k)++k;
//    }
//    std::cout << k;
//    return 0;
//}