1. vc2008 stl  在高版本vc下编译警告有点多
2. 所有异常直接KeBugCheck
3. 所有内存全部分配为nonpagedpool， 不要用这个代码去做低资源测试
4. kstring 为 wstring,unicodestring 混合体
5. lock 抄袭mfc clock
6. 测试环境， 用stlport 测试代码对整个库进行过完整的测试，没发现蓝屏
7. 编译环境已测试过：
	1. ddk 2600 for windows xp xp_x64
	2. wdk7600 for x86 x64
	3. win8.1  for x86 x64
	4. win10 for x86 x64
8. 作者英文不好，看不懂就找google  
[the Author's English is not good, if u do not understand then try to ask google]


