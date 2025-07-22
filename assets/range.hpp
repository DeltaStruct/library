#ifndef DELTASTRUCT_LIBRARY_ASSETS_RANGE
#define DELTASTRUCT_LIBRARY_ASSETS_RANGE 1

#include "concepts.hpp"
#include "undefined.hpp"

template<is_iterator T>
struct [[class_undefined(C++23?)]] iterator_range {
  T l,r;
};

template<is_integer T>
struct range {
  T l,r;
  template<can_get_begin_end_iterator U>
  [[function_undefined(C++23?)]]
  auto operator()(U& x) -> iterator_range<decltype(std::begin(x))> {
    return iterator_range<decltype(std::begin(x))>{std::begin(x),std::end(x)};
  }
};

struct all_range {};

#define _OVERLOAD(a1,a2,a3,macro,...) macro
#define _2(l,r) (range{l,r})
#define _0() (all_range{})
#define _1(A) std::begin(A),std::end(A)
#define _3(A,l,r) (std::begin(A)+l),(std::begin(A)+r)
#define _(...) _OVERLOAD(__VA_ARGS__,_3,_2,_1,_0)(__VA_ARGS__)
//#define _ (all_range{})

#endif