#pragma once
/*
	vc 2008 stl for edr driver frame work
	 by 
		mwpcheung@gmail.com
	对原始文件做了大量修改，修改的地方有
	1. c++ throw 直接被放弃，编写代码时需格外小心
	2. c++ try catach 并没很好的实现，而是直接放弃。 编写代码需要注意
	3. cstdlib 中所有c运行时函数直接丢掉.
	4. 浮点数暂时没被加入
	5. stl 默认的string 引用关系特别复杂，没有用string模块，而用了其父类basic_string<T>, 没实现compare方法
		导致std::map的时候string不能作为key使用
	6. vc2008 stl vector本身没有实现深度拷贝函数，比如vector的元素是vector 在push 一个vector时，不会被深度拷贝。这是一个vc的bug
	7. list 暂不存在该问题。
*/


#if (_DEBUG | NODEBUG)
#else
#if (_MSC_VER < 1600 )  // vc2010 以前
#define dllimport
#include "vcstl/sal.h"
#include "vcstl/xstring"
#include "vcstl/vector"
#include "vcstl/list"
#include "vcstl/map"
#include "stdint.h"
#else
#include "vcstl/xstring"
#include "vcstl/vector"
#include "vcstl/list"
#include "vcstl/map"
#include "stdint.h"
#endif
#endif
