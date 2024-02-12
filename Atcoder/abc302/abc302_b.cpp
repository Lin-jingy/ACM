#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

char a[105][105];
string name = "snuke";
int n, m;
void check(int x, int y, int dx, int dy){
    for(int i = 0; i <5 ; i++)if(a[x + dx * i][y + dy * i] != name[i]) return ;
    for(int i = 0; i < 5; i++) printf("%d %d\n",x + dx * i, y + dy * i);
    exit(0);
}
signed main(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++) scanf("%s",a[i] + 1);
    for(int i = 1; i <= n; i++) for(int j = 1; j + 4 <= m; j++){
        check(i,j,0,1);
        check(i,j+4,0,-1);
    }
    for(int i = 1; i + 4 <= n; i++) for(int j = 1; j <= m; j++){
        check(i,j,1,0);
        check(i+4,j,-1,0);
    }
    for(int i = 1; i + 4 <= n; i++) for(int j = 1;j + 4 <= m; j++){
        check(i,j,1,1);
        check(i+4,j+4,-1,-1);
        check(i+4,j,-1,1);
        check(i,j+4,1,-1);
    }
    return 0;
}