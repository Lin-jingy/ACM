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

const int N = 1e6 + 5;
int a[N];
unordered_set<int>s;

void init(int x){
    s.clear();
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0)s.insert(i), s.insert(x / i);
    }
}

void solve(){
    int n;
    cin >> n;
    init(n);
    a[1] = 0;
    for(int i = 2; i <= n; ++i){
        int p[26];
        memset(p, 0, sizeof p);
        p[a[i - 1]]++;
        for(auto j:s){
            if(i - j >= 1) p[a[i - j]]++;
        }
        for(int j = 0; j < 26; ++j){
            if(p[j] == 0){
                a[i] = j;
                break;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << (char)(a[i] + 'a');
    }
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
