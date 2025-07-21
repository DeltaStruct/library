#ifndef DELTASTRUCT_LIBRARY_ASSETS_CONCEPTS
#define DELTASTRUCT_LIBRARY_ASSETS_CONCEPTS 1

#include <concepts>
#include <iterator>

template<typename T>
concept is_iterator = std::input_or_output_iterator<T>;

template<typename T>
concept can_call_begin = requires(T& x){ std::begin(x); };
template<typename T>
concept can_call_end = requires(T& x){ std::end(x); };
template<typename T>
concept can_get_begin_iterator = requires(T& x){ {std::begin(x)} -> is_iterator; };
template<typename T>
concept can_get_end_iterator = requires(T& x){ {std::end(x)} -> is_iterator; };
template<typename T>
concept can_get_begin_end_iterator = can_get_begin_iterator<T>&&can_get_end_iterator<T>;

template<typename T>
concept is_integer = std::integral<T>;
template<typename T>
concept can_add_sub = requires(T& x,T& y){ x + y; x - y; x = y; };
template<typename T>
concept can_add = requires(T& x,T& y){ x + y; x = y; };

#endif