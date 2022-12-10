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

standartuli gadaxris datvla chemit momiwevs vatyob

u=s=sqrt((E(x-x*)^2)/n)

ert klasshi gadavtvirtav yvela operators da gamotvelbis metodebsac gavaketeb
bolos shevxedav tu gamova calcake klasebsshi gavaketeb gamotvlebs da friendebad gamovacxadeb

*/

class Bsm
{
    private:
        double S,K,R,T;
        int ID;
    public:
        Bsm(){ID=ID_count++; S=0,K=0,R=0,T=0;}
        Bsm(double s,double k, double r, double t)
        {ID=ID_count++; S=s,K=k,R=r,T=t;}
        
        // wvdoma rom qonoda private wevrebze friend gavxade
        friend ostream& operator << (ostream& os, const Bsm& obj); 
        friend istream& operator >> (istream& is,Bsm& obj);
        //shedarebis operatorsac gadavtvirav ori obieqtistvis


};