#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

bool cmp(char a, char b) {
    int k1 = 0, k2 = 0;
    if (a >= 'A' and a <= 'Z')k1 = (a - 'A') * 2;
    else k1 = (a - 'a') * 2 + 1;
    if (b >= 'A' and b <= 'Z')k2 = (b - 'A') * 2;
    else k2 = (b - 'a') * 2 + 1;
    return k1 < k2;
}



void solve() {
    string a;
    cin >> a;
    sort(a.begin(), a.end(), cmp);
    do {
        cout << a << '\n';
    } while (next_permutation(a.begin(), a.end(),cmp));
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
}

