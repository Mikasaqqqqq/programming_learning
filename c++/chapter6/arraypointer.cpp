#include<cstdio>
#include<iostream>
using namespace std;

typedef int arr[10];
// using arr=int[10];

int (*foo(int i))[10];
arr* foo(int i);
auto foo(int i)-> int (*)[10];

int a[]={1,2,3};
int b[]={2,3,4};

decltype(a) *func(int i)// a的类型是 int[3];
{
    return (i%2)? &a:&b;
}

int main()
{
    int (*p)[3]=&a;
    printf("%p %p",p+1,a);
    return 0;
}