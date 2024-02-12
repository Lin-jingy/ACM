#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define int long long
string High_precision_division(string aa, int b) {
    char a1[10001];
    int b, c[10001]={}, d, a[10001]={}, len, lenc;
    for (int i = 0; i < aa.length (); ++i) {
        a1[i] = aa[i];
    }
    len = strlen(a1);//把被除数的位数存在len里
    for (int i = 1; i <= len; i++)a[i] = aa[i - 1] - '0';//将被除数一位一位放入a数组
    for (int i = 1; i <= len; ++i)//这一个循环是关键，将被除数一位一位除以除数，不过除，向下
    {                                //一位借位，d为余数，c数组为商
        c[i] = (d * 10 + a[i]) / b;
        d = (d * 10 + a[i]) % b;
    }
    lenc = 1;
    while (c[lenc] == 0 && lenc < len)lenc++;//整理位数，删除前导0
    string answer;
    for (int i = lenc; i <= len; ++i)answer += to_string(c[i]);; //输出结果
    return answer;
}
signed main()
{
    string a;
    int b;
    cin >> a >> b;
    cout<< High_precision_division(a, b);
    return 0;
}