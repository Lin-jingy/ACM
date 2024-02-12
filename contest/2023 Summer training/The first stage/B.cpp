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

string str = "abacaba";
int n;
string a;

int check(){
    int sum = 0;
    for(int i = 0; i < n - 6; ++i){
        string s;
        for(int j = 0; j < 7; ++j) s += a[i + j];
        if(s == str) ++sum;
    }
    return sum;
}

void solve(){
    cin >> n;
    cin >> a;
    int sum = check();
    if(sum >= 2){
        no;
        return;
    }
    if(sum == 1){
        for(auto &i:a)if(i == '?') i = 'd';
        yes;
        cout << a << '\n';
        return;
    }
    for(int i = 0; i < n - 6; ++i){
        string s;
        for(int j = 0; j < 7; ++j) s += a[i + j];
        for(int j = 0; j < 7; ++j){
            if(a[i + j] == '?') a[i + j] = str[j];
            if(a[i + j] != str[j]) goto A;
        }
        if(check() == 1){
            yes;
            for(auto &j:a) if(j == '?') j = 'd';
            cout << a << '\n';
            return;
        }
        A:;
        for(int j = 0; j < 7; ++j) a[i + j] = s[j];
    }
    no;
    return;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
