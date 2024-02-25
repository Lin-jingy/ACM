#include <bits/stdc++.h>

#define int long long

class Point{
public:
    int x, y;
    Point() {}
    Point(double x, double y) :x(x), y(y) {}
    friend bool operator < (const Point& a, const Point& b){
        return a.x!=b.x?a.x<b.x:a.y<b.y;
    }
    friend Point operator + (const Point& a, const Point& b){
        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator - (const Point& a, const Point& b){
        return Point(a.x - b.x, a.y - b.y);
    }
    friend Point operator * (const Point& a, double k){
        return Point(a.x * k, a.y * k);
    }
    friend Point operator / (const Point& a, double b){
        return Point(a.x/b,a.y/b);
    }  
};
typedef Point Vector;
inline double Dot(const Point &a,const Point &b){//点积 
    return a.x*b.x+a.y*b.y;
}
inline double Cross(const Point &a,const Point &b){//叉积 
    return a.x*b.y-a.y*b.x;
}
inline double Length(const Vector &a) {//求向量的长度
    return sqrt(Dot(a,a));
}
inline double dis(const Point &a, const Point &b){//两点间距离
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double getDistToLine(const Point &P, const Point &A, const Point &B){//点到直线的有向距离（存在正负） 
    Vector AB = B - A, AP = P - A;
    return Cross(AB, AP) / Length(AB);
}

double getDistToSegment(Point &p, Point &a, Point &b){//点到线段的距离
    if (Dot(p - a, b - a) < 0.0) return dis(p, a);
    if (Dot(p - b, a - b) < 0.0) return dis(p, b);
    return fabs(getDistToLine(p, a, b));
}

constexpr int N = 1e3 + 5;
Point a[N];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Point p;
    int r;
    std::cin >> p.x >> p.y >> r;
    int n;
    std::cin >> n;
    std::vector<Point> in, out;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].x >> a[i].y;
        if(dis(a[i], p) >= r) out.push_back(a[i]);
        else in.push_back(a[i]);
    }
    int IN = in.size();
    int OUT = out.size();
    double ans = 0;
    ans += 1.0 * IN * OUT * (OUT - 1);
    ans += 1.0 * IN * (IN - 1) * OUT;
    for(int i = 0; i < OUT; ++i) {
        for(int j = i + 1; j < OUT; ++j) {
            double D = getDistToSegment(p, out[i], out[j]);
            int num = 0;
            if(D < r) num = 2;
            else if(D > r) num = 0;
            else num = 1;
            if(dis(p, out[i]) == r) --num;
            if(dis(p, out[j]) == r) --num;
            
            for(int k = j + 1; k < OUT; ++k) {
                double k1 = getDistToSegment(p, out[i], out[k]);
                double k2 = getDistToSegment(p, out[j], out[k]);
                if(k1 < r) ans += num + 2;
                else if(k1 > r) ans += num;
                else ans += num + 1;
                if(k2 < r) ans += 2;
                else if(k2 > r) ;
                else ans += 1;
            }
        }
    }
    std::cout << ans / (n * (n - 1) * (n - 2) / 6.0);
    

    return 0;
}