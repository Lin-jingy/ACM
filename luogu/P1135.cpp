#include<iostream>
#include<queue>
using namespace std;
#define int long long 
int n, a, b;
int k[205];
int min1=INT_FAST16_MAX;
bool flag[205];
struct fact {
    int t;//当前楼层
    int sum;//记录次数
};
queue<fact>q;
signed main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)cin >> k[i];
    fact x;
    x.sum = 0; x.t = a;
    q.push(x);
    flag[a] = 1;
    while (!q.empty()) {
        fact xx1, xx2;
        xx1.t = q.front().t; xx1.sum = q.front().sum;
        xx2.t = q.front().t; xx2.sum = q.front().sum;
        q.pop();
        if (xx1.t == b && xx1.sum < min1) {
            min1 = xx1.sum;
            cout << min1;
            return 0;
        }
        if (xx1.t + k[xx1.t] <= n&&!flag[xx1.t+k[xx1.t]]) {
            xx1.t += k[xx1.t];
            xx1.sum++;
            flag[xx1.t] = 1;
            q.push(xx1);
        }
        if (xx2.t - k[xx2.t] > 0&&!flag[xx2.t - k[xx2.t]]) {
            xx2.t -= k[xx2.t];
            xx2.sum++;
            flag[xx2.t] = 1;
            q.push(xx2);
        }
    }
    cout << "-1";
    return 0;
}