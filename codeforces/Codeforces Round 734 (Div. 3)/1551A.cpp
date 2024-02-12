#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> x;
		printf("%d %d\n",(x%3==1)?x/3+1:x/3,(x%3==2)?x/3+1:x/3);
	}
	return 0;
}