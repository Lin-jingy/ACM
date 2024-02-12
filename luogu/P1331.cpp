#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[1005][1005];
bool flag[1005][1005];
int sum;
int l[4]={0,0,1,-1};
int r[4]={1,-1,0,0};
int R,C;
void dfs(int x,int y){
    int k=0;
    for(int i=0;i<4;++i){
        int ix=x+l[i];
        int iy=y+r[i];
        if(ix>0&&ix<=R&&iy>0&&iy<=C&&!flag[ix][iy]&&a[ix][iy]=='#'){
            k++;
            flag[ix][iy]=true;
            dfs(ix,iy);
        }
    }
}
signed main(){
    cin>>R>>C;
    for(int i=1;i<=R;++i)for(int j=1;j<=C;++j)cin>>a[i][j];
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            if(a[i][j]=='#'&&!flag[i][j]){
                dfs(i,j);
                sum++;
            }
        }
    }
    pair<int,int>first,last;
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            if(flag[i][j]){
                first={i,j};
                while(1){
                    if(flag[i+1][j]){
                        ++i;
                    }else if(flag[i][j+1])
                        ++j;
                    else break;
                }
                last={i,j};
            }
        }
    }
    cout<<"There are "<<sum<<" ships.";
    return 0;
}