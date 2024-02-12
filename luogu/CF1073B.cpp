#include<iostream>
#include<stack>
#define int long long
using namespace std;
int a[200005];
int flag[200005] = {  };
stack<int>k;
signed main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> a[i];
    for (int i = n - 1; i >= 0; --i)k.push(a[i]);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (k.empty()) { cout << "0 "; continue; }
        int sum = 0;
        while (!k.empty()) {
            if (flag[x]) { cout << "0 "; goto A; }
            else if (k.top() == x) {
                sum++;
                flag[k.top()] = 1;
                k.pop();
                break;
            }
            else if (k.top() != x) {
                flag[k.top()] = 1;
                k.pop();
                sum++;
            }
        }
      
        cout << sum << ' ';  A:;
    }
    return 0;
}