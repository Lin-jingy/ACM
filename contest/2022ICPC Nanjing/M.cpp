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

inline bool IsPointOnSegment(Point &p,Point &a1,Point &a2){//点在线段上 
    return (dcmp(Cross(p-a1,p-a2))==0 && p.x<=std::max(a1.x,a2.x) && p.x>=std::min(a1.x,a2.x)
    && p.y<=std::max(a1.y, a2.y) && p.y>=std::min(a1.y, a2.y));
}

int inConvexPoly(Point a, std::vector<Point>&p){ //判断点在多边形内
/*
-1:点在凸多边形外
0:点在凸多边形边界上
1:点在凸多边形内*/
    int n = (int)p.size();
    for (int i = 0; i < n; i++){
        if (dcmp(Cross((p[i] - a), (p[(i + 1) % n] - a))) < 0) return -1;
        else if (IsPointOnSegment(a, p[i], p[(i + 1) % n])) return 0;
    }
    return 1;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point> a(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        a[i].x = 1.0 * x, a[i].y = 1.0 * y;
    }
    int ans = 0;
    
    for(int i = 0; i < n; ++i) {
        int last=i;
        int j=i+1;
        j%=n;
        int flag=1;
        while(a[j].y==a[i].y){
            flag=0;
            j++;
            if(j>=n)j-=n;
            last++;
            if(last>=n)last-=n;
        } 
        //std::cout<<i<<' '<<j<<' '<<last<<std::endl;
        if(a[i].y<a[(i+n-1)%n].y&&a[i].y<a[j].y){
            if(!flag&&a[i].x<a[last].x)ans++;
            else if(dcmp(Cross(a[i]-a[(i+n-1)%n],a[j]-a[last])>0))ans++;
        }
        if(j<i)break;
        else i=j-1;
    }
    std::cout << ans << '\n';


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