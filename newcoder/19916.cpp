// TLE
//  #include<bits/stdc++.h>
//  using namespace std;
//  #define int long long
//  #define endl '\n'
//  priority_queue<int,vector<int>,greater<int>>q;
//  signed main(){
//      int n,m;cin>>n>>m;
//      int x=0;
//      for(int i=0;i<n;++i){
//          cin>>x;
//          q.push(x);
//      }
//      while(m){
//          int k=q.top();
//          q.pop();
//          x=q.top()-k;
//          if(x==0){
//              m-=1;
//              q.push(k+1);
//          }else if(x<=m){
//              m-=x;
//              q.push(k+x);
//          }else{
//              break;
//          }
//      }
//      cout<<q.top();
//      return 0;
//  }

#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100], n, m;
bool check(int x) {
    int km = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < x) km += x - a[i];
    }
    return km <= m && km <= x;
}
signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = INT_MAX, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}