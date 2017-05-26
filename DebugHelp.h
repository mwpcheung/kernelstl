#pragma once

#define STRINGIZE(x) STRINGIZE2(x)
#define STRINGIZE2(x) #x
#define LINE_STRING STRINGIZE(__LINE__)
#define PrintPrefix "[luax] => " __FUNCTION__ "(" LINE_STRING "): "
//#define PrintPrefix "[luax]" 
#if DBG
#define DebugPrint(...) DbgPrint(PrintPrefix  __VA_ARGS__)
#else
#define DebugPrint(...) //DbgPrint(PrintPrefix  __VA_ARGS__)
#endif
