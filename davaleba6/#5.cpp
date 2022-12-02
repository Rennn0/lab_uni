// 6.3 დაწერეთ ფუნქცია რომელიც იპოვის სრულყოფილ რიცხვებს (perfect number). 
// კოდში აუცილებლად გამოიყენეთ პოინტერები ან/და რეფერენსები.
// სრულყოფილია რიცხვი, რომელიც უდრის მისი დადებითი გამყოფების ჯამს. 
// მაგალითად, 6-ს აქვს გამყოფები 1, 2 და 3 (თავისი თავის გამოკლებით), და 1 + 2 + 3 = 6, ასე რომ 6 არის სრულყოფილი რიცხვი.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void perfect(int &);
bool check(size_t);

int main()
{
    int wish=5; // ramdeni srulyofili vipovot, mets verc poulobs :|||||
    perfect(wish);
}

void perfect(int &n)
{
    // formula  2^(p-1) * (2^p -1 ) == perfect
    // p_primary number , 2^p-1_ mersene prime
    // formula araa sakmarisi, shemowmebac unda
    size_t perf;
    for(int a=2;n>0;a++)
    {
        perf=pow(2,a-1)*(pow(2,a)-1);
        if(check(perf))
        {
            cout<<fixed<<perf<<"\tp="<<a<<endl;
            --n;
        }
            
    }
        
}

bool check(size_t m)
{
    size_t jami=0;
    for(size_t i=1;i<=m/2;++i)
    {
        if(m%i==0)
            jami+=i;
    }
    return jami==m;
}