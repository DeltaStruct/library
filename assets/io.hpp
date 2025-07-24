#ifndef DELTASTRUCT_LIBRARY_ASSETS_IO
#define DELTASTRUCT_LIBRARY_ASSETS_IO 1

#include <iostream>
#include <string>
#include <iomanip>

struct stdio_control {
  stdio_control(){ std::ios::sync_with_stdio(false),std::cin.tie(0); }
  void sync_with_stdio(bool b = true){ std::ios::sync_with_stdio(b); }
  void tie(bool b = true){ std::cin.tie(b?&std::cout:nullptr); }
  void fast(bool b = true){ sync_with_stdio(!b),tie(!b); }
  void debug(bool b = true){ fast(!b); }
  void floating(int x){ std::cout << std::fixed << std::setprecision(x); }
  void flush(){ std::cout.flush(); }
  std::string yn(bool b){ return (b?"Yes":"No"); }
} stdio;

std::string yn(bool b){ return (b?"Yes":"No"); }

#endif