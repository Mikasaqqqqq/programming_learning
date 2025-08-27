---
author: Mikasa
categories: programming-learning
excerpt: 重新系统性地学一下c++
---

## C++ note

[^参考书]: 《C++语言程序设计（第5版）》 郑莉 董渊

### chapter 3

#### 3.1

##### 引用

​	**引用是一种特殊类型的变量，可以被认为是另一个变量的别名**，通过引用名与通过被引用变量名访问变量的效果是一样的。

```cpp
// 引用
int a = 10,q=100;
int &b = a; // b是a的引用
b = 20;     // 通过b修改a
printf("a = %d\n", a); // 输出a的值
/*
error case:
b = &q; // 引用不能被重新赋值
int &c; // 引用必须初始化
int &d = 10; // 引用必须引用一个变量，不能是字面值
int &e = b + 1; // 引用必须引用一个变量，不能是表达式
*/
```



##### initializer_list

​	`initializer_list`  是一种标准库类型，用于表示某种特定类型的值的数组，该类型定义在同名的头文件中。

>`initializer_list` 提供的操作：
>	`initializer_list<T>lst` :默认初始化；`T`类型元素的空列表。
>	`initializer_list<T> lst{a,b,c⋯}`:`lst`的元素数量和初始值一样多；`lst`的元素是对应初始值的副本；列表中的元素是 `const`。
>	`lst2(lst),lst2=lst`:复制或者赋值一个 `initializer_list`对象但不复制列表中的元素；复制后原始列表和副本共享元素。
>	`lst.size()`:列表中的元素数量。
>	`lst.begin()`:返回指向`lst` 首元素的指针。
>	`lst.end()`:返回指向 `lst` 尾元素下一位置的指针。

```cpp
#include<initializer_list>

void print_err(initializer_list<string> il)
{
    for(auto i:il) 
    {
        cout<< i << " ";
    }
    /*
    for(auto i=il.begin();i!=il.end();i++)
    */
    printf("\n");
    return ;
}

int main()
{
    string s1 = "hello";
    string s2 = "world";
    if(s1!= s2)
    {
        print_err({"s1 != s2", "s1 = ", s1, "s2 = ", s2});
    }
    else
    {   
        print_err({"s1 == s2", "s1 = ", s1, "s2 = ", s2});
    }
    return 0;
}
```



#### 3.2 内联函数

​	对于一些功能简单、规模较小又使用频繁的函数，可以设计为内联函数。**内联函数不是在调用时发生控制转移，而是在编译时将函数体嵌入在每一个调用处**。这样就节省了参数传递、控制转移等开销。

```cpp
inline void print_hello()
{
    printf("Hello, World!\n");
}

int main()
{
    print_hello(); // 调用内联函数
    return 0;   
}
```



#### 3.3 constexpr 函数

​	`constexpr` 函数是指能用于常量表达式的函数。定义 `constexpr` 函数的方法与其他函数类似，但要遵循几项约定：函数的返回类型以及所有的形参类型必须是常量，而且函数体中必须有且仅有一条 `return` 语句：

```cpp
// 关键字 constexpt 与 constexpr 函数
constexpr int block_size()
{
    return 20;
}

constexpr int len(int a)
{
    return a*block_size();
}

int main()
{
    constexpr int size=len(2);
    /*
    error:
    int i=2;
    constexpr int _size=len(i);    
    */
    return 0;
}
```



#### 3.4 带默认形参值的函数 (default_parameter)

​	函数在定义时可以预先声明默认的形参值。调用时如果给出实参，则用实参初始化形参，如果没有给出实参，则采用预先声明的默认形参值。

​	**有默认值的形参必须在形参列表的最后**，也就是说，在有默认值的形参右面，不能出现无默认值的形参。因为在函数调用中，实参与形参是按从左向右的顺序建立对应关系的。

​	**在相同的作用域内，不允许在同一个函数的多个声明中对同一个参数的默认值重复定义，即使前后定义的值相同也不行**。这里作用域是指直接包含着函数原型说明的大括号所界定的范围

```cpp
int max(int a,int b=0,int c=0);

int main()
{
    int a=3,b=5,c=2;
    printf("%d\n",max(a)); // 3
    printf("%d\n",max(a,b)); // 5
    printf("%d\n",max(a,b,c)); // 5
    return 0;
}

int max(int a,int b /*=0*/,int c/*=0*/)
{
    return max(a,max(b,c));
}
// 函数声明时指定默认参数，函数定义时不再指定
// 默认参数从右向左依次指定
// 函数调用时可以省略默认参数
```



#### 3.5 函数重载(funtion overloading)

​	**两个以上的函数，具有相同的函数名，但是形参的个数或者类型不同，编译器根据实参和形参的类型及个数的最佳匹配，自动确定调用哪一个函数，这就是函数的重载。**

