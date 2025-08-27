#include<cstdio>
using namespace std;

int main()
{
    // 引用
    int a = 10,q=100;
    int &b = a; // b是a的引用
    b = 20;     // 通过b修改a
    printf("a = %d\n", a); // 输出a的值
    /*
    error case:
    b = &q; // 引用不能被重新赋值
    int &c; // 引用必须初始化
    int &d = 10; // 引用必须引用一个变量，不能是字面值
    int &e = b + 1; // 引用必须引用一个变量，不能是表达式
    */
    return 0;
}