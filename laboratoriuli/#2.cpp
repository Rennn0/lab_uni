#include "../lib.h"

void swap(char**,char**);
void SRT(char*,char*);

int main(int argc, char** argv)
{
    cout<<"Before _ "<<argv[1]<<" "<<argv[2]<<endl;

    swap(argv[1],argv[2]);
    cout<<"After _ "<<argv[1]<<" "<<argv[2]<<endl;
    
    SRT(argv[1],argv[2]);
    cout<<"After Sort_ "<<argv[1]<<" "<<argv[2]<<endl;
}

void swap(char** s1,char** s2)
{
    char* temp=*s1;
    s1=s2;
    *s2=temp;
}

void SRT(char* s1,char* s2)
{
   sort(s1,s1+strlen(s1));
   sort(s2,s2+strlen(s2));
}