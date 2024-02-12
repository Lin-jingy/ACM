#include<iostream>
#include<queue>
#define int long long 
using namespace std;
int l[] = { 0,0,1,-1 };
int r[] = { 1,-1,0,0 };//上，下，右，左
struct event {
    int time;
    int x, y;
};
queue<event>q;
int a[305][305] = { -1 };//该空间的状态，-1为安全区，其余数为陨石落下的时间
bool pd[305][305];
signed main() {
    //输入
    for (int i = 0; i < 305; ++i) {
        for (int j = 0; j < 305; ++j)a[i][j] = -1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        if(a[x][y] > t || a[x][y] == -1)a[x][y] = t;
        for (int j = 0; j < 4; ++j) {
            if (x + l[j] >= 0 && y + r[j] >= 0 && a[x+l[j]][y+r[j]]>t || a[x + l[j]][y + r[j]]==-1)a[x + l[j]][y + r[j]] = t;
        }
    }
    //bfs
    a[0][0] = -2;
    pd[0][0] = true;
    event x;
    x.time = 0; x.x = 0; x.y = 0;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (a[x.x][x.y] == -1) { cout << x.time; return 0; }
        for (int i = 0; i < 4; ++i) {
            event xx = x;
            xx.x += l[i]; xx.y += r[i];
            if (xx.x >= 0 && xx.y >= 0 && !pd[xx.x][xx.y] && (xx.time+1 < a[xx.x][xx.y] || a[xx.x][xx.y]==-1)) {
                ++xx.time;
                pd[xx.x][xx.y] = true;
                q.push(xx);
            }
        }
    }
    cout << "-1";
    return 0;
}