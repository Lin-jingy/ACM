// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

const int N = 1e3 + 5;

class Point {
public:
    int x, y, i;
};

double cross(double x1,double y1,double x2,double y2){　//计算叉积
    return (x1*y2-x2*y1);
}

Point O;

int qua(Point &p){
    if(p.x >= 0 and p.y >= 0) return 0;
    else if(p.x < 0 and p.y >= 0) return 1;
    else if(p.x < 0 and p.y < 0) return 2;
    else return 3;
}

inline double compare(Point &a, Point &b, Point &c){//计算极角
    return cross((b.x-a.x),(b.y-a.y),(c.x-a.x),(c.y-a.y));
}

void solve(){
    int n;
    std::cin >> n;
    std::vector<Point>v(n);
    for(int i(0); i < n; ++i) 
        std::cin >> v[i].i >> v[i].x >> v[i].y;
    std::sort(v.begin(), v.end(), [&](auto v1, auto v2) {
        int k1 = qua(v1), k2 = qua(v2);
        if(k1 != k2) return k1 < k2;
        else return compare(c,a,b)>0;
    });
    

}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    //std::cin >> _;
    while (_--)
        solve();
    return 0;
}
