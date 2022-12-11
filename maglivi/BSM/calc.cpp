// gamotvlebistvis
#define e 2.71828
#define p 3.14159

inline double Bsm::call_opt_price()
{
    double 
        d1=(log10(S)-log10(K)+(R+U*U/2)*T)/U/sqrt(T),
        d2=d1-U*sqrt(T),
        top1=(-1/2)*pow(d1/U,2),
        top2=(-1/2)*pow(d2/U,2),
        N1=pow(e,top1)/U/sqrt(2*p),
        N2=pow(e,top2)/U/sqrt(2*p),

        answer=S*N1-K*pow(e,-R*T)*N2;
    
    return result=answer;
}
