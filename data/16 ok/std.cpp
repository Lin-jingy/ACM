#include <algorithm>
#include <math.h>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair


typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int N = 2e5 + 10;

int n; 
ll a[N], sum1[N], sum2[N], A[N], B[N];

bool bad(int l1, int l2, int l3) {
    return (B[l1] - B[l2]) * (A[l3] - A[l1]) >= (B[l1] - B[l3]) * (A[l2] - A[l1]);
}

vector<int> chull;
void add(int l) {
    int sz = chull.size();
    while (sz >= 2 && bad(chull[sz-2], chull[sz-1], l)) {
        chull.pop_back();
        sz--;
    }
    chull.push_back(l);
}

ll eval(int l, ll x) { return A[l]*x + B[l]; }

ll query(ll x) {
    int lo = -1, hi = chull.size()-1;
    while (lo+1 < hi) {
        int mi = (lo+hi)/2;
        if (eval(chull[mi],x) < eval(chull[mi+1],x)) lo = mi; else hi = mi;
    }
    return eval(chull[hi],x);
}

void solve(int dataID) {
    std::string address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/16/data/{}.in", dataID);
    std::string address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/16/data/{}.out", dataID);
    freopen(address1.c_str(), "r", stdin);
    freopen(address2.c_str(), "w", stdout);
    cin >> n; forn(i,n) cin >> a[i];
    sum1[0] = sum2[0] = 0;
    forn(i,n) {
        sum1[i+1] = sum1[i] + a[i];
        sum2[i+1] = sum2[i] + ll(i+1) * a[i];
    }

    ll ans = 0;
    forn(r,n+1) {
        A[r] = r;
        B[r] = (ll)r * sum1[r] - sum2[r];
        add(r);

        ll x = -sum1[r], c = sum2[r];
        ans = max(ans, query(x) + c);
        //forn(l,r+1) ans = max(ans, A[l]*x + B[l] + c);
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
}


int main() {
    ios_base::sync_with_stdio(false);
    

    for(int i = 1; i <= 31; ++i) {

        n = 0;
        memset(a, 0, sizeof(a));
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        chull.clear();


        solve(i);
        std::clog << i << std::endl;
    }

    return 0;
}
