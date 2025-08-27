#include<cstdio>
using namespace std;

int a=10;

decltype(a) max(decltype(a) b,decltype(a) c)
{
    return b>c? b:c;
}

int main()
{
    int b,c;
    printf("max(b,c)=%d",max(b,c));
    return 0;
}