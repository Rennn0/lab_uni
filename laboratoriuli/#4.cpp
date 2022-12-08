#include "../lib.h"

void fill(vector<int>&);
void print(vector<int>&);
int first_match(vector<int>&);
int last_match(vector<int>&);

int main()
{
    vector<int>vec; 
    fill(vec);
    cout<<first_match(vec)<<endl;
    cout<<last_match(vec)<<endl;
}


void fill(vector<int>&v)
{
    srand(time(NULL));
    int a, n;
    cout<<"n=";cin>>n;
        for(a=0;a<n;++a)
            v.push_back(rand()%101);
    
    print(v);
}

void print(vector<int>&v)
{
    for(auto a:v)
        cout<<a<<" ";
    cout<<endl;
}

int first_match(vector<int>&v)
{
    int match, idx;
    cout<<"Search for _ ";cin>>match;
    idx=find(v.begin(),v.end(),match)-v.begin();
    
    if(idx!=v.size())
        return idx;
    else 
        return v.size();
}
int last_match(vector<int>&v)
{
    short num, n;
    cout<<"Search last match of _ ";cin>>n;
    for(num=v.size()-1;num>=0;--num)
        {
            if(v[num]==n && v[num]%2==1)
            {
                return num;
            }
        }
    return v.size();
}