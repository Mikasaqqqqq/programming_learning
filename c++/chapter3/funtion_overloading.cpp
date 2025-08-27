#include<cstdio>
using namespace std;

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