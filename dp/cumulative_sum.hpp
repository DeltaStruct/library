#ifndef DELTASTRUCT_LIBRARY_DP_CUMULATIVE_SUM
#define DELTASTRUCT_LIBRARY_DP_CUMULATIVE_SUM 1

#include <vector>

#include "../assets/range.hpp"
#include "../assets/concepts.hpp"
#include "../assets/undefined.hpp"

template<can_add_sub T>
struct cumulative_sum {
  using iterator = std::vector<T>::iterator;
  using const_iterator = std::vector<T>::const_iterator;
  std::vector<T> dp;
  cumulative_sum() : dp(1) {}
  cumulative_sum(std::size_t n) : dp(n+1) {}
  cumulative_sum(std::size_t n,T x) : dp(n+1,x) {}
  cumulative_sum(std::vector<T>& A) : dp(1) { for (T& a:A) dp.emplace_back(dp.back()+a); }
  T operator[](std::size_t x){ return dp[x+1]-dp[x]; }
  T operator[](range x){ return dp[x.r]-dp[x.l]; }
  T operator[](all_range x){ return dp.back(); }
  T& operator()(std::size_t x){ return dp[x]; }
  std::size_t size(){ return dp.size()-1; }
  iterator begin(){ return dp.begin(); }
  const_iterator begin() const { return dp.begin(); }
  iterator end(){ return dp.end(); }
  const_iterator end() const { return dp.end(); }
  T fold(std::size_t x){ return dp[x]; }
  T fold(std::size_t l,std::size_t r){ return dp[r]-dp[l]; }
  void reverse_csum(){ for (int i(dp.size()-1);i;--i) dp[i] = dp[i]-dp[i-1]; }
  [[risky_operation]]
  void change(std::size_t x,T y){ dp[x] = y; }
  void build(){ for (int i(1);i < (int)dp.size();++i) dp[i] = dp[i]+dp[i-1]; }
  void build(std::vector<T>& A){
    dp.resize(A.size()+1);
    for (int i(1);i < (int)dp.size();++i) dp[i] = A[i-1]+dp[i-1];
  }
};

template<can_add T>
struct cumulative_sum {
  using iterator = std::vector<T>::iterator;
  using const_iterator = std::vector<T>::const_iterator;
  std::vector<T> dp,val;
  cumulative_sum() : dp(1),val() {}
  cumulative_sum(std::size_t n) : dp(n+1),val() {}
  cumulative_sum(std::size_t n,T x) : dp(n+1,x),val(n,x) {}
  cumulative_sum(std::vector<T>& A) : dp(1),val(A) { for (T& a:A) dp.emplace_back(dp.back()+a); }
  T operator[](std::size_t x){ return A[x]; }
  unable_operation(T,operator[],range)
  T operator[](all_range x){ return dp.back(); }
  T& operator()(std::size_t x){ return dp[x]; }
  std::size_t size(){ return dp.size()-1; }
  iterator begin(){ return dp.begin(); }
  const_iterator begin() const { return dp.begin(); }
  iterator end(){ return dp.end(); }
  const_iterator end() const { return dp.end(); }
  T fold(std::size_t x){ return dp[x]; }
  unable_operation(T,fold,std::size_t,std::size_t)
  unable_operation(void,reverse_csum)
  [[risky_operation]]
  void change(std::size_t x,T y){ dp[x] = y; }
  void change_val(std::size_t x,T y){ val[x] = y; }
  void build(){ for (int i(1);i < (int)dp.size();++i) dp[i] = dp[i]+dp[i-1]; }
  void build_val(){ for (int i(1);i < (int)dp.size();++i) dp[i] = val[i-1]+dp[i-1]; }
  void build(std::vector<T>& A){
    dp.resize(A.size()+1);
    for (int i(1);i < (int)dp.size();++i) dp[i] = A[i-1]+dp[i-1];
  }
};

template<typename T>
using csum = cumulative_sum<T>;

#endif