```cpp
int max(int a,int b);
double max(double a,double b);
int max(int a,int b,int c);
/*
error:
int max(int a,int b,int c=0);
*/

int main()
{
    int a=5,b=2,c=3;
    printf("max(a,b)=%d",max(a,b));
    printf("max(a,b,c)=%d",max(a,b,c));
    return 0;
}

int max(int a,int b)
{
    return a>b ? a:b;
}

int max(int a,int b,int c)
{
    return max(a,max(b,c));
}

double max(double a,double b)
{
    return a>b ? a:b;
}
```



### chapter 4

#### 4.2 类和对象 & 4.3 构造函数、析构函数

```cpp
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
```



```cpp
#include<cstdio>
#include<iostream>
using namespace std;

class Point 
{
    public:
        Point(int xx=0,int yy=0)
        {
            x=xx;
            y=yy;
        }

        Point(Point &p);// 显式

        int Get_x()
        {
            return x;
        }

        int Get_y()
        {
            return y;
        }

    private:
        int x,y;
};

Point::Point(Point &p)
{
    x=p.x;
    y=p.y;
    printf("Calling the copy constructor\n");
}

void fun1(Point p)// 传值，调用了复制构造函数
{
    printf("%d\n",p.Get_x());
    return ;
}

Point fun2()
{
    Point a(1,2);
    return a;// 可能被编译器优化
}

int main()
{
    Point a(4,5);
    Point b=a;
    printf("%d\n",b.Get_x());
    fun1(b);
    b=fun2();
    printf("%d\n",b.Get_x());
    return 0;
}
```



##### 移动构造函数

​	复制构造函数通过复制的方式构造新的对象，而很多时候被复制的对象仅作复制之用后销毁，在这时，如果使用移动已有对象而非复制对象将大大提高性能。C++11标准推出以前，没有移动对象的直接方法，C++11标准引入了左值和右值，定义了右值引用的概念，以表明被引用对象在使用后会被销毁，不会再继续使用。直观来看，**左值是位于赋值语句左侧的对象变量，右值是赋值语句右侧的值，不依附于对象**。3.1节中参数引用传递中**对持久存在变量的引用，称之为左值引用，相对的对短暂存在可被移动的右值的引用称之为右值引用**。因此，可通过移动右值引用对象来安全地构造新对象，并且避免冗余复制对象的代价。

```cpp
float n=6;
float &lr_n=n;	//对变量n的左值引用
float &&rr_n=n; //错误，不能将右值引用绑定到左值n上
float &&rr_n=n * n; //将乘法结果右值绑定到右值引用
float &lr_n=n * n; //错误，不能将左值引用绑定到乘法结果右值
```

​	以上举例展示了右值引用和左值引用的区别和正确使用方式，注意一个左值对象不能绑定到一个右值引用上。但实际应用中，可能某个对象的作用仅限在初始化其他新对象使用后销毁，标准库 `utility` 中声明提供了 `move` 函数，将左值对象移动成为右值。

```cpp
float n=10;
float &&rr_n=std::move(n); //将左值对象移动为右值并绑定右值引用
```

`move` 函数告诉编译器变量 `n` 转换为当右值来使用，承诺除对 `n` 重新赋值或者销毁它以外，将不再通过 `rr_n` 右值引用以外的方式使用它。

​	基于右值引用的新设定，可以通过移动而不复制实参的高性能方式构建新对象，即移动构造函数。类似于复制构造函数，移动构造函数的参数为该类对象的右值引用，在构造中移动源对象资源，构造后源对象不再指向被移动的资源，源对象可重新赋值或者被销毁：

```cpp
class Mystr
{
    public:
        string s;

        Mystr(): s(""){}// 无参构造函数

        Mystr(string _s): s(move(_s)) {}// 有参构造函数

        Mystr(Mystr &&str) noexcept// 告知编译器不会抛出异常
            : s(move(str.s)) {}// 移动构造函数
};
```



##### default、delete 函数

​	默认构造函数、复制构造函数和移动构造函数，这些概念让人眼花缭乱，在定义一个新类时，用户可能只是希望简单地使用，不希望花太多精力在复制控制优化性能上，C++11标准提供了 `default` 和 `delete` 两个关键字来简化构造函数的定义与使用。使用 `=default` 可显示要求编译器自动生成默认或复制构造函数。

​		通过使用 `default` ,可以让编译器合成简单的无参默认构造函数和复制构造函数，但其他使用参数的构造函数，由于编译器不知构造逻辑，需要用户自行定义。当用户不希望定义的类存在复制时，可以通过 `delete` 关键字将复制构造函数删除：

