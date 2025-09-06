#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include"date.h"
#include<string>

class SavingsAccount
{
    private:
        std::string id;
        double balance;
        double rate;
        Date lastDate;
        double accumulation;
        static double total;
        void record(const Date date,double amount,const std::string &desc);
        void error(const std::string &msg) const;
        double accmulate(const Date &date) const
        {
            return accumulation+date.distance(lastDate)*balance;
        }
    public:
        SavingsAccount(const Date &date,const std::string &id,double rate);
        std::string getId() const {return id;}
        double getBalance() const {return balance;}
        double getRate() const {return rate;}
        void show() const;
        void deposit(const Date &date,double amount,const std::string &desc);
        void withdraw(const Date &date,double amount,const std::string &desc);
        void settle(const Date &date);
        static double getTotal() {return total;}
};
#endif