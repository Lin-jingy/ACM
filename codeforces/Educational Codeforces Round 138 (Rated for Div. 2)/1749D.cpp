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

const int N = 3e5 + 5;
int p[N];
const int mod = 998244353;
vector<int>v;

const void prime(int &n){
    for(int i = 2; i <= n; ++i){
        if(p[i])continue;
        v.emplace_back(i);
        for(int j = i + i; j <= n; j += i)p[j] = 1;
    }
}

const int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1)sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

void solve(){
    int n, m;
    cin >> n >> m;
    prime(n);
    int ans = 0;
    int last = 1, sum = 1, k = 1;
    for(int i = 1; i <= n; ++i){
        if (!p[i]) last *= i;
        k = k * ((m / last) % mod) % mod;
        sum = sum * (m % mod) % mod;
        ans = (ans + sum - k) % mod;
    }
    cout << (ans + mod) % mod << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
