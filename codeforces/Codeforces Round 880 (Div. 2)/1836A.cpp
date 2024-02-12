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
const int N = 105;

void solve(){
    int n;
    cin >> n;
    int a[N];
    multiset<int>s;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i){
        if(a[i] == 0) s.insert(0);
        else{
            if(s.count(a[i] - 1)){
                s.erase(s.find(a[i] - 1));
                s.insert(a[i]);
            }else{
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
    cin >> _;
    while(_--)solve();
    return 0;
}
