#ifndef __POINT_H__
#define __POINT_H__
class Point
{
    public:
        Point(float _x=0,float _y=0):x(_x),y(_y) {}
        float getX() const {return x;}
        float getY() const {return y;}
        
    private:
        float x,y;
}; 
#endif