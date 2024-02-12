#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,g;
    cin >> n >> g;
    int a[n+5],k[n+5];
    int x;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        a[i] = x % g ? 1 : 0;
    }
    int ans = 0;
    int flag = 1;
    for(int i = 1; i <= n; ++i) k[i] = a[i-1] + a[i];
    for(int i = 1; i <= n; ) {
        if(k[i]-k[flag]<=1) ++ans, ++i;
        else ++flag;
    }
    cout<<ans;
    return 0;
}