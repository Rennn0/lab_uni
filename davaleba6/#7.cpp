// 6.5 შექმენით Random Walk-ის სიმულაცია 2 განზომილებაში აქციის ფასებისთვის.
// აიღეთ თქვენთვის სასურველი ნებისმიერი კომპანიის აქცია და აქციის დღიური ფასი.
// შეგიძლიათ ფასები მარტივად იპოვოთ გუგლით: „კომპანიის სახელი“ stock price
// გააკეთეთ აქციების ყოველდღიური ფასის სიმულირება. 
// დავუშვათ, რომ აქციის ფასი მიყვება წრფივ ტრენდს და გამოიხატება შემდეგი პარამეტრებით:
// ფასი(შემდეგი დღე)= a*ფასი(წინა დღე)+b+rand
// a და b პარამეტრები თავად განსაზღვრეთ თქვენ მიერ არჩეულ აქციის ფასსზე დაყრდნობით.
// rand პარამეტრი არის შემთხვევითი პარამეტრი.
// დაითვალეთ, რა იქნება აქციის მოსალოდნელი ფასი და შესაბამისი ალბათოები 4 დღის შემდეგ?
// რომელია ყველაზე მოსალოდნელი ფასი? რა არის იმის ალბათობა, რომ ფასი 50%-ით შემცირდეს?
// აუცილებლად გამოიყენეთ დინამიური მეხსიერება.
// შექმენით შესაბამისი ფუნქციები და არგუმენტებად გადაეცით მისამართები. 
// ყურადღება მიაქციეთ const და non-const პარამეტრებს.
// სადაც მხოლოდ წაკითხვა გჭირდებათ, მიუთითეთ const.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
using namespace std;

#define total   20
#define row     4
#define column  4

random_device rnd;
default_random_engine gen(rnd());
uniform_real_distribution<double> dis(-0.5,0.5);
/*
    monacemis struqtura aseti iqneba
    
    yoveli wina dgis fasi iqneba momdevno dgis saangarishi X mnishvneloba
    mesame wevrad random mnishvneloba sheinaxeba
    [
        [ [x(r), y0 ,r , ry] [x=y0, y1 , r, ry] [x=y1, y2 , r, ry ] [x=y2, y3 ,r, ry] ]
        
        [ [] [] [] [] ]
        
        [ [] [] [] [] ] 
        .....
    ]

    grafiki y=1.05x+0.25
    random diapazoni [-0.5,0.5]
*/
typedef double dimensions[row][column];

void filler(dimensions *); // pointeri heapis pointerze, sawyisi X mnishvnelobebistvis
void dependence(dimensions *); // y mnishnvelobebistvis
void print(const dimensions *); // yvelafers gamoitans ekranze
double calc(const double); 

int main()
{
    /* 
        sul 20 dakvirveba
        titoeulshi 4 dgis monacemebi
        tito dges x y  random mnishvnelobeba da
        random mnishvnelobis mixedvit y
    */
    dimensions *ptr=new dimensions[total];
    filler(ptr);
    dependence(ptr);
    print(ptr);
        
}

void filler(dimensions *p) // yoveli arrays pirveli X wevri xdeba rand
{
    for(size_t t=0; t<total; t++)
        {
            *(*(*(p+t)))=rand()%3-1; // sawyisi mnishvneloba [-1,1] shauledidan
            *(*(*(p+t))+1)=calc(*(*(*(p+t)))); // pirveli dgis aqciis fasi
        }
}   

void dependence(dimensions *p)
{
    for(size_t t=0; t<total; t++)
        for(size_t r=1; r<row; r++) // pirveli dgis 
            {
                *(*(*(p+t)+r))=*(*(*(p+t)+r-1)+1);
                *(*(*(p+t)+r)+1)=calc(*(*(*(p+t)+r))); 
                *(*(*(p+t)+r)+2)=dis(gen);
            }

}

//  y=1.05x+0.25
double calc(const double x)
{
    return 1.05 * x + 0.25;
}

void print(const dimensions *p)
{
    for(size_t t=0; t<total; t++)
    {
        cout<<"\nDay "<<t+1<<"\nX\t\tY(f(x))\t\tRandom\t\tY(Random)";
        for(size_t r=0; r<row; r++)
        {
        cout<<endl;
            for(size_t c=0; c<column; c++)
            {
                cout<<fixed<<setprecision(4)<<*(*(*(p+t)+r)+c)<<"\t\t";
            }
        }
        cout<<endl;
    }
}