#include<bits/stdc++.h>

#define int long long 
using namespace std;
const int N = 505;
bool p[N][N];
int n;
string a;
vector<char>ans;
int flag = 0;

void dfs(int lx, int ly, int x, int y){
    if(flag == 1)return;
    cout << '?' << ' ' << lx << ' ' << ly << ' ' << x << ' ' << y << endl;
    cin >> a;
    if(a == "YES"){
        p[lx][ly] = 1, p[x][y] = 1;
        if(lx + ly == n + 1 or x + y == n + 1){
            flag = 1;
            return;
        }
        if(x == n and y == n){
            if(ly + 1 <= n)dfs(lx, ly + 1, x, y);
            if(lx + 1 <= n)dfs(lx + 1, ly, x, y);
        }else if(lx == 1 and ly == 1){
            if(x - 1 >= 1)dfs(lx, ly, x - 1, y);
            if(y - 1 >= 1)dfs(lx, ly, x, y - 1);
        }
    }
    return;
}

void rdfs(int x, int y){
    if(x == n and y == n){
        for(auto i : ans)cout << i;
        return;
    }
    if(p[x + 1][y]){
        ans.push_back('D');
        rdfs(x + 1, y);
        ans.pop_back();
    }
    if(p[x][y + 1]){
        ans.push_back('R');
        rdfs(x, y + 1);
        ans.pop_back();
    }
}

void solve(){
    cin >> n;
    dfs(1, 2, n, n);
    if(flag == 0)dfs(2, 1, n, n);
    flag = 0;
    dfs(1, 1, n - 1, n);
    if(flag == 0)dfs(1, 1, n, n - 1);
    flag = 0;
    flag = 0;
    cout << "! ";
    rdfs(1, 1); 
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    solve();
    return 0;
}
