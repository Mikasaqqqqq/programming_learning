#include"rectangle.h"
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    Rectangle rect;
    rect.initRectangle(2,3,20,10);
    rect.move(3,2);
    cout<<"The data of rece(x,y,w,h):"<<endl;
    cout<<rect.getX()<<","
        <<rect.getY()<<","
        <<rect.getW()<<","
        <<rect.getH()<<endl;
    return 0;
}