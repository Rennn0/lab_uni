#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <chrono>
#include <cstring>
#include <fstream>
#include <typeinfo>
using namespace std;

int ID_count=1; // titoeul obieqts tavisi private ID eqneba

/*Black Scholes Model matematikuri formula
C=SN(d1)- Ke^(-rt)N(d2)
    sadac 
    d1=(ln_k_(S) + (r + (u^2)/2)t) / u(s)t^1/2
    d2=d1-u(s)t^1/2
C_call option price
// useris shemosatani mnishvnelobebi klasistvis
S_current stock
K_strike price
r_risk free interest rate
t_time to maturity
N_standard distribution
u_volatility
*/

class Bsm
{
    private:
        double S,K,R,T,U, result;
        int ID;
    public:
        Bsm(){ID=ID_count++; S=rand()%10001,K=rand()%10001,R=rand()%101,T=rand()%101,U=rand()%101, call_opt_price();}
        Bsm(double s,double k, double r, double t,double u)
        {ID=ID_count++; S=s,K=k,R=r,T=t, U=u, call_opt_price();}
        
        // wvdoma rom qonoda private wevrebze friend gavxade
        friend ostream& operator << (ostream& os, const Bsm& obj); 
        friend istream& operator >> (istream& is,Bsm& obj);
        friend bool operator < (const Bsm&, const Bsm&);
        friend bool operator > (const Bsm&, const Bsm&);
        
        // gadatvirtuli cout<< _is msgavsi iqneba 
        void print()const;
        
        // math go brrrr
        double call_opt_price();
};

inline void Bsm::print()const
    {
        string h(30,'*');
        cout<<h<<endl;
        cout<<"Object ID_"<<this->ID<<endl;
        cout<<"Current stock_"<<fixed<<setprecision(2)<<this->S<<endl;
        cout<<"Strike price_"<<fixed<<setprecision(2)<<this->K<<endl;
        cout<<"Risk free interest rate_"<<fixed<<setprecision(4)<<this->R<<endl;
        cout<<"Time to maturity(y)_"<<fixed<<setprecision(2)<<this->T<<endl;
        cout<<"Volatility_"<<fixed<<setprecision(4)<<this->U<<endl;
        cout<<"Call option price_"<<fixed<<setprecision(3)<<this->result<<endl;
    }

