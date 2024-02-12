#include<bits/stdc++.h>

using namespace std;
#define int long long 

void solve(){
    int n;
    cin >> n;
    int l = 1, r = n - 1;
    int x, ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        cout << "? " << mid << endl;
        cin >> x;
        if(x == 1)r = mid - 1;
        else ans = mid, l = mid + 1;
    }
    cout << "! " << ans << endl;
}

signed main(){
    solve();
    return 0;
}