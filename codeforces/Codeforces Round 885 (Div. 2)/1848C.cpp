#include<bits/stdc++.h>


int calc(int x,int y){
	if(x == 0) return 0;
	if(y == 0) return 1;
	x %= 2 * y;  
    return ((calc(y, abs(x - y)) + 1) % 3);
}


int main(){
	int T;
    std::cin >> T;
	while(T--) {
        int n;
        std::cin >> n;
        std::vector<int>a(n + 1), b(n + 1);
        for(int i(1); i <= n; ++i) std::cin >> a[i];
	    for(int i(1); i <= n; ++i) std::cin >> b[i];
	    int k(-1);
	    for(int i(1); i <= n; ++i) {
	    	if(a[i] == 0 and b[i] == 0)continue;
	    	int op = calc(a[i], b[i]);
	    	if(k == -1) k = op;
	    	else if(k != op){
                std::cout << "NO\n";
                goto A;
            }
	    } 
        std::cout << "YES\n";
        A:;
    }
	return 0;
} 