#include "bsm.cpp"
#include "calc.cpp"

void greet();
void bsm_call();
void bsm_call_r();
int main()
{
    greet();
    string question;
    
    while(question!="stop")
    {
        cout<<"pirveli meore _ ";
        cin>>question;
        switch(question.length())
        {
            case 5:
                bsm_call_r();
                break;
            case 7:
                bsm_call();
                break;
        }
    }
}

void greet()
{
    string left(51,'#'),h(20,'-');
    cout<<left<<endl<<h<<"->Welcome<-"<<h<<endl<<left<<endl;
}
void bsm_call()
{
    Bsm* ptr=new Bsm;
    cin>>*ptr;
    cout<<*ptr;
}

void bsm_call_r()
{
    Bsm* ptr=new Bsm;
    cout<<*ptr;
}