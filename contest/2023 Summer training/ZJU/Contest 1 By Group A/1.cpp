#include<bits/stdc++.h>

using namespace std;
#define int long long 
using PII = pair<int, int>;
const int mod = 1e9 + 7;
int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1) sum = sum * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return sum;
}

const int N = 1e5 + 5;


void solve(){

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int _;
    cin >> _;
    while(_--)solve();
    return 0;
}