#include <bits/stdc++.h>

template <class T>
class Scapegoat_tree {
private:
    const int ERROR = -1;
    static int balance_coefficient = 2;
    struct treeNode {
        T *val;
        size_t size = 1;
        treeNode *l, *r, *fa;
        treeNode() {}
        treeNode(treeNode *p) {
            this->val = p->val;
            this->size = p->size;
            this->fa = p->fa;
            this->l = p->l;
            this->r = p->r;
        }
    };
    treeNode *root;
    treeNode Insert(T x, treeNode *p, treeNode *f) {
        if (!p) {
            p = (treeNode *)malloc(sizeof(treeNode));
            p->val = x;
            p->fa = f;
            return treeNode(p);
        }
        if (x < p->val) {
            return Insert(x, p->l);
        } else if (x > p->val) {
            return Insert(x, p->r);
        } else {
            return treeNode(p);
        }
        p->size = (p->l ? p->l->size : 0) + (p->r ? p->r->size : 0) + 1;
    }
    treeNode Delete(T x, treeNode *p, treeNode *f) {
        if (!p) return nullptr;
        if (x < p->val) {
            Delete(x, p->l);
        } else if (x > p->val) {
            Delete(x, p->r);
        } else {
            if (!p->l and !p->r) {
                if (p->val < p->fa->val) {
                    p->fa->l = nullptr;
                } else {
                    p->fa->r = nullptr;
                }
                treeNode mid(p);
                free(p);
                return mid;
            } else if (p->l) {
                treeNode sp = p;
                while (sp->r) sp = sp->r;
                if (p->val < p->fa->val) {
                    p->fa->l = sp;
                } else {
                    p->fa->r = sp;
                }
                sp->l = p->l;
                sp->r = p->r;
                sp->fa = p->fa;
                treeNode mid(p);
                free(p);
                return mid;
            } else if (p->r) {
                treeNode sp = p;
                while (sp->l) sp = sp->l;
                if (p->val < p->fa->val) {
                    p->fa->l = sp;
                } else {
                    p->fa->r = sp;
                }
                sp->l = p->l;
                sp->r = p->r;
                sp->fa = p->fa;
                treeNode mid(p);
                free(p);
                return mid;
            }
        }
        p->size = (p->l ? p->l->size : 0) + (p->r ? p->r->size : 0) + 1;
    }
    treeNode *Find(T x, treeNode *p) {
        if (!p) return nullptr;
        if (x < p->val) {
            return Find(x, p->l);
        } else if (x > p->val) {
            return Find(x, p->r);
        } else {
            return p;
        }
    }
    void Free(treeNode *p) {
        if (!p) return;
        Free(p->l);
        Free(p->r);
        free(p);
    }
    balance(treeNode *p) {
        std::vector<int> mid;
        auto dfs = [&](auto dfs, treeNode *x) -> void {
            if (!x) return;
            dfs(dfs, x->l);
            mid.emplace_back(x->val);
            dfs(dfs, x->r);
        };
        dfs(dfs, p);
        Free(p->l), Free(p->r);
        // TODO build
    }
    void build(treeNode *p, size_t l, size_t r, std::vector<T> &x){
        // TODO
    };

public:
    Balanced_tree() {}
    Balanced_tree(std::vector<T> &x) {
        // TODO
    }
    Balanced_tree(T *begin, T *end) {
        // TODO
    }
    bool insert(T x) {
        if (!root) {
            root = (treeNode *)malloc(sizeof(treeNode));
            root->val = x;
            return true;
        } else {
            return Insert(x, root);
        }
    }
    bool erase(T x) {
        if (!root) {
            return false;
        } else {
            return Deletes(x, root);
        }
    }

    bool isExist(T x) {
        if (Find(x, root) != nullptr) {
            return true;
        } else {
            return false;
        }
    }
    T find(T x) {
        treeNode *p = Find(x, root);
        if (p) {
            return p->val;
        } else {
            return ERROR;
        }
    }
    T max() {
        // TODO
    }
    T min() {
        // TODO
    }
    T upper_bound(T x) {
        // TODO
    }
    T lower_bound(T x) {
        // TODO
    }
    void clear() {
        Free(root);
    }
    bool empty() {
        return size;
    }
    size_t size() {
        if (!root) return 0;
        return root->size;
    }
    int kth(T x) {
        treeNode *p = Find(x, root);
        if (!p) return ERROR;
        if (p->l) {
            return p->l->size + 1;
        } else {
            return 1;
        }
    }
    T indexof(size_t x) {
        // TODO
    }
    ~Balanced_tree() {
        Free(root);
    }
};
