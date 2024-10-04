#include <cstddef>

template <class T>
class List {
   private:
    class List_node {
        T* val;
        List_node* prev;
        List_node* next;
    };

    class iterator {
        List_node* m_ptr;

       public:
        iterator(List_node* ptr) : m_ptr(ptr) {}
        iterator(const iterator &other) : m_ptr(other.m_ptr) {}

        iterator& operator++() {
            m_ptr = m_ptr->next;
            return *this;
        }

        iterator& operator--() {
            m_ptr = m_ptr->prev;
            return *this;
        }

        bool operator==(const iterator& other) const {
            return m_ptr == other.m_ptr;
        }

        bool operator!=(const iterator& other) const {
            return m_ptr != other.m_ptr;
        }

        T& operator*() const { return *m_ptr->val; }

    };

   private:
    List_node* tail;
    std::size_t m_size;
};