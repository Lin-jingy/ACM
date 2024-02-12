#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#define int long long
using namespace std;
int fact(int x, string a) {//x进制转10进制，a为x进制的值
    int answer = 0;
    string raa(a.rbegin(), a.rend());
    int aaa = raa.length();
    for (int i = 0; i < aaa; ++i) {
        answer += (raa[i] - '0') * pow(x, i);
    }
    return answer;
}
int answer;
signed main() {
    string a, b;
    cin >> a >> b;
    string ra(a.rbegin(), a.rend());
    string rb(b.rbegin(), b.rend());
    int lenra = ra.length();
    int lenrb = rb.length();
    if (a[0] == '0') {
        a[0] = '1';
        answer = fact(2,a);
        cout << answer;
        return 0;
    }else {
        int ia = fact(2, a);
        int ib = fact(3, b);
        for (int i = 0; i < lenra; ++i) {
            for (int j = 0; j < lenrb; ++j) {
                if (ra[i] == '0') {
                    int kk = ia + pow(2, i);
                    int bb = pow(3, j);
                    if (rb[j] + 1 < '3' && kk == ib + bb) { cout << kk; return 0; }
                    else if (rb[j] + 2 < '3' && kk == ib + 2 * bb) { cout << kk; return 0; }
                    else if (rb[j] - 1 >= '0' && kk == ib - bb) { cout << kk; return 0; }
                    else if (rb[j] - 2 >= '0' && kk == ib - 2 * bb) { cout << kk; return 0; }
                }
                else if (ra[i] == '1') {
                    int kk = ia - pow(2, i);
                    int bb = pow(3, j);
                    if (rb[j] + 1 < '3' && kk == ib + bb) { cout << kk; return 0; }
                    else if (rb[j] + 2 < '3' && kk == ib + 2 * bb) { cout << kk; return 0; }
                    else if (rb[j] - 1 >= '0' && kk == ib - bb) { cout << kk; return 0; }
                    else if (rb[j] - 2 >= '0' && kk == ib - 2 * bb) { cout << kk; return 0; }
                }
            }
        }
    }
    return 0;
}