#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick ios::sync_with_stdio(false),cin.tie(nullptr);
string a;
string s;
void solve(){
    cin>>a;
    //预处理原字符串



    int n;cin>>n;
    for(int i=0;i<n;++i){
        cin>>s;
        int len=s.size();
        int next[len+5];
        for (int k = 2, j = 0; k <= len; k ++ ){
            while (j && s[k] != s[j + 1]) j = next[j];
            if (s[k] == s[j + 1]) j ++ ;
            next[k] = j;
        }
    }

    return;
}

signed main(){
    quick;
    int t=1;
    while(t--)solve();
    return 0;
}