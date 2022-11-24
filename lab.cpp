#include "lib.h"

//leetcode arranging coins

// 325ms sucks
//6mb memory

// int arrangeCoins(int n) {
//     // 1  3  6  10  15 21 ...
//     int arr[10]={1};
//     for(int a=1, b=2;a<10;++a, ++b)
//     {
//         arr[a]=arr[a-1]+b;
//     }

//     for(size_t t=1;t<10;++t)
//     {
//         if(n==arr[t-1])
//         {
//             cout<<t<<endl;
//             return t;
//         } 
//         else if(n>arr[t-1])
//             continue;
//         else 
//         {
//             cout<<t-1<<endl;
//             return t-1;
//         }
//     }
//     cout<<"fail";
//     return 1;
// };

int arrangeCoins(int n)
{
    long dec=0;
    for(size_t a=1;true;++a)
    {
        if(n==0)
        {
            cout<<a<<endl;
            return a;
        } else if(n<0)
        {
            cout<<a-1<<endl;
            return a-1;
        }
        dec+=a;
        n-=dec;
    }
}


int main()
{
    arrangeCoins(17);
}