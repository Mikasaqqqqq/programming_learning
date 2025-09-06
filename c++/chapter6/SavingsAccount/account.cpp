#include"account.h"
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

SavingsAccount::SavingsAccount(const Date &date,const std::string &id,double rate)
:id(id),balance(0),rate(rate),lastDate(date),accumulation(0)
{
    date.show();
    cout<<"\t#"<<id<<" created"<<endl;
}

void SavingsAccount::record(const Date date,double amount,const std::string &desc)
{
    accumulation=accmulate(date);
    lastDate=date;
    amount=floor(amount*100+0.5)/100;
    balance+=amount;
    total+=amount;
    date.show();
    cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
    return ;
}

void SavingsAccount::error(const std::string &msg) const
{
    cout<<"Error(#"<<id<<")"<<msg<<endl;
    return ;
}

void SavingsAccount::deposit(const Date &date,double amount,const std::string &desc)
{
    record(date,amount,desc);
    return ;
}

void SavingsAccount::withdraw(const Date &date,double amount,const std::string &desc)
{
    if(amount>getBalance())
        error("not enough money");
    else 
        record(date,-amount,desc);
    return ;
}

void SavingsAccount::settle(const Date &date)
{
    double interest=accmulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));
    if(interest!=0)
        record(date,interest,"interest");
    accumulation=0;
    return ;
}

void SavingsAccount::show() const
{
    cout<<id<<"\tBalance:"<<balance;
    return ;
}

double SavingsAccount::total=0;