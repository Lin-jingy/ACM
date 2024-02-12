#include<bits/stdc++.h>

std::map<std::string,std::set<std::string>> sub;
std::map<std::string, int> mp;

void solve() {
	std::string s;
	while(std::cin >> s) {
		std::string mid, mmm;
		int flag = 0;
		int ok = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '\\' and flag == 0) flag = 1;
			else if(s[i] == '\\' and flag) {
				if(!ok){
					for(int k = 0; k < i; ++k) mmm += s[k];
					mp[mmm] ++;	
					ok = 1;
					mid.clear();
				}
				sub[mmm].insert(mid);
			}else if(flag) mid += s[i];
		}
	}
	
	int ans1 = 0;
	for(auto i:sub) ans1 = std::max(ans1, (int)i.second.size());
	int ans2 = 0;
	for(auto i:mp) ans2 = std::max(ans2, i.second);
	std::cout << ans1 - 1 << ' ' << ans2 << '\n';
	
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	//std::cin >> T; 
	while(T--) solve();
	return 0;
}