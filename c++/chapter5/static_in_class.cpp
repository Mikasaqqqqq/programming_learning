#include<cstdio>
#include<iostream>
using namespace std;

class Point
{
    public:
        Point(int xx=0,int yy=0):x(xx),y(yy) 
        { 
            count++; 
        } // 构造函数

        Point(const Point &p):x(p.x),y(p.y) 
        { 
            count++; 
        } // 复制构造函数

        ~Point() 
        { 
            count--; 
        } // 析构函数

        int getX() const { return x; }
        int getY() const { return y; }
        static void showCount() //静态成员函数
        { 
            printf("Object count=%d\n",count);
            return ;
        }
        /*
        void showCount() const 
        { 
            printf("Object count=%d\n",count);
            return ;
        }
        */
        

    private:
        static int count; // 静态数据成员声明
        constexpr static int origin=0; // 常量静态变量类内初始化
        int x,y;
};

int Point::count=0; // 静态数据成员定义与初始化
constexpr int Point::origin; // 常量静态变量类外定义

int main()
{
    Point a(4,5);
    printf("Point A:(%d,%d) ",a.getX(),a.getY());
    Point::showCount();
    //a.showCount();

    Point b(a);
    printf("Point B:(%d,%d) ",b.getX(),b.getY());
    Point::showCount();   
    //b.showCount();

    return 0;
}