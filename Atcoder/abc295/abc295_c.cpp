#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
string a, mid;

void solve() {
    cin >> a;
    while (getline(cin, mid)) {
        a += mid;
        a += ' ';
        cout << a << endl;
    }
    cout << a;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    while (t--)solve();
}

