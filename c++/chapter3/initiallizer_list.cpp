#include<cstdio>
#include<cstring>
#include<iostream>
#include<initializer_list>
using namespace std;

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