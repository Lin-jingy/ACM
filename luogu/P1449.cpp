#include<iostream>
#include<stack>
#define int long long
using namespace std;
string a;
stack<int>k;
double answer;
signed main() {
    cin >> a;
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        if (a[i] == '@')break;
        else if (a[i] >= '0' && a[i] <= '9') {
            int dig = a[i]-'0';
            while (a[i+1]>='0'&&a[i+1]<='9') {
                dig = dig * 10 + a[i + 1]-'0';
                i++;
            }
            k.push(dig);
        }
        else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            int x, y;
            x = k.top();
            k.pop();
            if (!k.empty()) {
                y = k.top();
                k.pop();
                switch (a[i]) {
                case '+':answer = y + x; k.push(answer); break;
                case '-':answer = y - x; k.push(answer); break;
                case '*':answer = y * x; k.push(answer); break;
                case '/':answer = (double)y / x; k.push(answer); break;
                }
            }
            
        }

    }
    cout << k.top();
    return 0;
}