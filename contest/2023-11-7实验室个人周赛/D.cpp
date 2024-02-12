#include<bits/stdc++.h>

#define int long long
int dp[1005][1005][4];
std::string s[1005];
struct Point {
    int x, y;
};

int fact(char p, int x, int y) {
    if(p == '+') return 0;
    if(p == '-') return y==0?0:1;
    if(p == '|') return x==0?0:1;
    if(p == '^') {
        if(x == 0 and y == -1) return 0;
        if(x == 1 and y == 0) return 3;
        if(x == 0 and y == 1) return 2;
        if(x == -1 and y == 0) return 1;
    }
    if(p == '>') {
        if(x == 0 and y == -1) return 1;
        if(x == 1 and y == 0) return 0;
        if(x == 0 and y == 1) return 3;
        if(x == -1 and y == 0) return 2;
    }
    if(p == '<') {
        if(x == 0 and y == -1) return 3;
        if(x == 1 and y == 0) return 2;
        if(x == 0 and y == 1) return 1;
        if(x == -1 and y == 0) return 0;
    }
    if(p == 'V') {
        if(x == 0 and y == -1) return 2;
        if(x == 1 and y == 0) return 1;
        if(x == 0 and y == 1) return 0;
        if(x == -1 and y == 0) return 3;
    }
    if(p == 'L') return x==-1&&y==0?1:0;
    if(p == 'R') return x==1&&y==0?1:0;
    if(p == 'U') return x==0&&y==1?1:0;
    if(p == 'D') return x==0&&y==-1?1:0;
    if(p == '*') return INT_MAX;
    return 0;
}

char change(char p) {
    switch (p){
        case '+': return '+';
        case '-': return '|';
        case '|': return '-';
        case '^': return '>';
        case '>': return 'V';
        case 'V': return '<';
        case '<': return '^';
        case 'L': return 'U';
        case 'U': return 'R';
        case 'R': return 'D';
        case 'D': return 'L';
        case '*': return '*';
    }
    return ' ';
}

int dis(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) std::cin >> s[i], s[i] = ' ' + s[i];
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) for(int k = 0; k < 4; ++k) dp[i][j][k] = INT_MAX; 
    Point begin, end;
    std::cin >> begin.x >> begin.y >> end.x >> end.y;
    std::queue<Point> q;
    q.push(begin);
    dp[begin.x][begin.y][0] = 0;
    dp[begin.x][begin.y][1] = 1;
    dp[begin.x][begin.y][2] = 2;
    dp[begin.x][begin.y][3] = 3;
    while(!q.empty()) {
        auto P = q.front();
        int x = P.x, y = P.y;
        q.pop();
        if(dis(P, begin) < dis({x, y + 1}, begin) and y + 1 <= m) {
            char p = s[x][y];
            for(int i = 0; i < 4; ++i) {
                int k = fact(p, 1, 0);
                dp[x][y + 1][(i + k) % 4] = std::min(dp[x][y + 1][(i + k) % 4], dp[x][y][i] + k + 1);
                p = change(p);
            }
            q.push({x + 1, y});
        }
        if(dis(P, begin) < dis({x + 1, y}, begin) and x + 1 <= n) {
            char p = s[x][y];
            for(int i = 0; i < 4; ++i) {
                int k = fact(p, 1, 0);
                dp[x + 1][y][(i + k) % 4] = std::min(dp[x + 1][y][(i + k) % 4], dp[x][y][i] + k + 1);
                p = change(p);
            }
            q.push({x, y + 1});
        }
        if(dis(P, begin) < dis({x, y - 1}, begin) and y - 1 >= 1) {
            char p = s[x][y];
            for(int i = 0; i < 4; ++i) {
                int k = fact(p, 1, 0);
                dp[x][y - 1][(i + k) % 4] = std::min(dp[x][y - 1][(i + k) % 4], dp[x][y][i] + k + 1);
                p = change(p);
            }
            q.push({x - 1, y});
        }
        if(dis(P, begin) < dis({x - 1, y}, begin) and x - 1 >= 1) {
            char p = s[x][y];
            for(int i = 0; i < 4; ++i) {
                int k = fact(p, 1, 0);
                dp[x - 1][y][(i + k) % 4] = std::min(dp[x - 1][y][(i + k) % 4], dp[x][y][i] + k + 1);
                p = change(p);
            }
            q.push({x, y - 1});
        }
        dp[x][y][0] = std::min({dp[x][y][3] + 1, dp[x][y][2] + 2, dp[x][y][1] + 3});
        dp[x][y][1] = std::min({dp[x][y][3] + 2, dp[x][y][2] + 3, dp[x][y][0] + 1});
        dp[x][y][2] = std::min({dp[x][y][3] + 3, dp[x][y][0] + 2, dp[x][y][1] + 1});
        dp[x][y][3] = std::min({dp[x][y][0] + 3, dp[x][y][2] + 1, dp[x][y][1] + 2});
    }
    int &x = end.x, &y = end.y;
    int ans = std::min({dp[x][y][0], dp[x][y][1], dp[x][y][2], dp[x][y][3]});
    if(ans >= 4000000) std::cout << -1 << '\n';
    else std::cout << ans << '\n';
    return ;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}