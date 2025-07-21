#include "concepts.hpp"
#include "undefined.hpp"

template<is_iterator T>
struct [[class_undefined(C++23?)]] iterator_range {
  T l,r;
};

template<is_integer T>
struct range {
  T l,r;
  [[function_undefined(C++23?)]]
  template<can_get_begin_end_iterator T>
  auto operator()(T& x) -> iterator_range<decltype(begin(T))> {
    return iterator_range<decltype(begin(T))>{x.begin(),x.end()};
  }
};

struct all_range {};

#define _OVERLOAD(a1,a2,a3,macro,...) macro
#define _2(l,r) (range_object{l,r})
#define _0() (all_range{})
#define _1(A) begin(A),end(A)
#define _3(A,l,r) (begin(A)+l),(begin(A)+r)
#define _(...) _OVERLOAD()(__VA_ARGS__,_3,_2,_1,_0)(__VA_ARGS__)
#define _ (all_range{})