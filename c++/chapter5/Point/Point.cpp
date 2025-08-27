#include"Point.h"
#include<iostream>
using namespace std;

int Point::count=0;

Point::Point(const Point &p): x(p.x),y(p.y)
{
    count++;
}

void Point::showCount()
{
    printf("Object count=%d\n",count);
    return ;
}