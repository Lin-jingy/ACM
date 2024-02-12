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

#include<bits/stdc++.h>

using namespace std;

const int eps = 0.000000001;
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
double getDistToLine(const Point &P, const Point &A, const Point &B){//点到直线的有向距离（距离加绝对值） 
    Vector AB = B - A, AP = P - A;
    return Cross(AB, AP) / Length(AB);
}
int ConvexHull(Point *p,int n,Point *ch){//构造逆时针凸包 
    std::sort(p+1,p+n+1);//先按照横坐标再按照纵坐标排序 
    int m=0;
    for(int i=1;i<=n;i++){
        while(m>1 && Cross(ch[m]-ch[m-1],p[i]-ch[m-1])<=0)m--;
        ch[++m]=p[i];
    }
    int k=m;
    for(int i=n-1;i;i--){
        while(m>k && Cross(ch[m]-ch[m-1],p[i]-ch[m-1])<=0)m--;
        ch[++m]=p[i];
    }
    if(n>1)m--;
    return m;
}
double PolygonArea(Point *p,int n){//求逆时针构成的多边形（可不凸）面积 

    double ret(0.0);
    for(int i=2;i<n;i++)//第一个点是p[1],所以这样循环 
        ret+=Cross(p[i]-p[1],p[i+1]-p[1]);
    return ret / 2;
}
bool isPointInPolygon(Point p,Point *poly,int n){//点在凸多边形内的判定 
    int wn = 0;
    poly[n+1]=poly[1];
    for(int i=1;i<=n;i++){
        if(IsPointOnSegment(p,poly[i],poly[i+1]))return -1;
        int k=dcmp(Cross(poly[i+1]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[i+1].y-p.y);
        if(k>0 && d1<=0 && d2>0)wn++;
        if(k<0 && d2<=0 && d1>0)wn--;
    }
    if(wn!=0)return 1;//在内部
    return 0;//在外部
}



void solve(){
   Point a, b, c, d;
   std::cin >> a.x >> a.y >> b.x >> b.y;
   std::cin >> c.x >> c.y >> d.x >> d.y;
   if(SegmentProperIntersection(a, b, c, d)) yes;
   else no;
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}
