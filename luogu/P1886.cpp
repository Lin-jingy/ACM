#include <iostream>
#include <algorithm>
#include<queue>

using namespace std;
const int maxn = 1000010;
int n, k, a[maxn], id[maxn], l, r, b[maxn];

int main(void) {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        while (r >= l && a[i] < b[r]) r--;
        b[++r] = a[i];
        id[r] = i;
        if (i - id[l] + 1 > k) l++;
        if (i >= k) cout << b[l] << " ";
    }
    cout << '\n';
    l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        while (r >= l && a[i] > b[r]) r--;
        b[++r] = a[i];
        id[r] = i;
        if (i - id[l] + 1 > k) l++;
        if (i >= k) cout << b[l] << " ";
    }
    return 0;
}