#include<iostream>
using namespace std;
#define int long long
int a[105];
int fact(int a[], int n) {
    if (a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == -1 && a[5] == -1) {
        /*cout << "ooo--***";
        for (int q = 1; q <= 2 * n + 2 - 8; q += 2) {
            cout << "o*";
        }
        cout << '\n';*/
        cout << "ooo*o**--*";
        for (int q = 1; q <= 2 * n + 2 - 10; q += 2) {
            cout << "o*";
        }
        cout << '\n';
        cout << "o--*o**oo*";
        for (int q = 1; q <= 2 * n + 2 - 10; q += 2) {
            cout << "o*";
        }
        cout << '\n';
        cout << "o*o*o*--o*";
        for (int q = 1; q <= 2 * n + 2 - 10; q += 2) {
            cout << "o*";
        }
        cout << '\n';
        cout << "--";
        for (int q = 1; q <= n; ++q) {
            cout << "o*";
        }
        return 0;
    }
    else {
        for (int i = 1; i <= 2 * n + 1; ++i) {
            if (a[i] == 0 && a[i + 1] == 1) {
                int k = 0;
                for (int j = i+1; j < 2 * n + 2; ++j)
                    if (a[j] == -1) { k = j; break; }
                a[k] = 0; a[k + 1] = 1;
                a[i] = -1; a[i + 1] = -1;
                for (int q = 1; q <= 2 * n + 2; ++q) {//输出
                    if (a[q] == 1)cout << '*';
                    else if (a[q] == 0)cout << 'o';
                    else cout << '-';
                }
                cout << '\n';
                goto A;
            }
            else if (a[i] == -1 && a[i + 1] == -1) {
                for (int j = i + 1; j < 2 * n + 1; ++j) {
                    if (a[j + 1] == 0) {
                        a[j - 1] = -1; a[j] = -1;
                        a[i] = 1; a[i + 1] = 1;
                        for (int q = 1; q <= 2 * n + 2; ++q) {//输出
                            if (a[q] == 1)cout << '*';
                            else if (a[q] == 0)cout << 'o';
                            else cout << '-';
                        }
                        cout << '\n';
                        goto A;
                    }
                }
            }
        }
    }
A:
    fact(a, n);
    return 0;
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i] = 0;
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        a[i] = 1;
    }
    a[2 * n + 1] = -1; a[2 * n + 2] = -1;
    for (int q = 1; q <= 2 * n + 2; ++q) {//输出
        if (a[q] == 1)cout << '*';
        else if (a[q] == 0)cout << 'o';
        else cout << '-';
    }
    cout<<'\n';
    fact(a, n);
    return 0;
}