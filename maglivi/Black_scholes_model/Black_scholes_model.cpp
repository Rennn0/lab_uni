#include "class.h"
#define CLEAR cout<<"\033[2J"; // ეკრანს გაწმენდს
#define BEGIN cout<<"\033[1;1H"; // კურსორს სათავეში დააბრუნებს

vector<Bsm>* DATA = new vector<Bsm>; // კლასების ვექტორი

void greet(); // მისალმება
void bsm_call(); // პარამეტრიან კლასს გამოიძახებს
void bsm_call_r(); // რანდომ მნიშვნელობებიან კლასს გააკეთებს
void opp(); // ოპერაციების მენიუ
void print_all(); // მთლიანი  კლასების ვექტორის დასაბეჭდად
void new_obj(); // კლასის პარამეტრიან კონსტრუქტორს გამოძახებს


int main()
{
    greet();
    char question; cin >> question; // ოპერაციის ბრძანების მისაღებად
g:
    if (question == 'y') // დავიწყოთ
    {
        CLEAR; BEGIN; opp();//ოეპრაციებს დაბეჭდავს

        while (cin >> question) // ბრძანებების მისაღებად
        {
            CLEAR; BEGIN; opp();
            switch (question) // სვიჩი ინფუთის შესაბამისად
            {
            case 'r': // რანდომ  აქცია
                bsm_call_r(); cout << endl << '_';
                break;
            case 'p': // გამოთვლის სიმულატორში გადავა
                CLEAR; BEGIN;
                bsm_call();
                opp();
                break;
            case 'd': // ინდექსს მოსთხოვს
                int id;
                cout << "\nID="; cin >> id;
                if (DATA->size() < id) // სისწორის შემოწმება,იდ [1,ზომა) ფარგლებშია
                {
                    cout << "\nobieqti mititebuli ID nomrit ar arsebobs\n_"; break;
                }
                cout << DATA->at(id - 1);
                break;
            case 'a':
                if (DATA->size() == 0) // შეამოწმებს არის თუარა წევრები ვექტორში
                {
                    cout << "araferia dasabechdi ://\n_"; break;
                }
                print_all(); // ყველას დაბეჭდავს
                break;
            case 's': // შედარების ბლოკი
                char c; CLEAR; BEGIN;
                cout << "ukve arsebulis tu axals gaaketeb (u/a)?"; cin >> c; // ორი არჩევანი
                if (c == 'u' && DATA->size() >= 2) //თუ ძველი უნდა + ბაზაში 2 ელემენტი მაინცაა 
                {
                    int id1, id2; // ორი ელემენტის აიდი
                    bool z; // > < = შემოწმებისთვის
                    cout << "ID1="; // პირველი ობიექტის აიდი
                    while (!(cin >> id1) || id1 > DATA->size()) // აიდების სისწორის შემოწმება
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "araswori ID\n_";
                    }
                    cout << "ID2="; // მეორე ობიექტის აიდი
                    while (!(cin >> id2) || id2 > DATA->size()) // ბოლო აიდის ნომერი ვექტორის სიგრძეა, ანუ მაგაზე მეტი ინფუთი არუნდაიყოს
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "araswori ID\n_";
                    }
                    cout << DATA->at(id1 - 1) << DATA->at(id2-1); // დაბეჭდავს ობიექტებს 
                    z = DATA->at(id1 - 1) > DATA->at(id2 - 1); // შედარებისთვის
                    if (z == true) // მარტივი იფ ელსი
                    {
                        cout << "\n\t\tobj ID" << id1 << "> ID" << id2 << '\n';
                    }
                    else if (z == false)
                    {
                        cout << "\n\t\tobj ID" << id1 << "< ID" << id2 << '\n';
                    }
                    else
                    {
                        cout << "\n\t\torive tolia\n";
                    }
                    opp(); // მენიუს გამოიტანს ისევ
                    cout << endl << '_';
                    break;
                }
                else if (c == 'a') // თუ ახალი უნდა
                {
                    CLEAR; BEGIN;

                    cout << "\npirveli obieqtebis shesaqmnelad miyevit instruqciebs:\n";
                    new_obj(); // პარამეტრიანი კონსტრუქტორი

                    cout << "\nmeore obieqtebis shesaqmnelad miyevit instruqciebs:\n";
                    new_obj();

                    cout << DATA->at(DATA->size() - 2) << DATA->at(DATA->size() - 1);
                    bool z = DATA->at(DATA->size() - 2) > DATA->at(DATA->size() - 1);

                    // უტოლობის გამოტანა ზევითას მსგავსად შემეძლო თუმცა ასე დავტოვებ
                    cout << endl << boolalpha << z << endl; 
                    // true მხოლოდ მეტობის შემთხვევაში იქნება
                    opp();
                    cout << endl << '_';
                    break;
                }
                else // თუ არც ძველი უნდა არც ახალი, ნუ რაღაც სხვა დაწერა
                {
                    cout << "araswori brdzaneba!";
                    opp();
                    cout << endl << '_';
                    break;
                }
            case '!': // პროგრამა გაჩერდება
                CLEAR; BEGIN;
                cout << "\nbye bye\n";
                exit(0);
            default: // შეცდომის დამფიქსირებელი, ანუ  შემოტანილი ჩარ არაფერს ემთხვევა
                cout << "\naraswori operacia\n";
            }
        }
    }
    else if (question == 'n') // არ დავუწყით
    {
        cout << "\n:(((((((((((((\n";
        exit(1);
    }
    else // რაღაც განსხვავებული დაიბეჭდა
    {
        cout << "\nragac shegeshala :| ";
        cin >> question;
        goto g; // ეს შეკითხვის რეჟიმში გადაიყვანს ისევ
    }
}

