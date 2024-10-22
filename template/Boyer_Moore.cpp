#include <bits/stdc++.h>

class Boyer_Moore {
   private:
    std::boyer_moore_searcher<
        __gnu_cxx::__normal_iterator<const char *, std::string>,
        std::hash<char>>
        bm;

   public:
    Boyer_Moore(const std::string &s) : bm{s.begin(), s.end()} {}
    std::vector<int> find(std::string_view text) {
        std::vector<int> result;
        for (auto [beg, end] = bm(text.begin(), text.end()); beg != text.end();
             std::tie(beg, end) = bm(end, text.end())) {
            result.push_back(beg - text.begin());
        }
        return result;
    }
};