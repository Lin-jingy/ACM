#include <bits/stdc++.h>
using namespace std;
int n, ans;
struct node {
    int a, b;
} a[1000005];
priority_queue<int, vector<int>, greater<int>> q;
bool cmp(node a, node b) {
    if (a.a == b.a)
        return a.b < b.b;

    return a.a < b.a;
}
int main() {
    std::string test = "20";
    std::string address1 = std::format("C:/users/123/desktop/programming/vscode/ACM/data/P6346/data/{}.in", test);
    std::string address2 = std::format("C:/users/123/desktop/programming/vscode/ACM/data/P6346/data/{}.out", test);
    freopen(address1.data(), "r", stdin);
    freopen(address2.data(), "w", stdout);
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b;

    sort(a + 1, a + 1 + n, cmp);

    for (int i = n; i >= 1; i--) {
        q.push(a[i].b);

        if (a[i].a > n - q.size())
            ans += q.top(), q.pop();
    }

    cout << ans << std::endl;
    return 0;
}