#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b, p;

int quickpow(int a, int b ,int p){
    int ans = 1;
    while(b){
        if(b & 1)ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}

signed main(){
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << quickpow(a, b, p);
}