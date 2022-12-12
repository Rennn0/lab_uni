#include "bsm.cpp"
#include "calc.cpp"

void greet();

int main()
{
    greet();
}

void greet()
{
    string left(51,'#'),h(20,'-');
    cout<<left<<endl<<h<<"->Welcome<-"<<h<<endl<<left<<endl;
}