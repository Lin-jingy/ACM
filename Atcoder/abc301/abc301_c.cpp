#include "bits/stdc++.h"
 
int cnts[27], cntt[27];
 
signed main() {
	std::string s; std::cin >> s;
	std::string t; std::cin >> t;
 
	for (int i = 0; i < s.length(); ++ i) {
		if (s[i] == '@') cnts[26] ++;
		else cnts[s[i] - 'a'] ++;
 
		if (t[i] == '@') cntt[26] ++;
		else cntt[t[i] - 'a'] ++;
	}
 
	
	for (int i = 0; i < 26; ++ i) { // @ 不用减
		int tmp = std::min(cntt[i], cnts[i]);
		cntt[i] -= tmp;
		cnts[i] -= tmp;
	}
 
	// for (int i = 0; i <= 26; ++ i) std::cout << cnts[i] << " ";
	// std::cout << "\n";
	// for (int i = 0; i <= 26; ++ i) std::cout << cntt[i] << " ";
	// std::cout << "\n";
 
	int get[7] = {'a' - 'a', 't' - 'a', 'c' - 'a', 'o' - 'a', 'd' - 'a', 'e' - 'a', 'r' - 'a'};
 
	bool ans = true;
	for (int i = 0; i < 26; ++ i) {
		if (cnts[i] > 0) {
			bool flag = false;
			for (int j = 0; j < 7; ++ j) {
				if (get[j] == i) flag = true;
			}
			if (flag and cntt[26] >= cnts[i]) {
				cntt[26] -= cnts[i];
			} else {
				ans = false;
				//std::cout << "error in s\n";
			}
		}
	}
 
	for (int i = 0; i < 26; ++ i) {
		if (cntt[i] > 0) {
			bool flag = false;
			for (int j = 0; j < 7; ++ j) {
				if (get[j] == i) flag = true;
			}
			if (flag and cnts[26] >= cntt[i]) {
				cnts[26] -= cntt[i];
			} else {
				ans = false;
				//std::cout << "error in t\n";
			}
		}
	}
 
	if (ans) std::cout << "Yes\n";
	else std::cout << "No\n";
}