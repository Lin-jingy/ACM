#include<bits/stdc++.h>
using namespace std;
#define quick std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
#define int long long
int ansl;
int n, m;
string kkk;
string ans = "?????????????????";
int fa[17];
int quickpow(int a, int b) {
	int sum = 1;
	while (b) {
		if (b & 1)sum = sum * a;
		a = a * a;
		b >>= 1;
	}
	return sum;
}
auto _10to2(int t) {//10ת2
	vector<int>v;
	while (t / 2) {
		v.emplace_back(t % 2);
		t /= 2;
	}
	v.emplace_back(t);
	while ((int)v.size() < 17)v.emplace_back(0);
	reverse(v.begin(), v.end());
	return v;
}
bool _2to10(string x) {//2ת10
	int sum = 0;
	for (int i = 0; i < 17; ++i) {
		if (ans[i] == '?' and fa[i] % 2 == 0)x[i] = 1 - x[i];
	}
	for (int i = 0; i < 17; ++i) {
		if (x[i] == '1')sum += quickpow(2, 16 - i);
	}
	if (sum >= m)return false;
	return true;
}
void solve() {
	cin >> n >> m;
	string op;
	int t;
	while (n--) {
		vector<int>v;
		cin >> op >> t;
		while (t / 2) {
			v.emplace_back(t % 2);
			t /= 2;
		}
		v.emplace_back(t);
		while ((int)v.size() < 17)v.emplace_back(0);
		reverse(v.begin(), v.end());

		if (op == "AND") {
			for (int i = 0; i < 17; ++i) {
				if (v[i] == 0)ans[i] = '0';
			}
		}
		else if (op == "XOR") {
			for (int i = 0; i < 17; ++i) {
				if (ans[i] != '?')ans[i] = (ans[i] - '0') ^ v[i] + '0';
				else ++fa[i];
			}
		}
		else if (op == "OR") {
			for (int i = 0; i < 17; ++i) {
				if (v[i] == 1)ans[i] = '1';
			}
		}
	}
	int kt = 0;
	string mid = ans;
	for (int i = 0; i < 17; ++i)if (mid[i] != '?')mid[i] = '0';
	string mid1 = ans;
	for (int i = 0; i < 17; ++i)if (ans[i] == '?')++kt;
	int zhong = quickpow(2, kt);
	for (int i = zhong - 1; i >= 0; --i) {
		vector<int>x = _10to2(i);
		reverse(x.begin(), x.end());
		x.emplace_back(0);
		int flag = 0;
		for (int i = 16; i >= 0; --i) {
			if (mid[i] == '?')mid[i] = x[flag++] + '0';
		}
		if (_2to10(mid))goto A;
		if (i != 0)mid = mid1;

	}
A:;
	int k = 0;
	for (int i = 0; i < 17; ++i) {
		if (ans[i] == '?')ans[i] = mid[i];
		if (ans[i] == '1')k += quickpow(2, 16 - i);
	}
	cout << k;
}
signed main() {
	quick;
	int t = 1;
	while (t--)solve();
	return 0;
}