#include<bits/stdc++.h>
typedef long long ll;
char a[25][25];
char ans[25][25];
class pair{
public:
    int x;
    int y;
    int val;
};
std::vector<pair> v;
int main(){
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            std::cin>>a[i][j];
            pair node;
            node.x=i,node.y=j,node.val=a[i][j]-'0';
            if(a[i][j]>='0' and a[i][j]<='9')v.push_back(node);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            ans[i][j]=a[i][j];
            for(auto it:v){
                if(abs(i-it.x)+abs(j-it.y)<=it.val)ans[i][j]='.';
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            std::cout<<ans[i][j];
        }
        std::cout<<'\n';
    }
    return 0;
}