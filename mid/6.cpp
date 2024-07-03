#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	T f=1;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}//快读，常数优化
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		write(x*-1);
		return;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}//快写，常数优化
string st[18];
vector<int>v[210];//动态数组
int f[18];//标记数组
int dfs(int x){
	int ans=0;
	for(auto i:v[st[x][st[x].size()-1]])//v数组是存第1个字母的一个容器
		if(!f[i]){
			f[i]=1;//标记这个字符串已经用过了
			ans=max(ans,dfs(i));//打擂
			f[i]=0;//回溯
		}
	return ans+st[x].size();
}
int main(){
	int ans=0,n;
	read(n);//读入
	for(int i=1;i<=n;i++)cin>>st[i],v[st[i][0]].push_back(i);//读入，放入vector容器
	for(int i=1;i<=n;i++){
		f[i]=1;//表记
		ans=max(ans,dfs(i));//打擂法找到最优解
		f[i]=0;//回溯
	}
	write(ans);//输出
    return 0;
}