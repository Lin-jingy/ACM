#include<iostream>
using namespace std;
#define int long long
signed main() {
	int t; cin >> t;
	while (t--) {
		int w, d, h; cin >> w >> d >> h;
		int a, b, f, g; cin >> a >> b >> f >> g;
		int ans = 0;
		ans = min(b+h+g+abs(f-a),a+f+h+abs(b-g) );
		int x = min((w-a)+(w-f)+h+abs(b-g),(d-b)+(d-g)+h+abs(a-f));
		ans = min(ans,x);
		cout << ans << '\n';
	}
	return 0;
}