//高精乘
#include<iostream>
#include<string>
using namespace std;
#define int long long
string High_precision_multiplication(string a, string b) {
    string ra(a.rbegin(), a.rend());//对a，b进行逆向操作，方便计算
    string rb(b.rbegin(), b.rend());
    if (a == "0" || b == "0")return "0";
    int maxlen, minlen;
    string rmax, rmin;
    if (a.size() > b.size()) {
        maxlen = a.size();
        minlen = b.size();
        rmax = ra;
        rmin = rb;
    }
    else {
        maxlen = b.size();
        minlen = a.size();
        rmax = rb;
        rmin = ra;
    }
    // cout<<rmin<<' '<<rmax;
    int answer[10000] = {};//注意此处的长度大小要大于要求的长度
    for (int i = 0; i < minlen; ++i) {
        for (int j = 0; j < maxlen; ++j) {
            answer[i + j] += ((int)rmin[i] - '0') * ((int)rmax[j] - '0');
        }
    }
    //  for(int i=0;i<5;++i)cout<<answer[i]<<' ';
    int flag = 0;
    for (int i = 0; i < minlen + maxlen - 1; ++i) {
        flag = i;
        while (answer[i] > 9) {
            answer[i] -= 10;
            answer[i + 1]++;
            flag = i + 1;
        }
    }
    string str;
    str.resize(flag+1);
    for (int i = 0; i <= flag; ++i) {
        str[i] = (char)(answer[i]) + '0';
    }
    string ranswer(str.rbegin(), str.rend());
    return ranswer;
}
signed main() {
    string a, b;
    cin >> a >> b;
    cout << High_precision_multiplication(a, b);
    return 0;
}