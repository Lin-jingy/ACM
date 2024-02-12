#include<bits/stdc++.h>

const double eps = 1E-12;
double fast2(double x){
    union P {
            double x;
            unsigned long i[2];
    };
    double a;
    union P x0;
    a = x/2;
    x0.x = x;
    x0.i[1] = ((x0.i[1] &(0xffefffff>>1))>>1)+(512<<20);
    x = x0.x/2 + a/x0.x;
    x = (x/2 + a/x);
    x = (x/2 + a/x);
    x = (x/2 + a/x);
    x = (x/2 + a/x);
    return x;
}



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
    return fast2((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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
double Ploygon_area(std::vector<Point> &s){// 求多边形面积(Shoelace Theorem，鞋带定理)
    int n = s.size();
    double ans = 0.0;
    for (int i = 0; i < n; i++){
        ans += Cross(s[i], s[(i + 1) % n]);
    }
    return ans * 0.5;
}

void solve() {
    Point a, b, c, x;
    int aa, bb, cc, dd, e, f, g, h;
    std::cin >> aa >> bb >> cc >> dd >> e >> f >> g >> h;
    a.x = aa, a.y = bb;
    b.x = cc, b.y = dd;
    c.x = e, c.y = f;
    x.x = g, x.y = h;
    //std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> x.x >> x.y;
    bool f1 = IsPointOnSegment(x, a, b);
    bool f2 = IsPointOnSegment(x, a, c);
    bool f3 = IsPointOnSegment(x, b, c);
    if(!f1 and !f2 and !f3) {
        printf("-1\n");
        return ;
    }
    std::vector<Point> kkk = {a, b, c};
    double area = abs(Ploygon_area(kkk));
    Point ans = {0, 0};
    auto fact = [&](Point x, Point a, Point b, Point c) ->void {
        double l = dis(x, a);
        double r = dis(x, b);
        if(r > l) {
            double h = area / r;
            Vector k1 = c - b;
            Vector k2 = a - b;
            double xx = h * (dis(c, b) * dis(a, b) / abs((Cross(k1, k2))));
            ans = b + k1 * (xx / dis(c, b));
        }else {
            double h = area / l;
            Vector k1 = c - a;
            Vector k2 = b - a;
            double xx = h * (dis(a, c) * dis(a, b) / abs((Cross(k1, k2))));
            ans = a + k1 * (xx / dis(c, a));
        }
    };
    if(f1) fact(x, a, b, c);
    else if(f3) fact(x, b, c, a);
    else fact(x, a, c, b);
    printf("%.12lf %.12lf\n", ans.x, ans.y);
    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}