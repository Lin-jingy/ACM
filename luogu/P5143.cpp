#include<bits/stdc++.h>
#define int long long
using namespace std;
struct position{
	int x;
	int y;
	int z;
}a[50005];
bool fact(position a,position b){
	return a.z<b.z;
}
double sum=0;
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a,a+n,fact);
	for(int i=0;i<n-1;++i){
		sum+=sqrt(pow(a[i+1].x-a[i].x,2)+pow(a[i+1].y-a[i].y,2)+pow(a[i+1].z-a[i].z,2));
	}
	printf("%.3lf",sum);
	return 0;
}