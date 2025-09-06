#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include"point.h"
class Rectangle: private Point
{
    private:
        float w,h;
    public:
        void initRectangle(const float x,const float y,const float w,const float h)
        {
            initPoint(x,y);
            this->w=w;
            this->h=h;
            return ;
        }
        void move(const float offX,const float offY) {return Point::move(offX,offY);}
        float getX()const {return Point::getX();}
        float getY()const {return Point::getY();}
        float getH()const {return h;}
        float getW()const {return w;}
};
#endif