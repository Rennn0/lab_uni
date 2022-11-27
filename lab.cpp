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

// 10ms 
// 5.9 mb

int arrangeCoins(int n)
{
    for(int a=2,b=1;true;b+=a, ++a){
        if(n>b)
            continue;
        else if(n==b){
            return a-1;
        }
        else{
            return a-2;
        }
    }
}


int main()
{
    arrangeCoins(1);
}