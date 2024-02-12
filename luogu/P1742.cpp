#include<bits/stdc++.h>

const double eps = 1E-12;

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
inline Vector Rotate90Degrees(Vector a) {//旋转90度
    return {-a.y, a.x};
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
    return (dcmp(Cross(p-a1,p-a2))==0 && p.x<=std::max(a1.x,a2.x) && p.x>=std::min(a1.x,a2.x)
    && p.y<=std::max(a1.y, a2.y) && p.y>=std::min(a1.y, a2.y));
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
Point getCrossPoint(Point a1, Point a2, Point b1, Point b2){//求两直线交点(两点式)
    Vector base = b2 - b1;
    double d1 = abs(Cross(base, a1 - b1));
    double d2 = abs(Cross(base, a2 - b1));
    double t = d1 / (d1 + d2);
    return a1 + (a2 - a1) * t;
}
Point getCrossPoint1(Point a1, Vector b1, Point a2, Vector b2) {//求两直线交点(点向式)
    double t = Cross(a2 - a1, b2) / Cross(b1, b2);
    return a1 + b1 * t;
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
    double r = Dot(p - a, base) / (base.x*base.x + base.y*base.y);
    base = base * r;
    return Point(a + base);
}

inline Point reflect(Point p, Point a, Point b){//求点P对于直线s的映像(对称点)
    return p + (project(p, a, b) - p) * 2.0;
}
class Circle {
public:
    Point x;
    double r;
    Circle() {

    }
    Circle(Point x, double r) {
        this->x = x;
        this->r = r;
    }
};

Circle SetCircleAtThreePoints(Point p1, Point p2, Point p3) {
    double a, b, c, d, e, f;
	a = p2.y - p1.y; b = p3.y - p1.y; c = p2.x - p1.x; d = p3.x - p1.x;
	f = p3.x * p3.x + p3.y * p3.y - p1.x * p1.x - p1.y * p1.y;
    e = p2.x * p2.x + p2.y * p2.y - p1.x * p1.x - p1.y * p1.y;
    Circle x;
    x.x.x = (a * f - b * e) / (2 * a * d - 2 * b * c); x.x.y = (d * e - c * f) / (2 * a * d - 2 * b * c);
    x.r = dis(x.x, p1);
    return x;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point> a;
    for(int i = 1; i <= n; ++i) {
        Point x;
        std::cin >> x.x >> x.y;
        a.push_back(x);
    }
    std::random_shuffle(a.begin(), a.end());
    Circle p = {{0, 0}, 0};
    for(int i = 0; i < n; ++i) {
        if(dis(a[i], p.x) > p.r + eps) {
            p = {a[i], 0};
            for(int j = 0; j < i; ++j) {
                if(dis(a[j], p.x) > p.r + eps) {
                    p = {(a[i] + a[j]) / 2, dis(a[i], a[j]) / 2};
                    for(int k = 0; k < j; ++k) {
                        if(dis(a[k], p.x) > p.r + eps) {
                            p = SetCircleAtThreePoints(a[i], a[j], a[k]);
                        }
                    }
                }
            } 
        }
    }
    printf("%.10lf\n%.10lf %.10lf\n", p.r, p.x.x, p.x.y);

    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}