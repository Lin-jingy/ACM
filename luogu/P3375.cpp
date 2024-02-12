#include<bits/stdc++.h>

class KMP {
public:
    std::string txt, pattern;
	int *next;
	std::vector<int>p;
	void buildNext() {
		for (int i = 1, j = 0; i < pattern.size(); i++) {
        	while (j && pattern[i] != pattern[j]) j = next[j - 1];
        	if (pattern[i] == pattern[j]) j++;
        	next[i] = j;
		}
	}
	void kmp() {
		for (int i = 0, j = 0; i < txt.size(); i++){
        	while (j && txt[i] != pattern[j]) j = next[j - 1];
        	if (txt[i] == pattern[j]) j++;
        	if (j == pattern.size()){
				p.emplace_back(i - pattern.size() + 1);
            	j = next[j - 1];
        	}
    	}
	}

	KMP(std::string Txt, std::string Pattern) {
		txt = Txt, pattern = Pattern;
		next = (int*)malloc(sizeof(int) * pattern.size());
        for(int i = 0; i < pattern.size(); ++i) next[i] = 0;
		buildNext();
		kmp();
	}
};

int main(){
    std::string a, b;
    std::cin >> a >> b;
    KMP T(a, b);
    for(auto i:T.p) std::cout << i + 1 << '\n';
    for(int i = 0; i < b.size(); ++i) std::cout << T.next[i] << ' ';
    return 0;
}