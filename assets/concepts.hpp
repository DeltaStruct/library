#pragma once
#include <concepts>
#include <iterator>

template<typename T>
concept is_iterator = std::input_or_output_iterator<T>;

template<typename T>
concept can_call_begin = requires(T& x){ begin(x); };
template<typename T>
concept can_call_end = requires(T& x){ end(x); };
template<typename T>
concept can_get_begin = requires(T& x){ {begin(x)} -> is_iterator; };

template<typename T>
concept is_integer = std::integral<T>;
template<typename T>
concept can_add_sub = requires(T& x,T& y){ x + y; x - y; x = y; };
template<typename T>
concept can_add = requires(T& x,T& y){ x + y; x = y; };