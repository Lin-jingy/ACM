#include <bits/stdc++.h>

namespace highPrecision {

class Hint {
private:
    bool isNegative;
    std::vector<int> m_data;
    void format(const std::string &s);
public:
    Hint() = default;
    Hint(const std::string &s);
    Hint(const int x);
    Hint(const long long x);
    Hint(Hint &x);
    Hint& mul(const Hint &other);
    std::string to_string();
    void operator- (int);
    void operator+= (const Hint &other);
    void operator+= (const int other);
    void operator-= (const Hint &other);
    void operator*= (const Hint &other);
    Hint& operator= (const Hint &other);
    void operator/= (const Hint &other);
    bool operator== (const Hint &other);
    bool operator!= (const Hint &other);
    bool operator< (const Hint &other);
    bool operator> (const Hint &other);
    bool operator<= (const Hint &other);
    bool operator>= (const Hint &other);
    std::istream& operator>> (std::istream &in);
    std::ostream& operator<< (std::ostream &out) const;
};




}