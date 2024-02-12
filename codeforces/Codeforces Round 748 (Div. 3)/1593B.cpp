#include<bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string a;cin>>a;
    int sum=INT_MAX,ans=0;
    for(int i=a.size()-1;i>=0;--i){
        ans=a.size()-1-i;
        if(a[i]=='0'){
            for(int j=i-1;j>=0;--j){
                if(a[j]=='5'){
                    sum=min(sum,ans);
                    break;
                }
                else if(a[j]=='0'){
                    sum=min(sum,ans);
                    break;
                }else ++ans;
            }
        }else if(a[i]=='5'){
            for(int j=i-1;j>=0;--j){
                if(a[j]=='2' or a[j]=='7'){
                    sum=min(sum,ans);
                    break;
                }
                else ++ans;
            }
        }
    }
    A:;
    cout<<sum<<'\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
}