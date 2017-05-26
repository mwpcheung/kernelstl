1. vc2008 stl  在高版本vc下编译警告有点多
2. 所有异常直接KeBugCheck
3. 所有内存全部分配为nonpagedpool， 不要用这个代码去做低资源测试
4. kstring 为 wstring,unicodestring 混合体
5. lock 抄袭mfc clock



