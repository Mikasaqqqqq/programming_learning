#include<cstdio>
#include<iostream>
using namespace std;

typedef int (*DoubleIntFunction)(double);

int func(const double x)
{
    return static_cast<int>(x);
}

void print(const int *p,const int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",p[i]);
    printf("\n");
    return ;
}

int main()
{
    DoubleIntFunction funcPtr=func;
    printf("func(3.14)=%d\n",funcPtr(3.14));

    void (*funcPointer)(const int *,const int )=print;
    int a[]={1,2,3,4,5};
    funcPointer(a,5);
    return 0;
}