void greet() // მისალმების ფუნქცია
{
    string left(51, '#'), h(20, '-');
    cout << left << endl << h << "->Welcome<-" << h << endl << left << endl;
    cout << "\nPrograma Black_Scholes_Model Gamotvlebistvis\n"
        "daviwyot?? (y/n) _ ";
}
void bsm_call() // ჰიპზე შექმნილი კლასი შემდეგ ჰიპის ვექტორზევე იფუშება
{
    Bsm* ptr = new Bsm;
    cin >> *ptr;
    DATA->push_back(*ptr);
    cout << *ptr;
}

void bsm_call_r() // იგივე აქაც,ოღონდ რანდომ მნიშვნელობით
{
    Bsm* ptr = new Bsm;
    DATA->push_back(*ptr);
    cout << *ptr;
}

void opp() { // მენიუ
    cout << "\nShesadzlo operaciebi:\n\n";
    cout << left << setw(40) << "random BSM_ " << "r\n";
    cout << left << setw(40) << "parametriani BSM_ " << "p\n";
    cout << left << setw(40) << "dabechdva ID mixedvit_" << "d\n";
    cout << left << setw(40) << "yvelafris dabechdva_" << "a\n";
    cout << left << setw(40) << "shedareba aqciebis_" << "s\n";
    cout << left << setw(40) << "programis shesawyvetad_ " << "!\n";
}

void print_all()// ყველაფრის ბეჭდვა
{
    for (auto v : *DATA)
        v.print(); // ობიექტის პრინტ ფუნქციას გამოვიყენებ
}

void new_obj()
{
    double s, k, r, t, u; // ხუთივე პარამეტრი, შემდეგ სისწორის შემოწმებებია ყველასთვის
    cout << "Stock Price_";
    while (!(cin >> s) || s<0) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "error\n_";
    }
    cout << "strike Price_"; 
    while (!(cin >> k) || s<0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "error\n_";
    }
    cout << "risk free interest rate_"; 
    while (!(cin >> r) || r<0 || r>100)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "error\n_";
    }
    cout << "time_"; 
    while (!(cin >> t) || t<0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "error\n_";
    }
    cout << "volatility_";
    while (!(cin >> u) || u<0 || u>100)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "error\n_";
    }
    // ვექტორში ახალი ობიექტი დაიფუშება
    DATA->push_back(Bsm(s, k, r, t, u)); CLEAR; BEGIN;
}












