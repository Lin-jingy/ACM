#include <bits/stdc++.h>

template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
	    typename _Alloc = std::allocator<std::pair<const _Key, _Tp> > >
class map : public std::map<_Key, _Tp, _Compare, _Alloc> {

};
