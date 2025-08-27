#include<cstdio>
using namespace std;

// 常量表达式
// 关键字 constexpt 与 constexpr 函数

constexpr int block_size()
{
    return 20;
}

constexpr int len(int a)
{
    return a*block_size();
}

int main()
{
    constexpr int size=len(2);
    /*
    error:
    int i=2;
    constexpr int _size=len(i);    
    */
    return 0;
}