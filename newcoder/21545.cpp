#include<bits/stdc++.h>
using namespace std;
int n, a[51], x;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	cin >> x;
	sort(a + 1, a + n + 1);
	int m = a[n] - a[1];
	for(int i = 1; i < n; i++)
	m = min(m, (max(a[n] - x, a[i] + x) - min(a[1] + x, a[i + 1] - x)));
	cout << m;
	return 0;
}