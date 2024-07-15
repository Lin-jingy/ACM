#include <bits/stdc++.h>

class KMP {
	std::string pattern;
	std::vector<int> next;
	void buildNext() {
        static bool first = 0;
        if(first) return ;
		for (int i = 1, j = 0; i < pattern.size(); i++) {
            while (j && pattern[i] != pattern[j]) j = next[j - 1];
            if (pattern[i] == pattern[j]) j++;
            next[i] = j;
		}
	}
public:
	std::vector<int> kmp(std::string txt) {
        buildNext();
		std::vector<int>p;
		for (int i = 0, j = 0; i < txt.size(); i++){
            while (j && txt[i] != pattern[j]) j = next[j - 1];
            if (txt[i] == pattern[j]) j++;
            if (j == pattern.size()){
				p.emplace_back(i - pattern.size() + 1);
                j = next[j - 1];
            }
        }
		return p;
	}
	std::vector<int>& get_next() { buildNext(); return next; }
	KMP(std::string& Pattern) : pattern(Pattern), next(pattern.size()) {}
};

