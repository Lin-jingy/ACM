//#include<bits/stdc++.h>
//
//using namespace std;
//#define int long long
//const int N = 5e3 + 5;
//int a[N];
//unordered_map<int, pair<int, int>> mp;
//int va[N][N];
//int dp[N];
//
//void solve() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; ++i)cin >> a[i];
//    for (int i = 1; i <= n; ++i) {//预处理左右边界
//        if (mp.count(a[i])) mp[a[i]].second = i;
//        else mp[a[i]].first = i, mp[a[i]].second = i;
//    }
//    for (int i = 1; i <= n; ++i) {//预处理（i，j）的异或值
//        for (int j = i; j <= n; ++j) {
//            if (mp[a[j]].first >= i and mp[a[j]].second <= j) {
//                va[i][j] = va[i][j - 1] ^ a[j];
//            }
//        }
//    }
//    for (int i = 1; i <= n; ++i) {
//        dp[i] = max(dp[i], dp[i - 1]);
//        if (mp[a[i]].second > i)continue;
//        for (int j = i; j >= 1;) {
//            if (mp[a[j]].first >= j and mp[a[j]].second <= i) {//如果是合法的区间，进行状态转移
//                dp[i] = max(dp[i], dp[j - 1] + va[j][i]);
//                --j;
//            } else {
//                if (mp[a[j]].second > i)break;
//                if (mp[a[j]].first < j){
//                    int mid=mp[a[j]].first;
//                    for(int k=j;k>=mid;--k){
//                        if(mp[a[k]].second>i)goto A;
//                        if(mp[a[k]].first<j)mid=min(mid,mp[a[k]].first);
//                    }
//                    j=mid;
//
//                }
//            }
//        }
//        A:;
//    }
//    cout << dp[n];
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr);
//    int t = 1;
//    while (t--)solve();
//    return 0;
//}



#include<bits/stdc++.h>

#define int long long
using namespace std;

class Node {
public:
    int l, r;
    int value;
} s[10000];

int a[10000];
int vis[10000];
int dp[10000];

bool cmp(Node a, Node b) {
    if (a.r != b.r)return a.r < b.r;
    else return a.l < b.l;
}

signed main() {
    int n;
    cin >> n;
    int cnt = 0;
    unordered_map<int, int> m;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
        if (!m.count(x)) {
            m[x] = cnt++;
            s[m[x]].l = i;
            s[m[x]].r = i;
        } else {
            s[m[x]].l = min(s[m[x]].l, i);
            s[m[x]].r = max(s[m[x]].r, i);
        }
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = s[i].l; j <= s[i].r; j++) {
            s[i].l = min(s[m[a[j]]].l, s[i].l);
            s[i].r = max(s[m[a[j]]].r, s[i].r);
        }
    }
    for (int i = 0; i < cnt; i++) {
        memset(vis, 0, sizeof(vis));
        s[i].value = 0;
        for (int j = s[i].l; j <= s[i].r; j++) {
            if (!vis[a[j]]) {
                s[i].value ^= a[j];
                vis[a[j]] = 1;
            }
        }
    }
    sort(s, s + cnt, cmp);
    for (int i = 0; i < cnt; i++) {
        dp[i] = s[i].value;
        for (int j = 0; j < i; j++) {
            if (s[i].l > s[j].r)
                dp[i] = max(dp[j] + s[i].value, dp[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) ans = max(ans, dp[i]);
    cout << ans;
}