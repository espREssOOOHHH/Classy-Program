/*程序功能：
功能要求：创建两个子线程:
thread1:每打印一个数字，中间间隔一秒,循环打印数字0—100
thread2:响应键盘，从键盘输入一个字符，如果这个字符不等于‘x’，
        那么thread1正常运行 ，如果这个字符刚好等于‘x’，
        则两个线程都结束并退出程序。
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int exit_=0;

void *PrintDigit(void)
{
    int a=0;
    while(!exit_)
    {
        printf("%d\n",a++);
        sleep(1);
    }
    pthread_exit(0);
}
void *Keaboard(void)
{
    char a='s';
    system("stty -icanon");//关闭缓冲区
    while(a!='x')
        a=getchar();
    exit_=1;
    pthread_exit(0);
}
int main()
{
    printf("hello!\n");
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,PrintDigit,NULL);
    pthread_create(&thread2,NULL,Keaboard,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("\nbye~\n");
}
