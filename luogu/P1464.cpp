#include<iostream>
#include<vector>
#define int long long
using namespace std;
/*int w(int a,int b,int c){                原递归实现（TLE）
    A:;
    if(a<=0 || b<=0 || c<=0)return 1;
    else if(a>20||b>20||c>20){
        a==20;b==20;c==20;
        goto A;
    }
    else if(a<b&&b<c)return (a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}*/



/*int sum;      使用容器实现递归（时间复杂度等同递归，优势时栈不会溢出）
struct th {
    int aa;
    int bb;
    int cc;
    int flag;
};
th x;
vector<th> k;
int w(int a, int b, int c) {
    sum = 0;
    x.aa = a; x.bb = b; x.cc = c; x.flag = 1;//将a,b,c的值放入结构体中
    k.push_back(x);//存入w(a,b,c)
    while (!k.empty()) {//如果容器中还有值
        if (k.back().aa <= 0 || k.back().bb <= 0 || k.back().cc <= 0) {//情况1
            sum += k.back().flag;
            k.pop_back();//如果满足情况就删去并加上值
        }
        else if (k.back().aa > 20 || k.back().bb > 20 || k.back().cc > 20) {//情况2
            x.aa = 20; x.bb = 20; x.cc = 20; x.flag = k.back().flag;
            k.pop_back();
            k.push_back(x);
        }
        else if (k.back().aa < k.back().bb && k.back().bb < k.back().cc) {//情况3
            x.aa = k.back().aa; x.bb = k.back().bb; x.cc = k.back().cc; x.flag = k.back().flag;
            k.pop_back();
            x.cc--;
            k.push_back(x);
            x.bb--;
            k.push_back(x);
            x.cc++;
            x.flag *= -1;
            k.push_back(x);
        }
        else {//其他情况
            x.aa = k.back().aa; x.bb = k.back().bb; x.cc = k.back().cc; x.flag = k.back().flag;
            k.pop_back();
            x.aa--;
            k.push_back(x);
            x.bb--;
            k.push_back(x);
            x.bb++;
            x.cc--;
            k.push_back(x);
            x.bb--;
            x.flag *= -1;
            k.push_back(x);
        }
    }
    return sum;
}*/


int qq[21][21][21];
int sum = 0;
int w(int a, int b, int c) {
//dfs（记忆化搜索）
    if (a <= 0 || b <= 0 || c <= 0)return 1;
    else if (a > 20 || b > 20 || c > 20) {
        a = 20; b = 20; c = 20;
        if (qq[a][b][c] == 0)qq[a][b][c] = w(a, b, c);
    }
    else if (a < b && b < c) {
        if (qq[a][b][c] == 0)
            qq[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else {
        if (qq[a][b][c] == 0)
            qq[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return qq[a][b][c];
}




signed main() {
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)break;
        else
            cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
    return 0;
}