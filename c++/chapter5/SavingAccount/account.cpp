#include<cstdio>
#include<iostream>
#include"account.h"
using namespace std;

double SavingsAccount::total=0;

void SavingsAccount::record(int date,double amount)
{
    accumulation=accumulate(date);
    lastDate=date;
    balance+=amount;
    total+=amount;
    printf("%d\t#%d\t%lf\t%lf\n",date,id,amount,balance);
    return ;
}

SavingsAccount::SavingsAccount(int date,int id,double rate)
:lastDate(date),id(id),rate(rate),balance(0),accumulation(0)
{
    printf("%d\t#%d is created\n",date,id);
}

void SavingsAccount::deposit(int date,double amount)
{
    record(date,amount);
    return ;
}

void SavingsAccount::withdraw(int date,double amount)
{
    if(amount>getBalance())
        printf("Error:not enough money\n");
    else
        record(date,-amount);
    return ;
}

void SavingsAccount::settle(int date)
{
    double interest=accumulate(date)*rate/365;
    if(interest!=0)
        record(date,interest);
    accumulation=0;
    return ;
}

void SavingsAccount::show() const
{
    printf("#%d\tBalance:%lf",id,balance);
    return ;
}