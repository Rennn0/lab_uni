#include "../lib.h"

void cheen(double& ,double&);

int main()
{
    double m,n;
    cout<<"m=";cin>>m;
    cout<<"n=";cin>>n;
    cheen(m,n);
}

void cheen(double& a,double& b)
{
    if(a>b)
    {
        cout<<"before _ "<<a<<' '<<b<<endl;
        double tmp=a;
        a=b;
        b=tmp;
        cout<<"after _ "<<a<<' '<<b<<endl;
    }
    else
        cout<<"what wrong with u brooo?"<<endl;
}