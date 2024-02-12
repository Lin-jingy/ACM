#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
#define int long long
int n, r;
void fact(int i, int t, string a);
signed main() {
    cin >> n >> r;
    if(r==0){cout<<" ";return 0;}
    for (int i = 1; i <= n - r + 1; ++i) {
        fact(i, 1, to_string(i));
    }
    return 0;
}
void fact(int i, int t, string a) {//x,r即为输入的值，i表示上一层遍历到的值，t表示当前嵌套的层数
    if (t == r) {
        int x=0;
        for (int j = 0; j < a.size(); ++j) {
            if (a[j] != ' ')x = x * 10 + (a[j] - '0');
            else { cout << setw(3) << x; x = 0; }
        }
        cout << setw(3) << x; x = 0;
        cout<<'\n';
    }
    else {
        for (int j = i + 1; j < n - r + t + 2; ++j) {
            fact(j, t + 1, a + " " + to_string(j));
        }
    }
}
