#include"date.h"
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
namespace
{
    const int DAYS_BEFORE_MONTH[]={0,31,59,90,120,151,181,
    212,243,273,304,334,365};
} // namespace

Date::Date(int year,int month,int day):year(year),month(month),day(day)
{
    if(day<=0||day>getMaxDay())
    {
        cout<<"Invalid date:";
        show();
        cout<<endl;
        exit(1);
    }
    int _year=year-1;
    totaldays=_year*365+_year/4-_year/100+_year/400+DAYS_BEFORE_MONTH[month-1]+day;
    if(isLeapYear()&&month>2) totaldays++;
}

int Date::getMaxDay() const
{
    if(isLeapYear()&&month==2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month]-DAYS_BEFORE_MONTH[month-1];
}

void Date::show() const
{
    cout<<year<<"-"<<month<<"-"<<day;
    return ;
}