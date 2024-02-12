#include<bits/stdc++.h>

int main(){
    int n;	
    std::cin >> n;
	std::vector<int>fa(n + 1) , p(n + 1);
	for(int i(2);i <= n; i++) std::cin >> fa[i];
	for(int i(1);i <= n; i++) p[i] = i;
	int q;	
    std::cin >> q;
	auto find = [&](auto find ,int x)->int{return p[x] == x ? x : p[x] = find(find, p[x]);};

	while(q--){
		int op, x, y;
        std::cin >> op;
		if(op == 1){
			std::cin >> x >> y;
			while(find(find, x) != find(find, y))p[find(find, x)] = find(find,fa[find(find, x)]);
		}else{
			std::cin >> x;
			std::cout << find(find, x) << '\n';
		}
	}
    return 0;
}