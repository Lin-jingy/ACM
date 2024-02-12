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

const double eps = 0.000000001;
class Point{
public:
    double x, y;
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
typedef Point P;



double dcmp(double x){//符号判断 (精度修正)
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
inline double Dot(const Point &a,const Point &b){//点积 
    return a.x*b.x+a.y*b.y;
}
inline double Cross(const Point &a,const Point &b){//叉积 
    return a.x*b.y-a.y*b.x;
}
inline double dis(const Point &a, const Point &b){//两点间距离
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline double Length(const Vector &a) {//求向量的长度
    return sqrt(Dot(a,a));
}
inline double Angle(const Vector &a,const Vector &b){//求两个向量的夹角（余弦定理） 
    return acos(Dot(a,b)/Length(a)/Length(b));
}
inline Point Rotate(const Point &a,double rad){//逆时针旋转rad 
    return Point(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Point Normal(Point &v){//求单位长度的法向量 
    double L = Length(v);
    return Point(-v.y/L,v.x/L);
}
Point getLineIntersection(const Point &P,const Point &v,const Point &Q,const Point &w){//求两个线段交点 
    Vector u = P-Q;
    double t = Cross(w,u) / Cross(v,w);
    return P + v * t;
}
bool SegmentProperIntersection(const Point &a1,const Point &b1,const Point &a2,const Point &b2){//两线段规范相交、即每条线段的端点分别在另一条一段的两侧 

    double c1=Cross(b1-a1,a2-a1),c2=Cross(b1-a1,b2-a1);
    double c3=Cross(b2-a2,a1-a2),c4=Cross(b2-a2,b1-a2);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
inline bool IsPointOnSegment(Point &p,Point &a1,Point &a2){//点在线段上 
    return dcmp(Cross(p-a1,p-a2))==0 && dcmp(Dot(p-a1,p-a2))<0;
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
bool isInGeometry(Point &p, std::vector<Point> &v){//点是否在图形内侧
    int flag1 = 0, flag0 = 0;
    int len = v.size();
    for(int i = 0; i < len; ++i){
        double k = Cross(p - v[i], v[(i + 1) % len] - v[i]);
        if(k < 0) ++flag1; // 可以存在边界上的时候取等号
        if(k > 0) ++flag0;
    }
    if(flag1 == v.size() - 1 or flag0 == v.size() - 1) return true;
    else return false; 
}
Point getCrossPoint(Point a1, Point a2, Point b1, Point b2){//求两直线交点
    Vector base = b2 - b1;
    double d1 = abs(Cross(base, a1 - b1));
    double d2 = abs(Cross(base, a2 - b1));
    double t = d1 / (d1 + d2);
    Point x = (a2 - a1) * t;
    return a1 + x;
}
double Ploygon_area(std::vector<Point> &s){// 求多边形面积(Shoelace Theorem，鞋带定理)
    int n = s.size();
    double ans = 0.0;
    for (int i = 0; i < n; i++){
        ans += Cross(s[i], s[(i + 1) % n]);
    }
    return ans * 0.5;
}

Point project(Point &p, Point &a, Point &b){//求点P在直线s上的投影
    Vector base = b - a;
    double r = Dot(p - a, base) / (pow(base.x,2) + pow(base.y,2));
    base = base * r;
    return Point(a + base);
}

inline Point reflect(Point p, Point a, Point b){//求点P对于直线s的映像(对称点)
    Point p1 = (project(p, a, b) - p) * 2.0;
    return p + p1;
}

void solve(){
    Point p, a, b;
    std::cin >> p.x >> p.y >> a.x >> a.y >> b.x >> b.y;
    p = project(p, a, b);
    //std::cout << p.x << ' ' << p.y << '\n';
    printf("%.7lf %.7lf\n", p.x, p.y);
    
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
