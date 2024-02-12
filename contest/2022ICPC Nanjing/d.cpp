#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 5;
int n,k,m,c,d,ans;
int a[maxn];

bool check(int x) {
    deque<int>cnt(n + 1);
    int res = 0,check = 0,bigger = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] >= x) res++;
        if (a[i] > x) bigger++;
    }
    if (bigger >= k) return 0;
    set<int>ok;
    for (int i = 1;i <= m;i++) {
        if (x - a[i] - c <= 0) {
            bigger++;
            res++;
            cnt[i - 1]++;
            continue;
        }
        int need = (x - a[i] - c) / d;
        if ((x - a[i] - c) % d) need++;
        //cout << need;
        if (i >= need) {
            res++;
            bigger++;
            cnt[min(i - need,i - 1)]++;
        }
        if (need * d + c + a[i] == x) {
            bigger--;
            ok.insert(1);
        }
    }
    if (bigger == k - 1 && ok.count(1)) {
        ans = max(ans,x);
    }
    if (res >= k) {
        check = 1;
    }
    //cout << res << '\n';
    //for (auto i : cnt) cout << i << ' ';
    for (int i = m + 1;i <= n;i++) {
        res -= cnt[0];
        cnt.pop_front();
        if (x - a[i] - c <= 0) {
            bigger++;
            res++;
            cnt[((i - 1) % m) + 1 - 1]++;
            continue;
        }
        int need = (x - a[i] - c) / d;
        if ((x - a[i] - c) % d)need++;
        if (need * d + c + a[i] == x) {
            ok.insert((m - need) + i);
        }
        if (m >= need) {
            res++;
            cnt.push_back(0);
            cnt[min(m - need,m - 1)]++;
        }
        if (res == k - 1 && ok.count(i)) {
            ans = max(ans,x);
            return 1;
        }
        if (res >= k) {
            check = 1;
        }
        //cout << res << '\n';
    }
    if (check) return 1;
    else return 0;
}

void solve() {
    cin >> n >> k >> m >> c >> d;
    for (int i = 1;i <= n;i++) cin >> a[i];
    int l = 0,r = 1e18;
    ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << mid << '\n';
        if (check(mid)) {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    //check(5);
    cout << ans << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}