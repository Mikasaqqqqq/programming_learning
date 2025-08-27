#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

/*
常对象、常成员函数
*/
class R
{
    public:
        R(int _r1,int _r2):r1(_r1),r2(_r2) {}
        void print();
        void print() const;//常成员函数
    
    private:
        int r1,r2;
};

void R::print()
{
    printf("%d:%d\n",r1,r2);
    return ;
}

void R::print() const
{
    printf("%d:%d\n",r1,r2);
    return ;
}

/*
常数据成员
*/
class A
{
    public:
        A(int i);
        void print();

    private:
        const int a;
        static const int b; //静态常数据成员
};

const int A::b=10;

//常数据成员只能通过初始化列表来获得初值
A::A(int i): a(i) {}

void A::print()
{
    printf("%d:%d\n",a,b);
    return ;
}

/*
常引用
*/
class Point
{
    public:
        Point(int xx=0,int yy=0): x(xx),y(yy) {}
        int getX() {return x;}
        int getY() {return y;}
        friend float dist(const Point &p1,const Point &p2);
    
    private:
        int x,y;
};

float dist(const Point &p1,const Point &p2)
{
    double x=p1.x-p2.x;
    double y=p1.y-p2.y;
    return static_cast<float>(sqrt(x*x+y*y));
}

int main()
{
    R a(5,4);
    a.print();          // 调用 void print()
    const R b(20,52);   // 常对象
    b.print();          //调用 void print() const
    
    A a1(100),a2(0);
    a1.print();
    a2.print();

    const Point myp1(1,1),myp2(4,5);
    printf("The distance is:");
    printf("%.2f\n",dist(myp1,myp2));
    return 0;
}