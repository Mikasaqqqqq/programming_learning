#include<cstdio>
#include<iostream>
using namespace std;

enum Level{FRESHMAN,SOPHOMORE,JUNIOR,SENIOR};
enum Grade{A,B,C,D};

class Student
{
    public:
        Student(unsigned int num,Level lev,Grade gra)
            :number(num),level(lev),grade(gra) {}
        void show();
    
    private:
        unsigned int number:27;// bitfield
        Level level:2;
        Grade grade:2;
};

void Student::show()
{
    cout<<"number:  "<<number<<endl;
    cout<<"level:   ";
    switch (level)
    {
        case FRESHMAN: cout<<"Freshman"<<endl;break;
        case SOPHOMORE: cout<<"Sophomore"<<endl;break;
        case JUNIOR: cout<<"Junior"<<endl;break;
        case SENIOR: cout<<"Senior"<<endl;break;  
    }
    cout<<"grade:   ";
    switch (grade)
    {
        case A: cout<<"A"<<endl;break;
        case B: cout<<"B"<<endl;break;
        case C: cout<<"C"<<endl;break;
        case D: cout<<"D"<<endl;break;  
    }
    return ;
}

int main()
{
    Student s(12345678,SOPHOMORE,B);
    cout<<"Size of Student:"<<sizeof(Student)<<endl;
    s.show();
    return 0;
}