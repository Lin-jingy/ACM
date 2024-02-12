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

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == b[i])continue;
        else{
            if(a[i] == '1' and b[i] == 'l' or a[i] == 'l' and b[i] == '1')continue;
            else if(a[i] == '0' and b[i] == 'o' or a[i] == 'o' and b[i] == '0')continue;
            else {
                no;
                return;
            }
        }
    }
    yes;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
