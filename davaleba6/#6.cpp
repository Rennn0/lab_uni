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

int* fill(int *); // xuti nabijis simulacia
void big_fill(int *);



int main()
{

    int array[step], big_boy[][step];
    fill(array);
}

int* fill(int *arr)
{
    cout<<"xuti nabiji -> ";
    for(int a=0;a<step;++a)
    {
        *arr=dis(gen);
        cout<<*arr++<<" ";
    }
    cout<<endl;
    return (int*)arr;
}

void big_fill(int *arr[step])
{
    
}