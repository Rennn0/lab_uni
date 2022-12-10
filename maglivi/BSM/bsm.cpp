#include "bsm.h"


// gadavtvirtav cin cout operaciesbs klasis input outputistvis 
istream& operator >> (istream& is,Bsm& obj)
{
    
    string h(30,'-');
    double s,k,r,t;
    cout<<"\nmogesalmebit Black-Scholes modelis simulatorshi \n"
        <<h<<"\nshemoitanet monacemebi gamotvlebistvis"<<endl;
    
    cout<<"Current stock_"; 
    // shezgudva daedeba yvelanair inputs garda double_sa
    // 2saati am metodis dzebnas movundi -_____-
    while(!(is>>s) || s<0) 
    {
        is.clear(); // buffers gaasuftavebs
        is.ignore(numeric_limits<streamsize>::max(), '\n'); // gaabatilebs mtlian inputs sanam axali xazi ar shexvdeba
        cout<<"shemoitane validuri mnishvneloba_"; // shecdomis dzaxili, mere tavidan daawerinebs
    }

    cout<<"Strike price_"; 
    while(!(is>>k) || k<0) 
    {
        is.clear(); 
        is.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout<<"shemoitane validuri mnishvneloba_"; 
    }

    cout<<"Risk free interest rate_"; 
    while(!(is>>r) || r<0 || r>100) 
    {
        is.clear(); 
        is.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout<<"shemoitane validuri mnishvneloba_"; 
    }

    cout<<"Time to maturity_"; 
    while(!(is>>t) || t<0) 
    {
        is.clear(); 
        is.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout<<"shemoitane validuri mnishvneloba_"; 
    }

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