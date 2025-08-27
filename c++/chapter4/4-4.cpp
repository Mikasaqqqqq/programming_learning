#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    public:
        Point(double _x=0,double _y=0):x(_x),y(_y) {}

        Point(const Point &p):x(p.x),y(p.y) {}

        double getX() const 
        {
            return x; 
        }
        
        double getY() const 
        {
            return y; 
        }
    
    private:
        double x,y;
};

class Line
{
    public:
        Line(const Point &_p1,const Point &_p2);
        Line(const Line &l);

        double getLen() const 
        {
            return len; 
        }
        
    private:
        Point p1,p2;
        double len;
};

Line::Line(const Point &_p1,const Point &_p2):p1(_p1),p2(_p2)
{
    len=sqrt(pow(p1.getX()-p2.getX(),2)+pow(p1.getY()-p2.getY(),2));
}

Line::Line(const Line &l):p1(l.p1),p2(l.p2),len(l.len) {}

int main()
{
    Point p1(1,2),p2(4,6);
    Line line(p1,p2);
    Line line2(line);
    printf("Length of line is: %lf\n",line.getLen());
    printf("Length of line2 is: %lf\n",line2.getLen());
    return 0;
}