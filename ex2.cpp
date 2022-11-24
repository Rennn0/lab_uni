#include "lib.h"

void kvadrati(int&);

int main()
{
    int a=5;
    cout<<"before_"<<a<<endl;
    kvadrati(a);
    cout<<"after_"<<a<<endl;
}

void kvadrati(int& a)
{
    a*=a;
}