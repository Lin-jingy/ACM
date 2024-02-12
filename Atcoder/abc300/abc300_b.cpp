#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
char a[31][31], b[31][31];
int n, m;

bool check(int x, int y){
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            if(a[(i + n - x) % n][(j + m - y) % m] != b[i][j])return false;
        }
    }
    return true;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++ i)for(int j = 0; j < m; ++ j)cin >> a[i][j];
    for(int i = 0; i < n; ++ i)for(int j = 0; j < m; ++ j)cin >> b[i][j];
    for(int i = 0; i < n; ++ i)for(int j = 0; j < m; ++ j)if(check(i, j)){
        cout << "Yes";
        return;
    }
    cout << "No";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
