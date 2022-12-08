#include "../lib.h"
#define P 3.14159265359

int objcount=0;

class Circle
{
    private:
        double r, are=0, circum=0;
        int id;
        // sheidzleboda formulebis chasma pirdapir
    public:
        Circle(); // default r=1
        Circle(const double rad);// p*r*r
        double get_circumference(); // circum
        double get_area(); //are
        Circle operator+(const Circle& c); // ++area ++circum
        void print();
};

    Circle::Circle()
        {
            ++objcount;
            id=objcount;
            r=1;
            are=P*r*r;
            circum=2*P*r;
        }   
    Circle::Circle(const double rad)
        {
            ++objcount;
            id=objcount;
            r=rad;
            are=P*r*r;
            circum=2*P*r;
        }
    double Circle::get_circumference()
        {
            cout<<"Circumference = "<<circum<<endl;
            return circum;
        }
    double Circle::get_area()
        {
            cout<<"Area = "<<are<<endl;
            return are;
        }
    Circle Circle::operator+(const Circle& c)
        {
            Circle temp;
            temp.r=this->r+c.r;
            temp.are=this->are+c.are;
            temp.circum=this->circum+c.circum;
            return temp;
        }
    void Circle::print()
        {   
            cout<<"Circle ID _ "<<id<<endl;
            cout<<"Circle radius _ "<<r<<endl;
            cout<<"Circle area _ "<<are<<endl;
            cout<<"Circle circumference _ "<<circum<<endl;
            cout<<endl;
        }

    

int main(void)
{
    Circle obj1, obj2(2.5), obj3=obj1+obj2;
    obj1.print();
    obj2.print();
    obj3.print();
}