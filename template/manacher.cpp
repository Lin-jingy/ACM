#include <bits/stdc++.h>

class manacher{
private:
	std::string res;
	std::vector<int> p;
	std::pair<int, int> get(){
		int len = res.size();
		int c = 0, r = 0;
		int max_len = 0;
		int start = -1;
		for(int i = 1; i < len; i++){
			if(i <= r){
				p[i] = std::min(p[2 * c - i], r - i);
			}
			while(res[i - p[i] - 1] == res[i + p[i] + 1]) p[i]++;
			if(i + p[i] > r){
				c = i;
				r = i + p[i];
			}
			if(p[i] > max_len){
				max_len = p[i];
				start = (i - p[i]) / 2;
			}
			// (i-p[i])/2是回文起始点,字符串从0开始
		}
		return {start, max_len};
	}
public:
	manacher(std::string &s){
		res = "^";
		for(auto x:s){
			res += '#';
			res += x;
		}
		res += "#&";
		p.resize(res.size() + 1);
	}
	bool check(int l,int r){
        static bool is_run_get = false;
        if(!is_run_get) is_run_get = true, get();
		int len = (r - l + 1);
		int center = (l + r) / 2;
		center = center * 2 + 2;
		if(len % 2 == 0) center++;
		return p[center] >= len;
	}
};