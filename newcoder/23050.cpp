//TLE
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//signed main() {
//	int a, b, n;
//	cin >> a >> b >> n;
//	int k = 0;
//	for (int i = 0; i < n-2; ++i) {
//		k = a + b;
//		b = a;
//		a = k;
//	}
//	cout << __gcd(k, a + b);
//	return 0;
//}
#include<bits/stdc++.h>
#define int long long
signed main() {
	int a, b; std::cin >> a >> b;
	std::cout << std::__gcd(a, b);
	return 0;
}