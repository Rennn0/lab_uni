#include "../lib.h"

// npv_net present value
// intereset rate
// $$$= t0/(1+%)^y0
//npv = E $$$

class Econ
{
    private:
        vector<double> wliuri_shenatani;
        vector<double> NPV;
        double procenti, investicia;
        int vada;
        double shedegi; 
    public:
        Econ();
        bool check(const double);
        bool check_y(const double);
        void print();
        void npv_print();
        double get_perc();
        double get_inv();
        bool result();
};

    Econ::Econ()
    {
        double y; //gamotvlebistvis
        cout<<"sawyisi investicia _ ";cin>>investicia;
        
        cout<<"wlebis raodenoba _ ";cin>>vada;
        // chavtvalot ro 100 wlianze naklebi iqneba investicia
        while(!check((double)vada))
        {
            cout<<"miutitet validuri mnishvneloba _ "; cin>>vada;
        }

        cout<<"saprocento ganakveti _ ";cin>>procenti;
        while(!check(procenti))
        {
            cout<<"miutitet validuri mnishvneloba _ "; cin>>procenti;
        }
        cout<<"miutitet wliuri shenatanebi: "<<endl;
        for(size_t t=1;t<=vada;++t)
        {
            cout<<"year "<<t<<" : "; cin>>y;
            wliuri_shenatani.push_back(y);
        }
        for(size_t t=1;t<=vada;++t)
        {
            y=wliuri_shenatani[t-1]/(pow(1+procenti/100,1.*t));
            NPV.push_back(y);
        }
    }

    bool Econ::check(const double n)
    {
        return n>=0 && n<100; 
    }
    void Econ::print()
    {
        string g(40,'-');
        cout<<"\n"<<g<<"\nshenatanebi wlebis mixedvit\n";
        short n=1;
        for(auto v:wliuri_shenatani)
            cout<<"year "<<n++<<'-'<<v<<endl;
    }
    void Econ::npv_print()
    {
        string g(40,'-');
        cout<<"\n"<<g<<"\nnet present value\n";
        short n=1;
        for(auto v:NPV)
            cout<<"year "<<n++<<'-'<<v<<endl;
    }
    double Econ::get_inv()
    {
        cout<<"\nsawyisi investicia "<<investicia<<endl;
        return investicia;
    }

    double Econ::get_perc()
    {
        cout<<"\nsaprocento ganakveti "<<procenti<<endl;
        return procenti;
    }

    bool Econ::result()
    {
        string g(40,'-');
        double put=0, get=0;
        for(size_t t=0;t<vada;++t)
        {
            put+=wliuri_shenatani[t];
            get+=NPV[t];
        }
        cout<<g<<"\nsul shenatani - "<<put<<endl;
        cout<<"\nsul migebuli - "<<get<<endl;
        return investicia-get>0;
    }
    bool Econ::check_y(const double d)
    {

    }
int main(void)
{
    Econ obj1;
    obj1.print();
    obj1.npv_print();
    obj1.result();
}