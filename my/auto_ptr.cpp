

template <class T>
class auto_ptr {
   private:
    T *m_point;

   public:
    auto_ptr(T *P = nullptr) : m_point(P) {}
    ~auto_ptr() { delete m_point; }
    T &operator*() const { return *m_point; }
    
};