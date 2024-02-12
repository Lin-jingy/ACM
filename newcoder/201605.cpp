#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long 
vector<int>a, b, c;
int n, last_move;
bool flag = 0;
void print() {//输出当前状态
    //输出第一行
    int k = 3 * (2 * n + 1) + 4;
    if (flag) {
        for (int i = 0; i < k; ++i)cout << "-";
        cout << '\n';
    }
    while (k--)cout << ".";
    cout << "\n";
    //输出第二行
    k = (2 * n + 1) / 2;
    int rk = 0;
    int j = 3;
    while (j--) {
        rk = k;
        cout << "."; while (rk--)cout << ".";
        cout << "|";
        rk = k;
        while (rk--)cout << ".";
    }
    cout << ".\n";
    //输出中间内容
    int ka = 0, kb = 0, kc = 0;//点的个数
    for (int i = 0; i < n; ++i) {
        ka = 0, kb = 0, kc = 0;
        if (a.size() >= n - i)ka = (a[n - i - 1] * 2 + 1);
        if (b.size() >= n - i)kb = (b[n - i - 1] * 2 + 1);
        if (c.size() >= n - i)kc = (c[n - i - 1] * 2 + 1);
        //输出第一部分
        cout << "."; for (int ia = k; ia > ka / 2; --ia)cout << ".";
        for (int ia = 0; ia < ka / 2; ++ia)cout << "*";
        if (ka == 0)cout << "|";
        else cout << "*";
        for (int ia = 0; ia < ka / 2; ++ia)cout << "*";
        for (int ia = k; ia > ka / 2; --ia)cout << ".";
        //输出第二三部分
        if (n % 2 == 0) {
            cout << "."; for (int ia = k; ia > kb / 2; --ia)cout << ".";
            for (int ia = 0; ia < kb / 2; ++ia)cout << "*";
            if (kb == 0)cout << "|";
            else cout << "*";
            for (int ia = 0; ia < kb / 2; ++ia)cout << "*";
            for (int ia = k; ia > kb / 2; --ia)cout << ".";

            cout << "."; for (int ia = k; ia > kc / 2; --ia)cout << ".";
            for (int ia = 0; ia < kc / 2; ++ia)cout << "*";
            if (kc == 0)cout << "|";
            else cout << "*";
            for (int ia = 0; ia < kc / 2; ++ia)cout << "*";
            for (int ia = k; ia > kc / 2; --ia)cout << ".";
        }
        else {
            cout << "."; for (int ia = k; ia > kc / 2; --ia)cout << ".";
            for (int ia = 0; ia < kc / 2; ++ia)cout << "*";
            if (kc == 0)cout << "|";
            else cout << "*";
            for (int ia = 0; ia < kc / 2; ++ia)cout << "*";
            for (int ia = k; ia > kc / 2; --ia)cout << ".";

            cout << "."; for (int ia = k; ia > kb / 2; --ia)cout << ".";
            for (int ia = 0; ia < kb / 2; ++ia)cout << "*";
            if (kb == 0)cout << "|";
            else cout << "*";
            for (int ia = 0; ia < kb / 2; ++ia)cout << "*";
            for (int ia = k; ia > kb / 2; --ia)cout << ".";
        }
        cout << ".\n";
    }
    flag = 1;
}
int check1() {
    if (!a.empty() and a.back() == 1) { a.pop_back(); return 1; }
    else if (!b.empty() and b.back() == 1) { b.pop_back(); return 2; }
    else if (!c.empty() and c.back() == 1) { c.pop_back(); return 3; }
    return 0;
}
signed main() {
    cin >> n;
    for (int i = n; i >= 1; --i)a.push_back(i);
    print();
    int left = 1 + n % 2;
    int counts = 1;
    while (b.size() < n and c.size() < n) {
        if (counts % 2 == 1) {
            int pos = (check1() + left - 1) % 3 + 1;
            switch (pos) {
            case 1:a.push_back(1); break;
            case 2:b.push_back(1); break;
            case 3:c.push_back(1); break;
            }
            print();
        }
        else {
            int ta = n + 1, tb = n + 1, tc = n + 1;
            if (!a.empty())ta = a.back();
            if (!b.empty())tb = b.back();
            if (!c.empty())tc = c.back();
            if (ta < tb and ta!=1)a.pop_back(), b.push_back(ta);
            else if (ta < tc and ta!=1)a.pop_back(), c.push_back(ta);
            else if (tb < tc and tb!=1)b.pop_back(), c.push_back(tb);
            else if (tb < ta and tb != 1)b.pop_back(), a.push_back(tb);
            else if (tc < ta and tc != 1)c.pop_back(), a.push_back(tc);
            else if (tc < tb and tc != 1)c.pop_back(), b.push_back(tc);
            print();
        }
        ++counts;
    }
    return 0;
}