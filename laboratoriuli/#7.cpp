#include "../lib.h"

void ok(double &,double &,double &);

int main()
{
    double a=5,b=1,c=9;
    cout<<"main before sort_ "<<a<<b<<c<<endl;
    ok(a,b,c);
    cout<<"main  after sort_ "<<a<<b<<c<<endl;
}

void ok(double &a,double &b,double &c)
{
    double arr[3]={a,b,c};
    cout<<"before _ "<<arr[0]<<arr[1]<<arr[2]<<endl;
    sort(arr, arr+3);
    cout<<"after _ "<<arr[0]<<arr[1]<<arr[2]<<endl;
    a=arr[0]; b=arr[1]; c=arr[2];
}