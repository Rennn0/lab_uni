#include "lib.h"

int main()
{
    srand(time(0));
    
    int array[10]={}, n, *ptr=array;
    for(size_t a{};a<10;++a)
    {
        n=rand()%11;
        array[a]=n;
    }

    cout<<"masivis index\t\telementi intergral\t\telementi pointer\n";
    for(size_t a{};a<10;++a)
    {
        cout<<setw(10)<<a<<setw(20)<<array[a]<<setw(30)<<*(ptr+a)<<endl;
    }
    

}