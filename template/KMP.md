# KMP

```c++
class KMP {
	std::string pattern;
	int *next;
	void buildNext() {
		for (int i = 1, j = 0; i < pattern.size(); i++) {
        	while (j && pattern[i] != pattern[j]) j = next[j - 1];
        	if (pattern[i] == pattern[j]) j++;
        	next[i] = j;
		}
	}
public:
	std::vector<int> kmp(std::string txt) {
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
	int* get_next() {
		return next;
	}
	KMP(std::string Pattern) {
		pattern = Pattern;
		next = (int*)malloc(sizeof(int) * pattern.size());
        memset(next, 0, sizeof(next));
		buildNext();
	}
};

```
