#include <iostream>
using namespace std;
int main()
{
//!	void voidobject; 错，不能声明 void类型的变量
	void *pv;
    int i=5;
    pv=&i;
    int *prin=static_cast<int*>(pv);
    printf("prin=%d",*prin);
	return 0;
}