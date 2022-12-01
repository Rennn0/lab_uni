// 6.1.2 დაწერეთ მართხკუთხედი ფართობის გამოსათვლელი ფუნქცია რომელიც მიიღებს არგუმენტებს: Pointer-ად

#include <iostream>
using namespace std;

double area(double *, double *);

int main()
{
    double x,y;
    cout<<"x=";cin>>x;
    cout<<"y=";cin>>y;
    cout<<area(&x,&y)<<endl;
}

double area(double *a, double *b)
{
    return *a**b;
}