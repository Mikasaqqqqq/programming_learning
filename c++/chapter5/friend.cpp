#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

/*
friend function
*/
class Point
{
    public:
        Point(int xx=0,int yy=0):x(xx),y(yy) {}
        int getX() const {return x;}
        int getY() const {return y;}
        friend float dist(Point &p1,Point &p2);
    
    private:
        int x,y;
};

float dist(Point &p1,Point &p2)
{
    double x=p1.x-p2.x;
    double y=p1.y-p2.y;
    return static_cast<float>(sqrt(x*x+y*y));
}

/*
friend class
*/

class A
{
    public:
        void show()
        {
            printf("%d\n",x);
            return ;
        }

        int getX() {return x;}
        friend class B;// //B类是A类的友元类

    private:
        int x;
};

class B
{
    public:
        void set(int i);
    
    private:
        A a;
};

void B::set(int i)
{
    a.x=i; //由于B是A的友元，所以在B的成员函数中可以访问A类对象的私有成员
    return ;
}

int main()
{
    Point myp1(1,1),myp2(4,5);
    cout<<"The distance is:";
    cout<<dist(myp1,myp2)<<endl;    
    return 0;
}