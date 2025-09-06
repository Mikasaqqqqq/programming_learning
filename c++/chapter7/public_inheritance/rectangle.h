#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include"point.h"
class Rectangle: public Point
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
        float getH()const {return h;}
        float getW()const {return w;}
};
#endif