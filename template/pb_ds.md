# 申明
```c++
template <typename T>
using set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>,
                             __gnu_pbds::rb_tree_tag,
                             __gnu_pbds::tree_order_statistics_node_update>;
template <typename T, typename Z>
using map = __gnu_pbds::tree<T, Z, std::less<T>,
                             __gnu_pbds::rb_tree_tag,
                             __gnu_pbds::tree_order_statistics_node_update>;
```
# 迭代器
```c++
decltype(rbt)::point_iterator ptr;
```
```c++
// 插入
mp.insert();

// 删除
mp.erase(mp.lower_bound());

//查询排名
mp.order_of_key();

// 查询位置上的值
rbt.find_by_order(); //返回迭代器


```

