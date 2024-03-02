#include <bits/stdc++.h>

template <typename T>
class list {
private:
    struct list_node {
        T *val;
        list_node *next;
        list_node *pre;
    };
    list_node *m_head; //头节点
    list_node *m_tail; //尾节点
    size_t m_size;     //大小
public:
    list() {
        m_head = nullptr;
        m_tail = new list_node;
        m_size = 0;
    }
    ~list() {
        list_node *m_next = nullptr;
        while(m_head != nullptr) {
            m_next = m_head->next;
            if(m_head->val != nullptr) delete m_head->val;
            delete m_head;
            m_head = m_next;
        }
        m_size = 0;
    }

    void push_back(const T &val) {
        if(m_tail == nullptr) {
            m_tail = new list_node;
            m_tail->val = new T;
            *(m_tail->val) = val;
            m_tail->next = nullptr;
            m_tail->pre = nullptr;
            m_head = m_tail;
        } else {
            m_tail->next = new list_node;
            m_tail->next->pre = m_tail;
            m_tail = m_tail->next;
            m_tail->val = new T;
            *(m_tail->val) = val;
            m_tail->next = nullptr;
        }
        ++m_size;
    }

    void pop_back() {
        if(m_size == 0) 
            throw std::runtime_error("Try to pop_back in the empty list");
        list_node *new_tail = m_tail->pre;
        new_tail->next = nullptr;
        delete m_tail->val;
        delete m_tail;
        m_tail = new_tail;
        --m_size;
    }

    void push_front(const T &val) {
        if(m_head == nullptr) {
            m_head = new list_node;
            m_head->val = new T;
            *(m_head->val) = val;
            m_head->next = nullptr;
            m_head->pre = nullptr;
            m_tail = m_head;
        } else {
            m_head->pre = new list_node;
            m_head->pre->next = m_head;
            m_head = m_head->pre;
            m_head->val = new T;
            *(m_head->val) = val;
            m_head->pre = nullptr;
        }
        ++m_size;
    }

    void pop_front() {
        if(m_size == 0) 
            throw std::runtime_error("Try to pop_front in the empty list");
        list_node *new_head = m_head->next;
        new_head->pre = nullptr;
        delete m_head->val;
        delete m_head;
        m_head = new_head;
        --m_size;
    }

    size_t size() {
        return m_size;
    }

    bool empty() {
        return m_size == 0;
    }

    class iterator {
    private:
        list_node *m_point;
    public:
        iterator() :m_point(nullptr){}
        iterator(T *point) :m_point(point){}
        ~iterator(){}
        bool operator== (const iterator &other){
            return m_point == other.m_point;
        }
        bool operator!= (const iterator &other){
            return m_point != other.m_point;
        }
        iterator operator= (const iterator &other){
            m_point = other.m_point;
            return *this;
        }
        iterator operator++(){
            m_point = m_point->next;
            return *this;
        }
        iterator operator++(int){
            iterator it = *this;
            m_point = m_point->next;
            return it;
        }
        iterator operator--(){
            m_point = m_point->pre;
            return *this;
        }
        iterator operator--(int){
            iterator it = *this;
            m_point = m_point->pre;
            return it;
        }
        T& operator*(){
            return *(m_point->val);
        }
        T* operator->(){
            return m_point->val;
        }
    };
    iterator begin() {
        return iterator(m_head);
    }
    iterator end() {
        return nullptr;
    }

    void insert(iterator pos, const T &val) {
        //TODO
    }
    iterator erase(iterator pos) {
        //todo
    }
};

int main() {
    std::list<int> l;
}