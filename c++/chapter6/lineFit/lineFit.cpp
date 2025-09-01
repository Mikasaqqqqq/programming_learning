#include<cstdio>
#include<iostream>
#include<cmath>
#include"point.h"
using namespace std;

float lineFit(const Point points[],const int nPoint)
{
    float avgX=0,avgY=0;
    float lxx=0,lyy=0,lxy=0;
    for(int i=0;i<nPoint;i++)
    {
        avgX+=points[i].getX();
        avgY+=points[i].getY();
    }
    avgX/=nPoint;avgY/=nPoint;
    for(int i=0;i<nPoint;i++)
    {
        lxx+=(points[i].getX()-avgX)*(points[i].getX()-avgX);
        lyy+=(points[i].getY()-avgY)*(points[i].getY()-avgY);
        lxy+=(points[i].getX()-avgX)*(points[i].getY()-avgY);
    }
    cout<<"This line can be fitted by y=ax+b."<<endl;
    cout<<"a="<<lxy/lxx<<" ";               //输出回归系数 a
    cout<<"b="<<avgY-lxy*avgX/lxx<<endl;    //输出回归系数b
    return static_cast<float>(lxy/sqrt(lxx*lyy));
}

int main()
{
    Point p[10]={Point(6,10),Point(14,20),Point(26,30),Point(33,40),
                 Point(46,50),Point(54,60),Point(67,70),Point(75,80),
                 Point(84,90),Point(100,100)};  //初始化数据点
    float r=lineFit(p,10);  //进行线性回归计算
    cout<<"Line coefficient r="<<r<<endl;   //输出相关系数
    return 0;
}