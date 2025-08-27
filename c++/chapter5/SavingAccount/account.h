#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
class SavingsAccount
{
    public:
        SavingsAccount(int data,int id,double rate);
        int getId() const {return id;}
        double getBalance() const {return balance;}
        double getRate() const {return rate;}
        void show() const;
        void deposit(int date,double amount);
        void withdraw(int date,double amount);
        void settle(int date);
        static double getTotal() {return total;}

    private:
        int id;
        double balance;
        double rate;
        int lastDate;
        double accumulation;
        static double total;
        void record(int date,double amount);
        double accumulate(int date) const
        {
            return accumulation+balance*(date-lastDate);
        }
};
#endif