#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 1e5 + 5;
int p[N];

void solve(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    cout << count(a.begin(), a.end(), 'L') + count(a.begin(), a.end(), 'R') + 1 << '\n';

}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
