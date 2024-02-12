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

int a[26][26];

void solve(){
    int n;
    cin >> n;
    memset(a, 0, sizeof a);
    string s;
    cin >> s;
    for(int i = 1; i < n; ++i){
        if(a[s[i - 1] - 'a'][s[i] - 'a']){
            if(a[s[i - 1] - 'a'][s[i] - 'a'] != i - 1){
                yes;
                return; 
            }
        }else a[s[i - 1] - 'a'][s[i] - 'a'] = i;
    }
    no;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
