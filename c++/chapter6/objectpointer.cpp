#include<cstdio>
#include<iostream>
using namespace std;

/*
object pointer
*/

class Point;
class Barney
{
    Point *x;
//! Point x; 
};

class Point
{
    public:
        Point(const int _x=0,const int _y=0):x(_x),y(_y) 
        {
            count++;
        }
        Point(const Point &p):x(p.x),y(p.y)
        {
            count++;
        }
        int getX()const {return x;}
        int getY()const {return y;}
        void change(const int x,const int y);
        static void showCount()
        {
            printf("PointCount=%d",count);
            return ;
        }

        static int count;

    private:
        int x,y;
};

/*
this 指针
*/
void Point::change(const int x,const int y)
{
    this->x=x;
    this->y=y;
    return ;
}

int Point::count=0;

int main()
{
    Point a(4,5);
    Point *p1=&a;
    int (Point::*funcPtrt)()const=&Point::getX;

    cout<<(a.*funcPtrt)()<<endl;
    cout<<(p1->*funcPtrt)()<<endl;
    cout<<a.getX()<<endl;
    cout<<p1->getX()<<endl;

    /*
    指针访问类的静态成员
    */
    int *ptr=&Point::count;
    void (*fptr)()=Point::showCount;
    printf("PointCount=%d\n",*ptr);
    fptr();
    return 0;
}