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
inline bool IsPointOnSegment(Point p,Point a1,Point a2){//点在线段上 
    return dcmp(Cross(p-a1,p-a2))==0 && dcmp(Dot(p-a1,p-a2))<0;
}
double getDistToLine(const Point &P, const Point &A, const Point &B){//点到直线的有向距离（存在正负） 
    Vector AB = B - A, AP = P - A;
    return Cross(AB, AP) / Length(AB);
}
double getDistToSegment(Point p, Point a, Point b){//点到线段的距离
    if (Dot(p - a, b - a) < 0.0) return dis(p, a);
    if (Dot(p - b, a - b) < 0.0) return dis(p, b);
    return fabs(getDistToLine(p, a, b));
}

bool isInGeometry(Point p, std::vector<Point> &v){//点是否在图形内侧
    //注意要把第一条边连回来
    //否则会少一条边
    int flag1 = 0, flag0 = 0;
    int len = v.size();
    for(int i = 1; i < len; ++i){
        double k = Cross(p - v[i - 1], v[i] - v[i - 1]);
        if(k < 0) ++flag1; // 可以存在边界上的时候取等号
        if(k > 0) ++flag0;
    }
    if(flag1 == v.size() - 1 or flag0 == v.size() - 1) return true;
    else return false; 
}

void solve(){
    std::vector<Point>v(4);
    Point x;
    std::cin >> x.x >> x.y;
    v[0] = x;
    for(int i = 1; i < 3; ++i) std::cin >> v[i].x >> v[i].y;
    v[3] = x;
    Point p = {0.0, 0.0};
    if(isInGeometry(p, v)) std::cout << "YES\n";
    else std::cout << "NO\n";
    
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
