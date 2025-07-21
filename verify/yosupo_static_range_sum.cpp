// PROBLEM https://judge.yosupo.jp/problem/static_range_sum

#include "../dp/cumulative_sum.hpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q; cin >> n >> q; vector<long long> A(n); for (long long& a:A) cin >> a;
  csum acc(A);
  while(q--){
    int l,r; cin >> l >> r; cout << acc[_(l,r)] << endl;
  }
}