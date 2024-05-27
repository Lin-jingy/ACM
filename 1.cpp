#include <any>
#include <bits/stdc++.h>
#include <memory>
#include <type_traits>

#define int long long
#define rep(i,b,e)for(int i=b;i<e;++i)
#define RETURN(x)do{return x,void();}while(0)
#define All(x)x.begin(),x.end()
#define pb(x)push_back(x)
#define eb(x)emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX
template<class T>using vec=std::vector<T>;using str=std::string;template<class K,class V>using umap=std::unordered_map<K,V>;template<class T>using uset=std::unordered_set<T>;template<class K,class V>std::istream&operator>>(std::istream&in,std::pair<K,V>&v){in>>v.first>>v.second;return in;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::pair<K,V>&v){out<<'{'<<v.first<<","<<v.second<<'}';return out;}template<class T>std::istream&operator>>(std::istream&in,std::vector<T>&v){for(auto&i:v)in>>i;return in;}template<class T>std::ostream&operator<<(std::ostream&out,const std::vector<T>&v){for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];return out;}template<class T>std::ostream&operator<<(std::ostream&out,const std::set<T>&s){out<<"\nsize:"<<s.size()<<'\n';for(auto i=s.begin();i!=s.end();++i)out<<*i<<" \n"[i==s.end()];return out;}template<class K,class V>std::ostream&operator<<(std::ostream&out,const std::map<K,V>&mp){out<<"\nsize:"<<mp.size()<<'\n';for(auto i=mp.begin();i!=mp.end();++i)out<<'{'<<i->first<<","<<i->second<<"}\n";return out;}using Pii=std::pair<int,int>;template<class T>using vvec=std::vector<std::vector<T>>;template<class K,class V>struct std::hash<std::pair<K,V>>{size_t operator()(const std::pair<K,V>&p)const{return std::hash<K>{}(p.first)^std::hash<V>{}(p.second);}};template<class T>using min_heap=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using max_heap=std::priority_queue<T>;
#define vec(type,x,sz,val)std::vector<type>x(sz,val);
#define vvec(type,x,sz1,sz2,val)std::vector<std::vector<type>>x(sz1,std::vector<type>(sz2,val));
#if defined(_WIN64)
#define log(...)print(#__VA_ARGS__" ::",__VA_ARGS__)<<std::endl
template<class...Ts>auto&print(Ts...ts){return((std::cerr<<ts<<" "),...);}
#define ensure(x)if(!(x)){std::cerr<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define sure(x)111
#define log(...)111
#endif

class var {
public:
    // 默认构造函数，创建一个空的Var对象
    var() = default;
    ~var() = default;

    // 通用构造函数，接受任意类型的参数并存储其值
    template <typename T>
    var(T&& value): m_value(std::forward<T>(value)){}

    // 重载赋值运算符，允许改变存储的值（类型可能变化）
    template <typename T>
    var& operator=(T&& value) {
        m_value = std::forward<T>(value);
        return *this;
    }

    // 获取当前存储值的类型名称（用于调试或错误信息）
    const char* type_name() const {
        return m_value.type().name();
    }


    // const版本的get方法
    template <typename T>
    const T& get() const {
        return const_cast<var*>(this)->get<T>();
    }

    template<typename T>
    const T& get() {
        if (m_value.has_value()) {
            if (m_value.type() == typeid(int)) {
                return std::any_cast<int>(m_value);
            } else if (m_value.type() == typeid(double)) {
                return std::any_cast<double>(m_value);
            } else if (m_value.type() == typeid(std::string)) {
                return std::any_cast<std::string>(m_value);
            } else {
                return "<unknown type>";
            }
        } else {
            return "<undefine>";
        }
    }

    // 重载输出流运算符<<，将Var对象的值输出到ostream
    friend std::ostream& operator<<(std::ostream& os, const var& var) {
        if (var.m_value.has_value()) {
            const auto& value = var.m_value;
            if (value.type() == typeid(int)) {
                os << std::any_cast<int>(value);
            } else if (value.type() == typeid(double)) {
                os << std::any_cast<double>(value);
            } else if (value.type() == typeid(std::string)) {
                os << std::any_cast<std::string>(value);
            } else {
                os << "<unknown type>";
            }
        } else {
            os << "<undefine>";
        }
        return os;
    }



private:
    std::any m_value;  // 存储任意类型值的容器
};



void solve() {

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}
