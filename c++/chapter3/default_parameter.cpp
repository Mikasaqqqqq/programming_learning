#include<cstdio>
#include<iostream>
using namespace std;

int max(int a,int b=0,int c=0);

int main()
{
    int a=3,b=5,c=2;
    printf("%d\n",max(a)); // 3
    printf("%d\n",max(a,b)); // 5
    printf("%d\n",max(a,b,c)); // 5
    return 0;
}

int max(int a,int b /*=0*/,int c/*=0*/)
{
    return max(a,max(b,c));
}
// 函数声明时指定默认参数，函数定义时不再指定
// 默认参数从右向左依次指定
// 函数调用时可以省略默认参数