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

void filler(int *[][step]); // xuti nabijis simulacia

// *(*(arr+i)+j)=int

int main()
{
    int *array[10*step][step];
    filler(array);
    cout<<array[0][1];
}

void filler(int *arr[][step])
{
    for(size_t n = 0; n < sizeof(arr)/sizeof(int) ; ++n)
    {
        for(size_t m=0; m< step; ++m)
        {
            *(*(arr+n)+m)=(int*)dis(gen);
        }
    }
}
