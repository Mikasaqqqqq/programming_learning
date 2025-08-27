#include"Point.h"
#include<iostream>
using namespace std;

int main()
{
    Point a(4,5);
    printf("Point A: %d, %d\n",a.getX(),a.getY());
    Point::showCount();

    Point b(a);
    printf("Point B: %d, %d\n",b.getX(),b.getY());
    Point::showCount();

    return 0;
}