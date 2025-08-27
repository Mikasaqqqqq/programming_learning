#ifndef __POINT_H__
#define __POINT_H__
class Point
{
    public:
        Point(int xx=0,int yy=0): x(xx),y(yy) {count++;}
        Point(const Point &p);
        ~Point() {count--;}
        int getX() const {return x;}
        int getY() const {return y;}
        static void showCount();
    
    private:
        int x,y;
        static int count;
};
#endif