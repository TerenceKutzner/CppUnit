#include <string>
#include "example_1.h"


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

std::string par(int a) 
{
    if(a%2==0)
    {
        return "Par";
    }
    else
    {
        return "Impar";
    }
}

int fatorial(unsigned int a) 
{
    int result=1;
    for(int i=1;i<a;i++)
    {
        result=result*i;
    }
    return result;
}
