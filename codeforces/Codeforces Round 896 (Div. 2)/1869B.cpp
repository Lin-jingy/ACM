#include<bits/stdc++.h>

class Point{
public:
    int x, y;
};

inline long long dis(Point &a, Point &b){
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

void solve() {
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;
    std::vector<Point>v(n);
    for(int i = 0; i < n; ++i) std::cin >> v[i].x >> v[i].y;
    long long dis1 = 1e15, dis2 = 1e15;
    if(a > k) for(int i = 0; i < k; ++i) dis1 = std::min(dis1, dis(v[a - 1], v[i]));
    else dis1 = 0;
    if(b > k) for(int i = 0; i < k; ++i) dis2 = std::min(dis2, dis(v[b - 1], v[i]));
    else dis2 = 0;
    std::cout << std::min(dis1 + dis2, dis(v[a - 1], v[b - 1])) << '\n';
    
    
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}