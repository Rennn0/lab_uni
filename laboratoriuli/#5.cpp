#include "../lib.h"

int main()
{
    string c; int cnt=0;

    ifstream in("laboratoriuli/words.in");
    if(in.is_open())
    {
        while(in>>c)
        {
            cnt++;
            cout<<c<<endl;
            if(c=="exam.")
            {
                cout<<"\nexam. found at position "<<cnt<<endl;
                in.close();
                return cnt;
            }
        }
    }
    else
    {
        cout<<"error"<<endl;
        in.close();
        return -1;
    }


}