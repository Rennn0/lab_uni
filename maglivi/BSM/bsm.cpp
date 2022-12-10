#include "bsm.h"

// gadavtvirtav cin cout operaciesbs klasis input outputistvis 
istream& operator >> (istream& is,Bsm& obj)
{
    
    string h(30,'-');
    double s,k,r,t;
    cout<<"mogesalmebit Black-Scholes modelis simulatorshi \n"
        <<h<<"\nshemoitanet monacemebi gamotvlebistvis"<<endl;
    
    cout<<"Current stock_"; is>>s; 
    while(s<=0){cout<<"shemoitane validuri mnishvneloba_"; is>>s;}

    cout<<"Strike price_"; is>>k; 
    while(k<=0){cout<<"shemoitane validuri mnishvneloba_"; is>>k;}

    cout<<"Risk free interest rate_"; is>>r; 
    while(r<0 || r>100){cout<<"shemoitane validuri mnishvneloba_"; is>>r;}

    cout<<"Time to maturity_"; is>>t; 
    while(t<=0){cout<<"shemoitane validuri mnishvneloba_"; is>>t;}

    obj.S=s; obj.K=k; obj.R=r; obj.T=t;
    // shemedzlo obj=Bsm(s,k,r,t) gameketebina da friend wvdoma ar damchirdeboda
    // magram operacia axali obieqtis sheqmnad chaitvleboda da globalur ID awevda
    // gadatvirtva razec gamovidzaxe im obieqtis IDc sheicvleboda
    return is;
}

ostream& operator << (ostream& os, const Bsm& obj)
{
    string h(30,'*');
    
    os<<h<<"\naqcia id:"<<obj.ID<<"\nmonacemebi:"
        "\nCurrent stock_"<<fixed<<obj.S
        <<"\nStrike price_"<<fixed<<obj.K
        <<"\nRisk free interest rate_"<<fixed<<obj.R
        <<"\nTime to maturity_"<<fixed<<obj.T<<endl;
        
        return os;
}