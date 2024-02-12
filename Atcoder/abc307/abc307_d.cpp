#include<bits/stdc++.h>

int main(){
    int n;
    std::string s;
    std::cin >> n >> s;
    std::list<char> l;
    for(auto i:s) l.emplace_back(i);
    std::vector<std::list<char>::iterator>v;
    for(auto it = l.begin(); it != l.end();){
        if(*it == '(') v.emplace_back(it), ++it;
        else if(*it == ')') {
            if(v.empty()) {
                ++it;
                continue;
            }
            for(std::list<char>::iterator j = v.back(); j != it;) {
                j = l.erase(j);
            }
            it = l.erase(it);
            v.pop_back();
        }else ++it;
    }
    for(auto i:l) std::cout << i;
    return 0;
}