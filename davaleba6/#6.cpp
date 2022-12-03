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
//pozicia -1
void pos__1();
//pozicia 0
void pos_0();
//pozicia 1
void pos_1();

// logika pointerebit wvdomistvis
// *(*(arr+i)+j)=int

int main()
{
    int array[10*step][step]; //array yvela nabijis shesanaxad
    filler(array);

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
