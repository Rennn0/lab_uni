#include "../lib.h"

class Cvector
{
    private:
        double x, y;
    
    public:
        Cvector()
        {
            x=0;
            y=0;
            get();
        }
        Cvector(double a,double b)
        {
            x=a; y=b;
            get();
        }
        void get()
        {
            cout<<"x="<<x<<' '<<"y="<<y<<endl;
        }
        Cvector operator+ (const Cvector& op1)
        {
            Cvector tmp;
            tmp.x=this->x+op1.x;
            tmp.y=this->y+op1.y;
            return tmp;
        }
};

int main()
{
    Cvector obj1, obj2(5,6.2), obj3=obj1+obj2;
    obj3.get();
}