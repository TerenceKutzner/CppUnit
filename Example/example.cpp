#include "example.h"


int maximo(int a, int b) 
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int fatorial(unsigned int a) 
{
    int result=1;
    for(int i=1;i<=a;i++)
    {
        result=result*i;
    }
    return result;
}
