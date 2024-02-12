#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 1e7 + 10, M = 2 * N;
int n, m, a[N];
int p[N], pe[N], primes[N], cnt;

void init() {
    for (int i = 2; i < N; i++ ) {
        if(!p[i]) p[i] = i, pe[i] = i, primes[++ cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] < N; j++ ){
            p[i * primes[j]] = primes[j];
            if(p[i] == primes[j]) {
                pe[i * primes[j]] = pe[i] * primes[j];
                break;
            } else pe[i * primes[j]] = primes[j];
        }
    }   
}
void solve(){
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    int t = b - a;
    vector<int> v;
    while(t > 1) {
        v.push_back(p[t]);
        int pp = p[t];
        while(t % pp == 0) t /= pp;
    }
    int ans = INF;
    for (auto it : v) {
        int t = a % it;
        if(t == 0) t = it;
        ans = min(ans, it - t);
    }
    if(ans == INF) ans = -1;
    cout << ans << '\n';
    
}
signed main() {
    ios::sync_with_stdio(0),cin.tie(0);
    // freopen("input.txt", "r", stdin);
    init();
    int T = 1;
    cin >> T;
    while(T -- ) solve();
    return 0;
}              