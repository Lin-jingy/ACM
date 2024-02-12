#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int a, b; cin >> a >> b;
	//先求最大公约数
	//再用最大公约数乘a,b中的较小数即可
	cout << min(a, b) * (max(a, b) / __gcd(a, b));
	return 0;
}