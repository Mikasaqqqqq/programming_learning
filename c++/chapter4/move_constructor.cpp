#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

class Mystr
{
    public:
        string s;

        Mystr(): s(""){}// 无参构造函数

        Mystr(string _s): s(move(_s)) {}// 有参构造函数

        Mystr(Mystr &&str) noexcept// 告知编译器不会抛出异常
            : s(move(str.s)) {}// 移动构造函数
};

int main()
{
    float n=6;
    float &lr_n=n;//对变量n的左值引用
    // float &&rr_n=n;
    float &&rr_n=n*n;//将乘法结果的右值绑定到右值应用
    // float &lr_n=n*n;
    float m=6;
    float &&rr_m=move(m); //将左值对象移动为右值并绑定右值引用
    return 0;
}