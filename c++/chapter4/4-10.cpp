#include<cstdio>
#include<iostream>
using namespace std;

const int YEAR_DAY=365;

class SavingAccount
{
    public:
        //构造函数
        SavingAccount(const int date,const int _id,const double _rate);
        int getId(){ return id; }
        double getBalance(){ return balance; }
        double getRate(){ return rate; }
        void show();                            //展示账户信息
        void deposit(int date,double amount);   //存入现金
        void withdraw(int date,double amount);  //取出现金
        void settle(int date);                  //结算利息

    private:
        int id;                     //账号
        double balance;             //余额
        double rate;                //存款的年利率
        int lastDate;               //上次变余额的日期
        double accumulation;        //余额按日累加之和
        //记录一笔账record，date为日期，amount为金额
        void record(int date,double amount);
        //获得到指定日期为止的存款金额按日累积值
        double accumulate(int date)
        {
            return (date-lastDate)*balance+accumulation;
        }
};

SavingAccount::SavingAccount(const int date,const int _id,const double _rate)
:lastDate(date),id(_id),rate(_rate),balance(0),accumulation(0) 
{
    cout<<date<<"\t#"<<id<<"is created"<<endl;
}

void SavingAccount::record(int date,double amount)
{
    accumulation=accumulate(date);
    lastDate=date;
    balance+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
    return ;
}

void SavingAccount::show()
{
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
    return ;
}

void SavingAccount::deposit(int date,double amount)
{
    record(date,amount);
    return ;
}

void SavingAccount::withdraw(int date,double amount)
{
    if(amount>balance)
    {
        cout<<"Error:not enough money"<<endl;
    }
    else
    {
        record(date,amount);
    }
    return ;
}

void SavingAccount::settle(int date)
{
    double interest=accumulate(date)*rate/YEAR_DAY;
    if(interest!=0)
    {
        record(date,interest);
    }
    accumulation=0;
    return ;
}

int main()
{
    SavingAccount sa0(1,21325302,0.015);
    SavingAccount sa1(1,58320212,0.015);
    sa0.deposit(5,5000);
    sa1.deposit(25,10000);
    sa0.deposit(45,5500);
    sa1.withdraw(60,4000);
    sa0.settle(90);
    sa1.settle(90);
    sa0.show();
    sa1.show();
    return 0;
}