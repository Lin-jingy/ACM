#include<iostream>
using namespace std;
#define int long long
int a[50005], n, d;
bool check(int x) {
    int happy = 0;
    int k = 0;
    for (int i = 0; i < d; ++i) {
        while (happy < x) {
            if (k > n) {
                return false;
            }
            happy += a[k++];
        }
        happy /= 2;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    int sum = 0;
    for (int i = 0; i < n; ++i) { cin >> a[i]; sum += a[i]; }
    int left = 0, right = sum;
    int mid = 0, ans = 0;
    while (left <= right) {
        mid = left + right >> 1;
        if (check(mid)) { left = mid + 1; ans = mid; }
        else right = mid - 1;
    }
    cout << ans << '\n';
    int happy = 0;
    int k = 0;
    int flag = 0;
    for (int i = 1; i <= d; ++i) {
        while (happy < ans) {
            happy += a[k++];
            cout << i << '\n';
        }
        happy /= 2;
    }
    for (; k < n; ++k)cout << d << '\n';
    return 0;
}