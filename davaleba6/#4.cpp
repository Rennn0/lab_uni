// 6.2 დაწერეთ ფუნქცია, რომელიც რიცხვს გადაიყვანს ორობით სისტემაში. ფუნქციამ არგუმენტები უნდა მიიღოს რეფერენსით.
// მაგალითად, თუ მივაწვდით რიცხვს 1025 უნდა დაბეჭდოს 010000000001

#include <iostream>
#include <bitset> // chashenebuli metodistvis
using namespace std;

void dec_bin(const long int&);

int main(int argc, char* argv[])
{
    char *n=argv[1];
    dec_bin(atoi(n));  //es dasawyisshi 0 ar dausvavs ubralod
    
    // cout << std::bitset<12>(1025) << "\n";
    // sasurveli bitebis raodenobit 12... 34... 64 ect.
}

void dec_bin(const long int&n)
{
    int binary[64], num=n, i=0; // max 64 bitiani gardaqmnistvis
    for( ;num>0; ++i)
    {
        binary[i]=num%2;
        num/=2;
    }

    cout<<"Binary of "<<n<<" is ";
    for (int j = i - 1; j >= 0; j--)
    cout << binary[j];
    cout<<endl;
}

