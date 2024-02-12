#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[25][25]={};
int sum=0;
int fact(int aa,int bb){
    if(aa==0&&bb==0){
        sum++;
        return 0;
    }
    if(aa-1>=0 && a[aa-1][bb]!=-1){fact(aa-1,bb);}
    if(bb-1>=0 && a[aa][bb-1]!=-1){fact(aa,bb-1);}
    return 0;
}
signed main(){
    int bx,by;
    int mx,my;
    cin>>bx>>by>>mx>>my;
    if(mx-1>=0&&my-2>=0)a[mx-1][my-2]=-1;
    if(mx-2>=0&&my-1>=0)a[mx-2][my-1]=-1;
    if(mx-2>=0&&my+1<=by)a[mx-2][my+1]=-1;
    if(mx-1>=0&&my+2<=by)a[mx-1][my+2]=-1;
    if(mx+1<=bx&&my+2<=by)a[mx+1][my+2]=-1;
    if(mx+2<=bx&&my+1<=by)a[mx+2][my+1]=-1;
    if(mx+2<=bx&&my-1>=0)a[mx+2][my-1]=-1;
    if(mx+1<=bx&&my-2>=0)a[mx+1][my-2]=-1;
    a[mx][my]=-1;
    fact(bx,by);
    cout<<sum;
    return 0;
}