#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) { cout << "1 0 0 0\n"; continue; }
        else if (n == 2) { cout << "1 0 0 1\n"; continue; }
        else if (n == 3) { cout << "1 0 1 1\n"; continue; }
        else if (n == 4) { cout << "1 0 1 2\n"; continue; }
        else if (n == 5) { cout << "1 0 2 2\n"; continue; }
        else if (n == 6) { cout << "1 0 2 3\n"; continue; }
        else if (n == 7) { cout << "2 0 2 3\n"; continue; }
        int a = 1, b = 0, c = 0, d = 0;
        int flag = 1, k = 2;
        int i = 1;
        int dig = 0;
        int ff = 0;
        while (1) {
            if (flag) {
                c += k / 2, d += k / 2;
                if (ff)c += k % 2;
                else d += k % 2;
            }
            else {
                a += k / 2, b += k / 2;
                if (ff)a += k % 2;
                else b += k % 2;
            }
            if (k % 2 == 1)ff = 1 - ff;
            i += k, ++dig;
            if (dig == 2)dig = 0, flag = 1 - flag;
            if (i + k < n)k++;
            else break;
        }
        if (flag == 0) {
            a += (n - i) / 2, b += (n - i) / 2;
            if (ff)a += (n - i) % 2;
            else b += (n - i) % 2;
        }
        else {
            c += (n - i) / 2, d += (n - i) / 2;
            if (ff)c += (n - i) % 2;
            else d += (n - i) % 2;
        }
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
    return 0;
}