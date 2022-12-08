#include "../lib.h"

pair<int,int>Rec(const int& height,const int& width)
{
    pair<int,int>tmp={height*width,2*(height+width)};
    return tmp;
} 

int main(int argc, char** argv)
{
    pair<int,int> c=Rec(atoi(argv[1]),atoi(argv[2]));
    cout<<"fartobi: "<<c.first<<'\n'<<"perimetri: "<<c.second<<endl;
}