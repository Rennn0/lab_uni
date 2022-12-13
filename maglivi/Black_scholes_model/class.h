#include <iostream>
#include <iomanip>
#include <random>
#include <limits>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstring>
using namespace std;

#define e 2.71828
#define p 3.14159

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
u_volatility

დეტალურად  ბოლოში

გამოთვლებში სხვაობაა ონლაინ კალკულატორთან შედარებით
ფორმულა იგივეა , დივიდენდებს არ ვიყენებ  მხოლოდ,
შეცდომას ვერ ვხედავ, ერთი ვარიანტი N  განაწილების გამოთვლაშია
ხარვეზი სავარაუდოდ
*/
random_device rnd; // რანდომ მნიშვნელობებს ამოყრის კლასისთვის
default_random_engine gen(rnd());
uniform_real_distribution<double>dis(0, 100);

int ID_count = 1; // გლობალური აიდი

class Bsm
{
private:
    double S, K, R, T, U, result; // რესულტ  ბოლოს დაითვლება და მიენიჭება მნიშვნელობა ავტომაურად
    int ID; // ყველა ობიექტს ინდივიდუალური აიდი ექნება
public:
    Bsm() { ID = ID_count++; S = dis(gen), K = dis(gen), R = dis(gen), T = dis(gen), U = dis(gen), call_opt_price(); } // რანდომ მნიშვნელობები მიენიჭებათ და რესულტიც ესე დაიტვლება
    Bsm(double s, double k, double r, double t, double u)
    {
        ID = ID_count++; S = s, K = k, R = r, T = t, U = u, call_opt_price();
    } // კლასის გამოცხადებისას მინიჭებული პარამეტრებით

// wvdoma rom qonoda private wevrebze friend gavxade
    friend ostream& operator << (ostream& os, const Bsm& obj);
    friend istream& operator >> (istream& is, Bsm& obj);
    friend bool operator < (const Bsm&, const Bsm&);
    friend bool operator > (const Bsm&, const Bsm&);

    // gadatvirtuli cout<< _is msgavsi iqneba 
    void print()const;

    // math go brrrr
    double call_opt_price();
};

//ბეჭდვის ფუნქცია

inline void Bsm::print()const
{
    string h(30, '*');
    cout << h << endl;
    cout << "Object ID_" << this->ID << endl;
    cout << "Current stock_" << fixed << setprecision(2) << this->S << endl;
    cout << "Strike price_" << fixed << setprecision(2) << this->K << endl;
    cout << "Risk free interest rate_" << fixed << setprecision(4) << this->R << endl;
    cout << "Time to maturity(y)_" << fixed << setprecision(2) << this->T << endl;
    cout << "Volatility_" << fixed << setprecision(4) << this->U << endl;
    cout << "Call option price_" << fixed << setprecision(3) << this->result << endl;
}

// gadavtvirtav cin cout operaciesbs klasis input outputistvis , ასევე < და   >
istream& operator >> (istream& is, Bsm& obj)
{
    string h(30, '-');
    double s, k, r, t, u;
    cout << "\nBlack-Scholes Model simulator \n"
        << h << "\nshemoitanet monacemebi gamotvlebistvis" << endl;

    cout << left << setw(30) << "Current stock_";
    // shezgudva daedeba yvelanair inputs garda double_sa
    // 2saati am metodis dzebnas movundi -_____-

    while (!(is >> s) || s < 0)
    {
        is.clear(); // buffers gaasuftavebs
        is.ignore(numeric_limits<streamsize>::max(), '\n'); // gaabatilebs mtlian inputs sanam axali xazi ar shexvdeba
        cout << "shemoitane validuri mnishvneloba_"; // shecdomis dzaxili, mere tavidan daawerinebs
    }

    cout << left << setw(30) << "Strike price_";
    while (!(is >> k) || k < 0)
    {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "shemoitane validuri mnishvneloba_";
    }

    cout << left << setw(30) << "Risk free interest rate_";
    while (!(is >> r) || r < 0 || r>100)
    {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "shemoitane validuri mnishvneloba_";
    }

    cout << left << setw(30) << "Time to maturity(y)_";
    while (!(is >> t) || t < 0)
    {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "shemoitane validuri mnishvneloba_";
    }

    cout << left << setw(30) << "Volatility_";
    while (!(is >> u) || u < 0)
    {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "shemoitane validuri mnishvneloba_";
    }

    obj.S = s; obj.K = k; obj.R = r; obj.T = t, obj.U = u; obj.call_opt_price();
    // shemedzlo obj=Bsm(s,k,r,t,u) gameketebina da friend wvdoma ar damchirdeboda
    // magram operacia axali obieqtis sheqmnad chaitvleboda da globalur ID awevda
    // gadatvirtva razec gamovidzaxe im obieqtis IDc sheicvleboda
    return is;
}

ostream& operator << (ostream& os, const Bsm& obj)
{
    string h(30, '*');

    os << h << "\nObject ID_" << obj.ID << "\nmonacemebi:";
    os << left << setw(30) << "\nCurrent stock_" << fixed << setprecision(2) << obj.S;
    os << left << setw(30) << "\nStrike price_" << fixed << setprecision(2) << obj.K;
    os << left << setw(30) << "\nRisk free interest rate_" << fixed << setprecision(4) << obj.R;
    os << left << setw(30) << "\nTime to maturity(y)_" << fixed << setprecision(2) << obj.T;
    os << left << setw(30) << "\nVolatility_" << fixed << setprecision(4) << obj.U;
    os << left << setw(30) << "\nCall option price_" << fixed << setprecision(3) << obj.result << endl;
    return os;
}

bool operator < (const Bsm& obj1, const Bsm& obj2)
{
    return obj1.result < obj2.result;
}

bool operator > (const Bsm& obj1, const Bsm& obj2)
{
    return obj1.result > obj2.result;
}

// გამოთვლა  საბოლოო მნიშვნელობის
inline double Bsm::call_opt_price()
{
    double
        d1 = (log10(S) - log10(K) + (R + U * U / 2) * T) / U / sqrt(T),
        d2 = d1 - U * sqrt(T),
        top1 = -(1 / 2) * pow(d1 / U, 2),
        top2 = -(1 / 2) * pow(d2 / U, 2),
        N1 = pow(e, top1) / U / sqrt(2 * p),
        N2 = pow(e, top2) / U / sqrt(2 * p),

        answer = S * N1 - K * pow(e, -R * T) * N2;

    return result = answer;
}


