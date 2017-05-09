# datastruct_kernel
Learn some datastruct from kernel

####1. offsetof_macro.c
今天学习到了两个强大的宏. 
offsetof用来判断结构体成员的偏移位置.
container_of宏用来根据成员的地址来获取结构体的地址。两个宏设计的很巧妙，值得学习。同时linux内核中也有这两个宏的定义

####2. dulinklist.c
从Linux内核中提取出来的双向循环链表,简单应用.


####3. rm_node_linklist.c
二级指针删除单链表(different from the text book)
