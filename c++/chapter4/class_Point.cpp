#include<cstdio>
#include<iostream>
using namespace std;

class Point 
{
    public:
        Point(int xx=0,int yy=0)
        {
            x=xx;
            y=yy;
        }

        Point(Point &p);// 显式

        int Get_x()
        {
            return x;
        }

        int Get_y()
        {
            return y;
        }

    private:
        int x,y;
};

Point::Point(Point &p)
{
    x=p.x;
    y=p.y;
    printf("Calling the copy constructor\n");
}

void fun1(Point p)// 传值，调用了复制构造函数
{
    printf("%d\n",p.Get_x());
    return ;
}

Point fun2()
{
    Point a(1,2);
    return a;// 可能被编译器优化
}

int main()
{
    Point a(4,5);
    Point b=a;
    printf("%d\n",b.Get_x());
    fun1(b);
    b=fun2();
    printf("%d\n",b.Get_x());
    return 0;
}