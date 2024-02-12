// #include <bits/stdc++.h>

// using namespace std;
// #define int long long 
// const int N = 2005;
// const int INF = 0x3f3f3f3f;
// typedef pair<int, int> PII;
// int n, e;
// int a[N][N], dis[N];
// bool st[N];
// int sum, mn = 0x3f;

// void dijkstra(){
//     memset(dis, INF, sizeof dis);
//     dis[1] = 0;
//     priority_queue<PII, vector<PII>, greater<PII>> q;
//     q.push({0, 1});
//     while(!q.empty()){
//         auto t = q.top();
//         int pos = t.second, ds = t.first;
//         q.pop();
//         if(st[pos])continue;
//         st[pos] = true;
//         for(int i = 1; i <= n; ++i){
//             int k = a[pos][i];
//             if(dis[i] > k + ds){
//                 dis[i] = k + ds;
//                 q.push({dis[i],i});
//             }
//         }
//         if(a[pos][n] != 0x3f){
//             if(pos == n)break;
//             //cout << dis[n] << '\n';
//             if(mn > dis[n]){
//                 sum = 1;
//                 mn = dis[n];
//             }else if(dis[n] == mn){
//                 ++sum;
//             }
//         }
//     }
//     if(dis[n] == INF) cout << "No answer";
//     else {
//         cout << dis[n] << ' ' << sum;
//     }
// }

// void solve(){
//     cin >> n >> e;
//     memset(a, INF, sizeof a);
//     while(e--){
//         int x, y, k;
//         cin >> x >> y >> k;
//         a[x][y] = min(a[x][y], k);
//     }
//     dijkstra();

// }

// signed main(){
//     ios::sync_with_stdio(false), cin.tie(nullptr);
//     solve();
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int N = 2005;
typedef pair<int, int> PII;
int n, e;
int a[N][N], dis[N];
bool st[N];
int sum[N];

void dijkstra(){
    for(int i = 0; i < N; ++i) dis[i] = INT_MAX;
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    sum[1] = 1;
    while(!q.empty()){
        auto t = q.top();
        int pos = t.second, ds = t.first;
        q.pop();
        if(st[pos])continue;
        st[pos] = true;
        for(int i = 1; i <= n; ++i){
            int k = a[pos][i];
            if(dis[i] > k + ds and a[pos][i] != INT_MAX and pos != i){
                dis[i] = k + ds;
                sum[i] = sum[pos];
                q.push({dis[i],i});
            }else if(a[pos][i] != INT_MAX and pos != i and dis[i] == k + ds)sum[i] += sum[pos];
        }
    }
    if(dis[n] == INT_MAX) cout << "No answer";
    else {
        cout << dis[n] << ' ' << sum[n];
    }
}

void solve(){
    cin >> n >> e;
    //memset(a, 0x3f, sizeof a);
    for(int i = 0; i < N; ++i)for(int j = 0; j < N; ++j) a[i][j] = INT_MAX;
    while(e--){
        int x, y, k;
        cin >> x >> y >> k;
        a[x][y] = min(a[x][y], k);
    }
    dijkstra();

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}

/*


5 5
1 2 1
2 3 1
3 4 1
4 5 1
1 4 3
*/