#include<bits/stdc++.h>

using namespace std;
#define int long long 
//#define double long double
const int N = 5e4 + 5;
int n, m, k;
const double EPS = 0.000000000001;

class node{
public:
    int sugar, walter;
};

node x[N], y[N];

bool check(double c){
    vector<double>a, b;
    for(int i = 0; i < n; ++i) a.emplace_back((1.0 - c) * x[i].sugar - c * x[i].walter);
    for(int i = 0; i < m; ++i) b.emplace_back((c - 1.0) * y[i].sugar + c * y[i].walter);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int kk = 0, sum = 0;
    for(int i = 0; i < n; ++i){
        while(kk < m and b[kk] < a[i]) ++kk;
        sum += kk;
    }
    return sum <= k;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> x[i].sugar >> x[i].walter;
    for(int i = 0; i < m; ++i) cin >> y[i].sugar >> y[i].walter;
    double ans = 0;
    --k;
    double l = 0, r = 1;
    int t = 100;
    while(t--){
        double mid = (l + r) / 2.0;
        if(check( mid )) r = mid, ans = mid;
        else l = mid; 
    }
    printf("%.10lf",ans * 100);
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}