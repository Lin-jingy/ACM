//#pragma GCC optimize(3)
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

int n, k;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for(int i = 0; i < n; ++i) cin >> a[i], a[i] %= k;
	int ans = a[0];
	priority_queue<int, vector<int>, greater<int>>q;
 	for(int i = 1; i < n; ++i){
		if(a[i] >= a[i - 1]){
			q.push(a[i] - a[i - 1]);
			ans += q.top();
			q.pop();
		}else{
			q.push(k + a[i] - a[i - 1]);
		}
	}
	cout << ans << '\n';

}

// void solve(){
//     cin >> n >> k;
//     vector<int>a(n), p(n);
//     for(int i = 0; i < n; ++i) cin >> a[i], p[i] = (a[i] + k) % k;
//     int l = 0, r = 1e9;
//     int ans = 0;

// 	auto check = [&](int x){
// 		int i;
// 		vector<int>ps(p);
//     	for(i = 1; i < n; ++i){
// 			if(ps[i] > x)break;
//         	if(ps[i] >= ps[i - 1])continue;
//         	else ps[i] += k;
//         	if(ps[i] > x){
// 				ps[i] -= k;
// 				break;
// 			}
//     	}
//     	for( ; i < n; i++){
//         	if(ps[i] < 0)return false;
//         	if(ps[i] <= ps[i - 1])continue;
//         	else ps[i] -= k;
//         	if(ps[i] <= 0)return false;
//     	}
//     	return true;
// 	};

//     while(l <= r){
//         int mid = l + r >> 1;
//         if(check(mid)) r = mid - 1, ans = mid;
//         else l = mid + 1;
//     }
//     cout << ans << '\n';
// }

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
