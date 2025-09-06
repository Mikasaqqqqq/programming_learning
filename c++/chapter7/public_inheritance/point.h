#ifndef __POINT_H__
#define __POINT_H__
class Point
{
    private:
        float x,y;
    public:
        void initPoint(const float x,const float y)
        {
            this->x=x;
            this->y=y;
            return ;
        }
        void move(const float offX,const float offY)
        {
            x+=offX;
            y+=offY;
            return ;
        }
        float getX()const {return x;}
        float getY()const {return y;}
};
#endif