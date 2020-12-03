# a common issue about fork() and printf()
# 为什么会这样？从一个小程序谈unistd下的fork()和printf()

今天课上，老师提出了这样一个问题：

```
#include <stdio.h>
#include <unistd.h>
int main()
{
    int i;
    for(i=0;i<2;i++)
    {
        fork();
        printf("=");
    }
    return 0;
}
```

这个程序运行结束会输出几个等号？

我们知道，fork()函数的工作原理可以简单认为是：当一个进程调用fork()函数后，系统先给新的进程分配资源，例如存储数据和代码的空间。然后把原来的进程的所有值都复制到新的新进程中，只有少数值与原来的进程的值不同。相当于克隆了一个自己。

根据这个思路，我们可以画图分析以下程序运行的过程：
```mermaid
    graph td
    A --> B
```