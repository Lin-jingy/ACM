#include<bits/stdc++.h>

void solve(){
    std::string s;
    std::cin >> s;
    int sort = 0, unsort = INT_MAX;
    int num = 0;
    bool flag = false;
    for(int i = 0; i < s.size(); i++) {
		if(s[i] == '+') num++;
		else if(s[i]=='-') {
			num--;
			if(unsort == num+1) unsort = INT_MAX;
			if(sort == num+1) sort--;
		}
		else if(s[i] == '0'){
			if(num<=sort or num < 2){
				std::cout << "NO\n";
				flag = true;
				return ;
			}
			unsort = std::min(unsort, num);
		}
		else{
			if(num >= unsort){
				flag = true;
				std::cout << "NO\n";
				return ;
			}
			sort = num;
		}
    }
	if(!flag) std::cout << "YES\n";
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}