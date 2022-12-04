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
#define row     4 // anu 4 dge
#define column  5 // 5 monacemi tito dgistvis

random_device rnd;
default_random_engine gen(rnd());
uniform_real_distribution<double> dis(-.5,.5);
/*
    monacemis struqtura aseti iqneba
    
    yoveli wina dgis fasi iqneba momdevno dgis saangarishi X mnishvneloba
    mesame wevrad random mnishvneloba sheinaxeba
    [
        [ [x(r), y0 ,r , ry ,cvlileba %] [x=y0, y1 , r, ry,...] [x=y1, y2 , r, ry.. ] [x=y2, y3 ,r, ry] ]
        
        [ [] [] [] [] ]
        
        [ [] [] [] [] ] 
        .....
    ]

    grafiki y=1.01x+0.01
    random diapazoni [-1.5,1.5]
*/
typedef double dimensions[row][column];

void filler(dimensions *); // pointeri heapis pointerze, sawyisi X mnishvnelobebistvis
void dependence(dimensions *); // y mnishnvelobebistvis
void print(const dimensions *); // yvelafers gamoitans ekranze
double calc(const double); // grafikit mnishvnelobis gamotvla 
void prob(int * ,const dimensions *); // xelshemwyobi xdomilobebistvis


int main()
{
    /* 
        sul 20 dakvirveba
        titoeulshi 4 dgis monacemebi
        tito dges x y  random mnishvnelobeba da
        random mnishvnelobis mixedvit y, + cvlileba procentuli
    */
    
    dimensions *ptr=new dimensions[total];
    filler(ptr);
    dependence(ptr);
    print(ptr); // Diff. datvlilia imave dgis y(fx) da y(act) shoris
    
    // cxrilis ageba morcha
    // albatobis datvlistvis yovel bolo wevs shevadareb 0.5s
    // calke func iqneba amistvis
    
    int *pcount=new int; // default 0
    
    prob(pcount,ptr);  

    delete ptr, pcount;
    return 0;
}

void filler(dimensions *p) // yoveli arrays pirveli X wevri xdeba rand
{
    for(size_t t=0; t<total; t++)
        {
            *(*(*(p+t)))=rand()%3; // sawyisi mnishvneloba [1,4] shauledidan
            *(*(*(p+t))+1)=calc(*(*(*(p+t)))); // pirveli dgis aqciis fasi
        }
}   

void dependence(dimensions *p)
{
    for(size_t t=0; t<total; t++)
    {
        for(size_t r=1; r<row; r++) // x - y  monacemebis asheneba
            {
                *(*(*(p+t)+r))=*(*(*(p+t)+r-1)+1); // wina dgis x_ebze wvdoma
                *(*(*(p+t)+r)+1)=calc(*(*(*(p+t)+r)));  // y gamotvla
            }
        for(size_t r=0; r<row; r++) // calke loop random da y(random)_ebistvis
            {
                *(*(*(p+t)+r)+2)=dis(gen);
                *(*(*(p+t)+r)+3)=*(*(*(p+t)+r)+1)+*(*(*(p+t)+r)+2);
                double difference=(*(*(*(p+t)+r)+3)-*(*(*(p+t)+r)+1)) / *(*(*(p+t)+r)+1);
                *(*(*(p+t)+r)+4)=difference;
            }
    }
}

//  y=1.01x+0.01
double calc(const double x)
{
    return 1.01* x + 0.01;
}

void print(const dimensions *p)
{
    for(size_t t=0; t<total; t++)
    {
        cout<<"\nDay::"<<t+1<<"\nX\t\tY(f(x))\t\tRandom\t\tY(Actual)\tDiff. %";
        for(size_t r=0; r<row; r++)
        {
        cout<<endl;
            for(size_t c=0; c<column; c++)
            {
                if(c==4)
                {
                *(*(*(p+t)+r)+3)>*(*(*(p+t)+r)+1)?
                cout<<fixed<<setprecision(2)<<*(*(*(p+t)+r)+c)<<" ↑":
                cout<<fixed<<setprecision(2)<<*(*(*(p+t)+r)+c)<<" ↓";
                }
                else
                cout<<fixed<<setprecision(4)<<*(*(*(p+t)+r)+c)<<"\t\t"; 
            }
        }
        cout<<endl;
    }
}

    /*50% klebis shemtxveva nakklebad realuria
    amito matebis variantsac chavtvli*/ 
void prob(int *p, const dimensions *parr) 
{
    double z;
    for(size_t t=0;t<total;++t)
    {
        z=(*(*(*(parr+t)+3)+3)-*(*(*(parr+t))+1)) / *(*(*(parr+t))+1);
        if(abs(z)>=0.5)
        {
            ++*p;
            cout<<"Day :: "<<t+1<<endl;
        }
    }
    cout<<"Total _ "<<*p<<endl;
    
    cout<<"Probability _ "<<(double)*p/total<<'%'<<endl;
}