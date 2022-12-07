#include "../lib.h"

void fill(vector<int>&);
void max_idx(vector<int>&,int&,int&);
int sum(vector<int>&);
double sash(vector<int>&);
double geom(vector<int>&);
void print(vector<int>&);

int main()
{
    srand(time(NULL));
    vector<int>vec;
    int v,x;
    fill(vec);
    print(vec);
    max_idx(vec,v,x);
    cout<<v<<" "<<x<<endl;
    cout<<sum(vec)<<endl;
    cout<<sash(vec)<<endl;
    cout<<geom(vec)<<endl;
}

void fill(vector<int>&v)
{
    int a, n;
    cout<<"n=";cin>>n;
        for(a=0;a<n;++a)
            v.push_back(rand()%101);
}
//
void max_idx(vector<int>&v, int& value, int& index)
{
    sort(v.begin(),v.end());
    value=v[v.size()-1];
    index=v.size()-1;
}
//
int sum(vector<int>&v)
{
    int jami=0;
    for(auto a:v)
        jami+=a;

    return jami;
}
//
double sash(vector<int>&v)
{
    int jami=0;
    for(auto a:v)
        jami+=a;
    
    return 1.*jami/v.size();
}
//
double geom(vector<int>&v)
{
    int jami=1;
    for(auto a:v)
        jami*=a;

    return pow(jami,1.*v.size());
}

void print(vector<int>&v)
{
    for(auto a:v)
        cout<<a<<" ";
    cout<<endl;
}