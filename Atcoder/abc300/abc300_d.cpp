#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define int long long 
using PII = pair<int, int>;

int n;
const int N = 1e6;
int st[N];
vector<int>v;

void init() {
    for (int i = 2; i < N; ++i) {
        if (st[i])continue;
        v.push_back(i);
        for (int j = 2; i * j < N; j ++)st[i * j] = 1;
    }
}

void solve() {
    cin >> n;
    init();
    int ans = 0;
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        if (v[i] * v[i] * v[i + 1] * v[i + 2] * v[i + 2] > n)break;
        for (int j = i + 1; j < len; ++j) {
            if (v[i] * v[i] * v[j] * v[j + 1] * v[j + 1] > n)break;
            for (int k = j + 1; k < len; ++k) {
                int s = v[i] * v[i] * v[j] * v[k] * v[k];
                if (s > n)break;
                else ++ans;
            }
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    while (t--)solve();
    return 0;
}
