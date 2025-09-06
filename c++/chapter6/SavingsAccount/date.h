#ifndef __DATE_H__
#define __DATE_H__
class Date
{
    private:
        int year;
        int month;
        int day;
        int totaldays;
    public:
        Date(int year,int month,int date);
        int getYear() const {return year;}
        int getMonth() const {return month;}
        int getDay() const {return day;}
        int getMaxDay() const;
        bool isLeapYear() const
        {
            return year%400==0||(year%4==0&&year%100!=0);
        }
        void show() const;
        int distance(const Date &date) const
        {
            return totaldays-date.totaldays;
        }
};
#endif