#include<cstdio>
using namespace std;

class Clock
{
    public://公有类型 外部接口
        Clock();//默认构造函数
        Clock(int newH,int newM,int newS);//构造函数
        Clock(Clock &c);//复制构造函数
        void setTime(int newH,int newM,int newS);
        void showTime();
        ~Clock() {}//析构函数

    // protected://保护型成员

    private://私有成员
        int hour,minutes,second;
        // int hour{0},minutes{0},second{0};

};

Clock::Clock():hour(0),minutes(0),second(0){ 
}
/*
// 委托构造函数
Clock::Clock():Clock(0,0,0){
}
*/

Clock::Clock(int newH,int newM,int newS):hour(newH),minutes(newM),second(newS){
}

Clock::Clock(Clock &c)
{
    hour=c.hour;
    minutes=c.minutes;
    second=c.second;
}

void Clock::setTime(int newH,int newM,int newS)
{
    hour=newH;
    minutes=newM;
    second=newS;
    return ;
}

inline void Clock::showTime()// inline function
{
    printf("Time: %02d:%02d:%02d\n",hour,minutes,second);
    return ;
}

int main()
{
    Clock myClock1(1,2,3);
    myClock1.showTime();
    myClock1.setTime(9,18,23);
    myClock1.showTime();
    Clock myClock2;
    myClock2.showTime();
    Clock myClock3(myClock1);
    Clock myClock4=myClock1;
    myClock3.showTime();
    return 0;
}