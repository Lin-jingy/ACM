#include <bits/stdc++.h>


namespace highPrecision {

class Hint {
private:
    bool isNegative;
    std::vector<int> m_data;
    void format(const std::string &s) {
        int index = 0;
        if(s.front() == '-') isNegative = true, ++index;
        while(index < s.size()) {
            if(s[index] != '0') break;
            ++index;
        }
        while(index < s.size()) m_data.push_back(s[index++] - '0');
        if(m_data.empty()) {
            isNegative = false;
            m_data.push_back(0);
        }
        std::ranges::reverse(m_data);
    }
    int abs_value_compare(const Hint &other) {
        if(m_data.size() != other.m_data.size()) return m_data.size() > other.m_data.size() ? 1 : -1;
        for(int i = m_data.size(); i > 0; --i) {
            if(m_data[i] != other.m_data[i]) return m_data[i] > other.m_data[i] ? 1 : -1;
        }
        return 0;
    }
public:
    Hint() = default;
    Hint(const std::string &s) { format(s); }
    Hint(const int x) { format(std::to_string(x)); }
    Hint(const long long x) { format(std::to_string(x)); }
    Hint(const Hint &x):isNegative(x.isNegative), m_data(x.m_data){}
    Hint& mul(const Hint &other) {
        //采用FFT加速运算
        //TODO
        return *this;
    }
    std::string to_string() const{
        std::string result;
        if(isNegative) result += '-';
        for(int i : m_data | std::views::reverse) result += i + '0';
        return result;
    }
    void operator- (int) { isNegative = !isNegative; }
    void operator+= (const Hint &other) {
        if (isNegative != other.isNegative) {
            Hint mid = other;
            *this -= (-mid);
        } else {
            std::vector<int> res(std::max(m_data.size(), other.m_data.size()), 0);
            int carry = 0;
            for (size_t i = 0; i < res.size(); ++i) {
                int sum = (i < m_data.size() ? m_data[i] : 0)
                        + (i < other.m_data.size() ? other.m_data[i] : 0)
                        + carry;
                res[i] = sum % 10;
                carry = sum / 10;
            }
            if (carry > 0) res.push_back(carry);
            m_data.swap(res);
        }
    }
    void operator-= (const Hint &other) {
        //TODO
    }
    void operator*= (const Hint &other) {
        //TODO
    }
    Hint& operator= (const Hint &other) {
        isNegative = other.isNegative;
        m_data = other.m_data;
    }
    void operator/= (const Hint &other) {
        //TODO
    }
    bool operator== (const Hint &other) {
        return isNegative == other.isNegative and m_data == other.m_data;
    }
    bool operator!= (const Hint &other) { return !operator==(other); }
    bool operator< (const Hint &other) {
        if(isNegative and !other.isNegative) return true;
        else if(!isNegative and other.isNegative) return false;
        else if(isNegative) return abs_value_compare(other) == 1;
        else return abs_value_compare(other) == -1;
    }
    bool operator> (const Hint &other) {
        if(isNegative and !other.isNegative) return false;
        else if(!isNegative and other.isNegative) return true;
        else if(isNegative) return abs_value_compare(other) == -1;
        else return abs_value_compare(other) == 1;
    }
    bool operator<= (const Hint &other) { return !operator> (other); }
    bool operator>= (const Hint &other) { return !operator< (other); }
    std::istream& operator>> (std::istream &in) {
        std::string s;
        in >> s;
        format(s);
        return in;
    }
    std::ostream& operator<< (std::ostream &out) const {
		out << to_string();
        return out;
	}

};
std::istream& operator>> (std::istream &in, Hint &other) {
	return other.operator>>(in);
}
std::ostream& operator<< (std::ostream &out, const Hint &other) {
	return other.operator<<(out);
}





}

int main() {
    highPrecision::Hint x("-000123123123222222");
    highPrecision::Hint y("00");
    std::cout << y;
}