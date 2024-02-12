#include<bits/stdc++.h>
using namespace std;
#define int long long
int flag = 0;
struct stu {
    string name;
    int chinese;
    int math;
    int english;
    int sum;
}a[1005];
struct answer {
    string name1;
    string name2;
}b[1000009];
// bool fact(stu a, stu b) {
//     if (a.sum != b.sum)return a.sum > b.sum;
//     else return a.name<b.name;
// }
// bool ans(answer a, answer b) {
//     if (a.name1 != b.name1)return a.name1 < b.name1;
//     else return a.name2 < b.name2;
// }
signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].name >> a[i].chinese >> a[i].math >> a[i].english;
        a[i].sum = a[i].chinese + a[i].math + a[i].english;
    }
    // sort(a, a + n, fact);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (fabs(a[i].sum - a[j].sum )<= 10 && fabs(a[i].chinese - a[j].chinese) <= 5 && fabs(a[i].math - a[j].math) <= 5 && fabs(a[i].english - a[j].english) <= 5) {
                b[flag].name1 = a[i].name; b[flag].name2 = a[j].name;
                flag++;
            }
        }
    }
    // assert(flag<=1001);
    // return 0;
    // sort(b, b + flag, ans);
    for (int i = 0; i < flag; ++i) {
        if (b[i].name1 < b[i].name2)cout << b[i].name1 << ' ' << b[i].name2 << '\n';
        else cout << b[i].name2 << ' ' << b[i].name1 << '\n';
    }
    return 0;
}