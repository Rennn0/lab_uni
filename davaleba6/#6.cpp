// 6.4 შექმენით Random Walk რიცხვით ღერძზე.
// მოძრაობას იწყებს 0 წერტილიდან:
// -1 - მოძრაობა მარცხნივ
// 0 - იგივე ადგილზე დარჩენა
// 1 - მოძრაობა მარჯვნივ
// საერთო ჯამში გავაკეთებინოთ 5 ნაბიჯი და ვნახოთ ამ ოთხი ნაბიჯის შემდეგ რომელ წერტილზე იქნება.
//  დაითვალეთ თითოეულ პოზიციაზე ყოფნის ალბათობები 5 სვლის შემდეგ.
// გამოიყენეთ პოინტერები ან/და რეფერენსები. შექმენით საჭირო ფუნქციები და მასივები გადაეცით
//  ფუნქციის არგუმენტებად.  ყურადღება მიაქციეთ const და non-const პარამეტრებს. 
//  სადაც მხოლოდ წაკითხვა გჭირდებათ, მიუთითეთ const.

#include <iostream>
#include <random>
using namespace std;

random_device rnd;
default_random_engine gen(rnd());
uniform_int_distribution<int> dis(-1,1);

#define step 5

void filler(int [][step]); // xuti nabijis simulacia
void positions(int [][step], int*,int*,int*);//poziciebi -1 0 1

// logika pointerebit masivis wevrebze wvdomistvis
// *(*(arr+i)+j) = ragac

int main()
{
    // mcdelobebis raodenoba hardcoded aris, vfiqrob 
    // optimizacia usargeblo iqneboda, amito darches ase...

    int array[10*step][step]; //array yvela nabijis shesanaxad
    
    int minus_one=0, zero=0, one=0,  // bolo koordinatebis mnishvnelobebs sheinaxaven 
        sul=10*step;  // 50 mcdeloba sul
    filler(array);
    positions(array, &minus_one, &zero, &one);

    cout<<"Albatoba -1 = "<<1.*minus_one/sul<<endl;
    cout<<"Albatoba  0 = "<<1.*zero/sul<<endl;
    cout<<"Albatoba  1 = "<<1.*one/sul<<endl;

}

void filler(int arr[][step]) // sheavsebs arrays random nabijebit
{
    for(size_t n = 0; n < 10*step ; ++n)
    {
        for(size_t m=0; m< step; ++m)
        {
            *(*(arr+n)+m)=dis(gen);
        }
    }
    cout<<endl;
}

void positions(int arr[][step], int* neg,int* nul,int* pos)
{
    //titoeuli striqonis bolo wevrs shevamowmeb 
    //da shesabamis cvladebis mnishvnelobebs gavzrdi

    for(size_t t=0; t<50;++t)
    {
        if(*(*(arr+t)+step-1)==-1)
            ++*neg;
        else if(*(*(arr+t)+step-1)==0)
            ++*nul;
        else    
            ++*pos;
    }
}