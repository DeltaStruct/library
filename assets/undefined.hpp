#ifndef DELTASTRUCT_LIBRARY_ASSETS_UNDEFINED
#define DELTASTRUCT_LIBRARY_ASSETS_UNDEFINED 1

#include <iostream>

#define class_undefined(additional) depracted("This class hasn't been implemented yet." #additional)
#define function_undefined(additional) depracted("This function hasn't been implemented yet." #additional)
#define unable_operation(type,name,...) [[depracted("This function is unable operation.")]] [[noreturn]] \
type name(__VA_ARGS__){ \
    std::cerr << #type << ' ' << #name << '(' << #__VA_ARGS__ << ") is unable operation." << std::endl; \
    std::exit(1); \
}
#define risky_operation depracted("This function is risky. Do you understand it?")
#define unnecessary_operation depracted("This function is unnecessary.")

#endif