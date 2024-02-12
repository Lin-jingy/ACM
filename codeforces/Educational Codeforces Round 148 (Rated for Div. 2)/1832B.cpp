// #include<bits/stdc++.h>
// #include<unordered_map>
// #include<unordered_set>

// using namespace std;
// #define int long long 
// using PII = pair<int ,int>;
// const int N = 2e5 + 5;
// int a[N];

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     int sum = 0;
//     for(int i = 1; i <= n; ++ i){
//         cin >> a[i];
//         sum += a[i];
//     }
//     sort(a + 1, a + 1 + n);
//     int mx = n, mn = 1;
//     int suml = 0, sumr = 0;
//     int i = 1;
//     while(m --){
//         suml += a[i] + a[i - 1];
//         sumr += a[mx];
//         if(suml - a[mn] >= sumr - a[mx])mx--;
//         else mn += 2;
//         i += 2;
//     }
//     cout << sum << '\n';
// }

// signed main(){
//     ios::sync_with_stdio(0),cin.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t--)solve();
//     return 0;
// }


#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
 const int N = 2e5 + 5;
 int a[N], p[N];


void solve(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        ans += a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++ i)p[i] = a[i] + p[i - 1];
    int mx = 0;
    for(int i = 0; i <= m; ++ i){
        int r = (m - i) * 2;
        int k = p[n - i] - p[r];
        mx = max(mx, k);
    }
    cout << mx << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
