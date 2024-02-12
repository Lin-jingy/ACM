#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[7][7];
int flag[7][7];//标记访问的时间
int l[9]={-1,0,1,-1,1,-1,0,1,0};//对于方向的遍历
int r[9]={-1,-1,-1,0,0,1,1,1,0};
int max1;//记录最大值
int sk=0;
//dfs
void dfs(int sum,int kk){//sum为当前的和，k为当前选数的次数
    int ff=0;//判断是否结束的标记
    for(int i=1;i<=n;++i){//对每个位置进行遍历
        for(int j=1;j<=m;++j){
            if(flag[i][j]==0){//如果未被访问过
                ++ff;//判断进入过循环
                for(int k=0;k<9;++k){//对九个位置未被访问的位置标记
                    int ki=i+l[k];
                    int kj=j+r[k];
                    if(ki>0&&ki<=n&&kj>0&&kj<=m)//无越界
                        if(flag[ki][kj]==0)flag[ki][kj]=kk;//未被标记过
                }
                if(sk==0){sk++;dfs(0,kk+1);}//递归调用下一次
                else dfs(sum+a[i][j],kk+1);
                for(int k=0;k<9;++k){//回溯
                    int ki=i+l[k];
                    int kj=j+r[k];
                    if(ki>0&&ki<=n&&kj>0&&kj<=m)//判断未越界
                        if(flag[ki][kj]==kk)flag[ki][kj]=0;//删除当前次的标记
                }
            }
        }
    }
    if(!ff){//如果遍历完发现已经全部访问过
        if(sum>max1)max1=sum;//判断最大值
    }
}
signed main(){
    int t;
    cin>>t;
    for(int i=0;i<t;++i){//初始化
        sk=0;
        for(int j=0;j<7;++j)
            for(int k=0;k<7;++k){
                a[j][k]=0;
                flag[j][k]=0;
            }
        max1=0;
        cin>>n>>m;
        for(int j=1;j<=n;++j){//输入
            for(int k=1;k<=m;++k){
                cin>>a[j][k];
            }
        }
        dfs(0,0);//dfs搜索
        cout<<max1<<'\n';
    }
    return 0;
}




