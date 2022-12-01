// 6.3 დაწერეთ ფუნქცია რომელიც იპოვის სრულყოფილ რიცხვებს (perfect number). 
// კოდში აუცილებლად გამოიყენეთ პოინტერები ან/და რეფერენსები.
// სრულყოფილია რიცხვი, რომელიც უდრის მისი დადებითი გამყოფების ჯამს. 
// მაგალითად, 6-ს აქვს გამყოფები 1, 2 და 3 (თავისი თავის გამოკლებით), და 1 + 2 + 3 = 6, ასე რომ 6 არის სრულყოფილი რიცხვი.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void perfect(int &);

int main()
{
    int wish=7; // ramdeni srulyofili vipovot
    perfect(wish);
}

void perfect(int &n)
{
    // formula  2^p * (2^(p+1) -1 ) == perfect
    // 
    for(int a=1, c=1; n>0;++a, --n, c+=2 )
    {
        
        
    }
    
}