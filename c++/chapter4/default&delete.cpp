#include<cstdio>
#include<iostream>
using namespace std;

class Mystr
{
    public:
        string s;

        Mystr()=default;//默认合成的无参构造函数

        Mystr(string _s): s(move(s)) {}//有参构造函数

        Mystr(Mystr &&str)=default;//默认合成的赋值构造函数
        // Mystr(Mystr &&str)=delete; //删除复制构造函数

        ~Mystr()=default;//默认合成的析构函数
};

int main()
{
    return 0;
}
