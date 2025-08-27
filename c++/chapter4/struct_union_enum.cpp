#include<cstdio>
#include<iostream>
using namespace std;

class ExamInfo
{
    public:
        ExamInfo(const string &_name,const char _grade)
            : name(_name),mode(GRADE),grade(_grade) {}

        ExamInfo(const string &_name,const bool _pass)
            : name(_name),mode(PASS),pass(_pass) {}    

        ExamInfo(const string &_name,const double _precent)
            : name(_name),mode(PRECENTAGE),precent(_precent) {}

        void show();

    private:
        string name;
        enum
        {
            GRADE,
            PASS,
            PRECENTAGE
        }mode;
        union
        {
            char grade;
            bool pass;
            double precent;
        };
        /*
        联合体也可以不声明名称，称为无名联合体。无名联合体没有标记名，只是声明一个成员项的集合，
        这些成员项具有相同的内存地址，可以由成员项的名字直接访问。
        */
};

void ExamInfo::show()
{
    cout<<name<<":";
    switch(mode)
    {
        case GRADE:
            cout<<grade;
            break;
        case PASS:
            cout<<(pass? "PASS":"FAIL");
            break;
        case PRECENTAGE:
            cout<<precent;
            break;
    }
    cout<<endl;
    return ;
}

int main()
{
    ExamInfo course1("English",'B');
    ExamInfo course2("Calculus",true);
    ExamInfo course3("C++Progamming",85.0);
    course1.show();
    course2.show();
    course3.show();
    return 0;
}