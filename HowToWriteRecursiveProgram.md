# How To Write Recurisive Program
## --A easier way to solve problems

# 递归程序编写指南

---
今天上课老师传授了个写递归函数的「秘诀」据说使用这个方法能够秒杀本科生阶段和研究生阶段的所有递归算法。是真的吗？我们一起来~~比划比划~~学习一下下~
老师强调我们要边写程序边体会其中的「奥义」，那么就让我们试试吧！

### 以[汉诺塔问题](https://en.wikipedia.org/wiki/Tower_of_Hanoi)求解为例


1. 写递归函数名
    把函数的函数名写出来，俗话说万事开头难嘛
    ```
    void hanno()
    ```

2. 写形参
    形参分为两类：『表示问题规模的参数』、『表示功能的参数』。
    表示问题规模的参数是问题规模的直接表示，而表示功能的参数驱使程序执行不同的功能以完成任务。

    这个问题的形参如下所示：
    ```
    void hanno(int n,Tower T1,Tower T2,Tower T3)
    ```
    其中，n是『表示问题规模的参数』，代表要移动圆盘的层数；T1,T2,T3是『表示功能的参数』，分别代表源位置、目的位置、辅助盘位置。

3. 认为函数已经完成
    严肃！当写完函数名和形参后，一定要认为函数已经构造完成，并且可以在程序中进行调用。这么想的目的是方便分析问题，在函数的具体构造中使用递归的思想。
    调用的时候要确保原问题规模变小而且功能相同。

4. 写递归终止条件
    递归方法求解问题的思路与「数学归纳法」有些类似，我们在具体解决问题的时候都要首先注意特殊情况下的结果。
    递归终止条件由问题规模决定，例如，当问题规模足够小我们可以很方便的解决的时候递归就可以终止。
    这个问题的递归终止条件如下所示：
    ```
    if(n==1)
    {
        cout<<"move plate"<<" from "<<T1<<" to "<<T2<<endl;
        return;
    }
    ```
    也就是说，当只需要挪动一个圆盘到目的地的时候，我们便可以终止递归过程，一步挪动就可以解决问题。

5. 写递归过程
    其实就是写一般情况下该怎么做。采用整体的思想我们不难想出，当有n个圆盘需要移动的时候，可以先把上面的n-1个圆盘作为一个整体移动到辅助盘上，再把最下面的圆盘移动到目的地上。
    代码如下所示：
    ```
    else
    {
        hanno(n-1,T1,T3,T2);
        hanno(n-1,T3,T2,T1);
    }
    ```

### 分析与探索
经过实践，这个方法对我来说能够很有效的规范思路，易于写出有效的递归程序。
当然，要想能得心应手的写出「递归终止条件」和「递归过程」，我们最好提前列出需要求解问题的「通项公式」，例如在汉诺塔问题中，把圆柱B作为缓冲，从圆柱A移动n个圆盘到C的「通项公式」是：
```
n=1:把圆盘从A移动到C
n>1:先把最上面的前n-1个圆盘移动到B，再把最下面的圆盘从A移动到C，最后把B上的圆盘移动到C
```

## 拓展
使用这个方法，我求解了一些常见的递归问题。

1. [斐波那契数列](https://en.wikipedia.org/wiki/Fibonacci_number)问题
2. 汉诺塔问题
3. 生成二叉树问题
    已知二叉树的前序、中序遍历序列，求二叉树。

    例如：
        已知前序遍历：ABDHIEJKCFLMGNO
        中序遍历：HDIBJEKALFMCNGO
    可以求得二叉树如下所示：
    ![BinaryTree](/assets/create_Tree.png)


代码如下所示：

```
#include <bits/stdc++.h>
using namespace std;
    enum Tower{A=1,B,C};
    typedef char Value;
    typedef struct tree{
            Value value;
            struct tree* l_child;
            struct tree* r_child;
        }Tree;

    void print(Tree* T,int hirachy=0){
                if(T==NULL)
                    return;
                if(hirachy>0)
                    cout<<setfill('-')<<setw(hirachy+1)<<(*T).value<<endl;
                else
                    cout<<(*T).value<<endl;
                
                print((*T).l_child,hirachy+1);
                print((*T).r_child,hirachy+1);
            };
class Recursive{
    public:
        int fibo(int n)
        {
            if(n==1 or n==2)
                return 1;
            else
            {
                return fibo(n-1)+fibo(n-2);
            }   
        }

        void hanno(int n,Tower T1,Tower T2,Tower T3)
        {
            if(n==1)
                {cout<<"move plate"<<" from "<<
                T1<<" to "<<T2<<endl;
                return;}
            else
            {
                hanno(n-1,T1,T3,T2);
                hanno(n-1,T3,T2,T1);
            }
        }

        void createBT(Tree* Root,
        const string& preorder,const string& inorder,
        int pl,int pr,int il,int ir)
        {
            if(Root==NULL)
                return;
            if(pl==pr and il==ir)
            {
                (*Root).value=preorder[pl];
                (*Root).l_child=NULL;
                (*Root).r_child=NULL;
            }
            else
            {
                int position=inorder.find(preorder[pl]);
                (*Root).value=preorder[pl];

                Tree *s=(Tree*)malloc(sizeof(Tree));
                (*Root).l_child=s;
                Tree* p=(Tree*)malloc(sizeof(Tree));
                (*Root).r_child=p;

                if(pl+1>pl+position-il or il>position-1)
                {
                    (*Root).l_child=NULL;free(s);
                    createBT(p,preorder,inorder,pl+position-il+1,pr,position+1,ir);
                    return;
                }
                if(pl+position-il+1>pr or position+1>ir)
                {
                    (*Root).r_child=NULL;free(p);
                    createBT(s,preorder,inorder,pl+1,pl+position-il,il,position-1);
                    return;
                }

                createBT(s,preorder,inorder,pl+1,pl+position-il,il,position-1);
                createBT(p,preorder,inorder,pl+position-il+1,pr,position+1,ir);
            }
        };
};
int main()
{
    Recursive r;
    cout<<r.fibo(3)<<endl;
    r.hanno(5,A,B,C);
    Tree a;
    string pre="ABDHIEJKCFLMGNO";
    string inr="HDIBJEKALFMCNGO";
    r.createBT(&a,pre,inr,0,pre.size()-1,0,inr.size()-1);
    print(&a);
}
```