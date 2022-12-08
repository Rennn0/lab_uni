#include "../lib.h"

class Rect
{
    public:
        int_fast16_t a,b;
        double area(void)
        {
            return a*b;
        }

        double peri(void)
        {
            return 2*(a+b);
        }
        double diag(void)
        {
            return sqrt(a*a+b*b);
        }
        void print(void)
        {
            cout<<"gverdebi "<<a<<' '<<b<<endl;
            cout<<"perimetri "<<peri()<<endl;
            cout<<"fartobi "<<area()<<endl;
            cout<<"diagonali "<<diag()<<endl;
        }
};

int main(void)
{
    Rect obj1;
    obj1.a=5; obj1.b=10;
    obj1.print();
}