```cpp
class Mystr
{
    public:
        string s;

        Mystr()=default;//默认合成的无参构造函数

        Mystr(string _s): s(move(s)) {}//有参构造函数

        Mystr(Mystr &&str)=default;//默认合成的赋值构造函数
        // Mystr(Mystr &&str)=delete; //删除复制构造函数

        ~Mystr()=default;//默认合成的析构函数
};
```

​	与 `default` 使用不同的是，`delete` 不限于在无参和复制构造函数上使用，除析构函数外，用户都可以指定为 `delete` 删除掉，以便禁止类使用过程中的相关操作，比如上例中的复制操作。



#### struct、union、enum

```cpp
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
```



#### 位域（bitfield）

程序员可以通过冒号(:)后的位数来指定为一个位域所占用的二进制位数。使用位域，有以下几点需要注意：

- C++标准规定了使用这种机制用来允许编译器将不同的位域“打包”,但这种“打包”的具体方式，C++标准并没有规定，因此不同的编译器会有不同的处理方式，不同编译器下，包含位域的类所占用的空间也会有所不同。
- 只有bool(布尔型)、char(字符型)、int(整型)和enum(枚举型)的成员才能够被定义为位域。
- 位域虽然节省了内存空间，但由于打包和解包的过程中需要耗费额外的操作，所以运行时间很有可能会增加。

结构体与类的唯一区别在于访问权限，因此也允许定义位域；但联合体中，各个成员本身就共用相同的内存单元，因此没必要也不允许定义位域。

```cpp
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
```



### Chapter 5

#### 类的静态成员

##### 1. 类的静态数据成员

​	**静态数据成员具有静态生存期**。由于静态数据成员不属于任何一个对象，因此可以通过类名对它进行访问，一般的用法是“类名：:标识符”。在类的定义中仅仅对静态数据成员进行引用性声明，必须在文件作用域的某个地方使用类名限定进行定义性声明，这时也可以进行初始化。C++11标准支持常量表达式类型修饰(constexpr 或 const)的静态常量在类内初始化，此时仍可在类外定义该静态成员，但不能做再次初始化操作。



##### 2. 类的静态成员函数

​	**静态成员函数可以直接访问该类的静态数据和函数成员**。而访问非静态成员，必须通过对象名。通过静态函数成员访问非静态成员是相当麻烦的，一般情况下，它主要用来访问同一个类中的静态数据成员，维护对象之间共享的数据。



```cpp
#include<cstdio>
#include<iostream>
using namespace std;

class Point
{
    public:
        Point(int xx=0,int yy=0):x(xx),y(yy) 
        { 
            count++; 
        } // 构造函数

        Point(const Point &p):x(p.x),y(p.y) 
        { 
            count++; 
        } // 复制构造函数

        ~Point() 
        { 
            count--; 
        } // 析构函数

        int getX() const { return x; }
        int getY() const { return y; }
        static void showCount() //静态成员函数
        { 
            printf("Object count=%d\n",count);
            return ;
        }
        /*
        void showCount() const 
        { 
            printf("Object count=%d\n",count);
            return ;
        }
        */
        

    private:
        static int count; // 静态数据成员声明
        constexpr static int origin=0; // 常量静态变量类内初始化
        int x,y;
};

int Point::count=0; // 静态数据成员定义与初始化
constexpr int Point::origin; // 常量静态变量类外定义

int main()
{
    Point a(4,5);
    printf("Point A:(%d,%d) ",a.getX(),a.getY());
    Point::showCount();
    //a.showCount();

    Point b(a);
    printf("Point B:(%d,%d) ",b.getX(),b.getY());
    Point::showCount();   
    //b.showCount();

    return 0;
}
```





#### 类的友元（Friend of Class）

```cpp
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

/*
friend function
*/
class Point
{
    public:
        Point(int xx=0,int yy=0):x(xx),y(yy) {}
        int getX() const {return x;}
        int getY() const {return y;}
        friend float dist(Point &p1,Point &p2);
    
    private:
        int x,y;
};

float dist(Point &p1,Point &p2)
{
    double x=p1.x-p2.x;
    double y=p1.y-p2.y;
    return static_cast<float>(sqrt(x*x+y*y));
}

/*
friend class
*/

class A
{
    public:
        void show()
        {
            printf("%d\n",x);
            return ;
        }

        int getX() {return x;}
        friend class B;// //B类是A类的友元类

    private:
        int x;
};

class B
{
    public:
        void set(int i);
    
    private:
        A a;
};

void B::set(int i)
{
    a.x=i; //由于B是A的友元，所以在B的成员函数中可以访问A类对象的私有成员
    return ;
}

int main()
{
    Point myp1(1,1),myp2(4,5);
    cout<<"The distance is:";
    cout<<dist(myp1,myp2)<<endl;    
    return 0;
}
```



