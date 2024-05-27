#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<bitset>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

#define nd second
#define st first
#define mp make_pair
#define pb push_back
#define orta (((bas)+(son))/2)
#define sol (k+k)
#define sag (k+k+1)

const int N = 1e6 + 5;
const int inf = 1e9 + 5;
const int mod = 998244353;
const int logN = 17;

void solve() {
    vector<int> arr(N);
    int a, r, m, n, s, k;
    vector<ll> pre(N);
	scanf("%d %d %d %d", &n, &a, &r, &m);
	m = min(a + r, m);
	vector< int > vec;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		vec.pb(arr[i]);
	}
	sort(arr.begin() + 1, arr.begin() + n + 1);
	for(int i = 1; i <= n; i++)
		pre[i] += pre[i - 1] + arr[i];

	int bas = 0, son = 1000000000;
	while(bas < son) {
		int ort = (bas + son + 1) / 2;
		int p = lower_bound(arr.begin() + 1, arr.begin() + n + 1, ort) - arr.begin() - 1;
		ll suml = ort * (ll) p - pre[p];
		ll sumr = (pre[n] - pre[p]) - ort * (ll) (n - p);
		if(suml < sumr) bas = ort;
		else son = ort - 1;
	}
	vec.pb(bas);
	vec.pb(bas-1);
	vec.pb(bas+1);

	ll ans = inf * (ll) inf;

	while(vec.size()) {
		int p = lower_bound(arr.begin() + 1, arr.begin() + n + 1, vec.back()) - arr.begin() - 1;
		ll suml = vec.back() * (ll) p - pre[p];
		ll sumr = (pre[n] - pre[p]) - vec.back() * (ll) (n - p);
		ans = min(ans, suml * (ll) a + sumr * (ll) r - (a + r - m) * min(suml, sumr));
		vec.pop_back();
	}

	cout << ans << endl;
}
int main() {
    
    for(int i = 1; i <= 22; ++i) {
        string s = format("C:/Users/123/Desktop/programming/VScode/ACM/data/4/data/{}.in", i);
        string s1 = format("C:/Users/123/Desktop/programming/VScode/ACM/data/4/data/{}.out", i);
        freopen(s.data(), "r", stdin);
        freopen(s1.data(), "w", stdout);
        solve();
        fclose(stdin);
        fclose(stdout);
        std::clog << i << std::endl;
    }

	return 0;
}
