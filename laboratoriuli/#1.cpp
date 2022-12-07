#include "../lib.h"

int main(int argc, char** argv)
{
    cout<<"Before swap "<<argv[1]<<" "<<argv[2]<<endl;
    char* t=argv[1];
    argv[1]=argv[2];
    argv[2]=t;
    cout<<"After swap "<<argv[1]<<" "<<argv[2]<<endl;
}
