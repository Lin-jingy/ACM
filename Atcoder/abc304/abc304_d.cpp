#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 2e5 + 5;
int w, h, n;
PII p[N];
int a[N], b[N], cnta, cntb;
map<PII, int> mp;

void solve(){
	cin >> w >> h >> n;
	for(int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
	cin >> cnta;
	for(int i = 1; i <= cnta; i++) cin >> a[i];
	cin >> cntb;
	for(int i = 1; i <= cntb; i++) cin >> b[i];
	a[++cnta] = w, b[++cntb] = h;
	
	sort(a + 1, a + 1 + cnta);
    sort(b + 1, b + 1 + cntb);
	
	for(int i = 1; i <= n; i++){
		int x = p[i].first, y = p[i].second;
		int xx = lower_bound(a + 1, a + 1 + cnta, x) - a;
		int yy = lower_bound(b + 1, b + 1 + cntb, y) - b;
		mp[{xx,yy}]++;
	}
	int min1 = INF,max1 = -INF, cnt = 0;
	for(auto i:mp){
		min1 = min(min1, i.second);
		max1 = max(max1, i.second);
		cnt++;
	}
	if(cnt < cnta * cntb) min1 = 0;
	cout << min1 << " " << max1 << "\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
