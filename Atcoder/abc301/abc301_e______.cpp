//暴力TLE

// #include<bits/stdc++.h>
// #include<unordered_map>
// #include<unordered_set>

// using namespace std;
// #define int long long 
// using PII = pair<int ,int>;
// using PSI = pair<string, int>;
// using PIS = pair<int, string>;
// #define inf LONG_LONG_MAX
// #define yes cout << "Yes\n"
// #define no cout << "No\n"

// const int N = 305;
// char a[N][N];
// int px[] = {1, -1, 0, 0};
// int py[] = {0, 0, 1, -1};
// class node{
//     public:
//     int x, y, val, last;
// };

// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     k = min(k, 1900ll);
//     queue<node>q;
//     for(int i = 1; i <= n; ++i){
//         string s;
//         cin >> s;
//         for(int j = 0; j < m; ++j){
//             a[i][j + 1] = s[j];
//             if(a[i][j + 1] == 'S') q.push({i, j + 1, 0, k});
//         }
//     }
//     int ans = -1;
//     while(!q.empty()){
//         auto mid = q.front();
//         q.pop();
//         int &x = mid.x, &y = mid.y, &val = mid.val, &last = mid.last;
//         if(last == 0 or val + last < ans)continue;
//         for(int i = 0; i < 4; ++i){
//             if(x + px[i] >= 1 and x + px[i] <= n and y + py[i] >= 1 and y + py[i] <= m){
//                 if(a[x + px[i]][y + py[i]] == '#')continue;
//                 else if(a[x + px[i]][y + py[i]] == 'o') q.push({x + px[i], y + py[i], val + 1, last - 1});
//                 else if(a[x + px[i]][y + py[i]] == '.') q.push({x + px[i], y + py[i], val, last - 1});
//                 else if(a[x + px[i]][y + py[i]] == 'G') ans = max(ans, val), q.push({x + px[i], y + py[i], val, last - 1});
//             }
//         }
//     }
//     cout << ans << '\n';

// }

// signed main(){
//     ios::sync_with_stdio(0),cin.tie(0);
//     int _ = 1;
//     //cin >> _;
//     while(_--)solve();
//     return 0;
// }

// ! TSP(旅行箱问题)
// ! 状压DP

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

char a[305][305];
int dp[1 << 19][18];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];
    

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
