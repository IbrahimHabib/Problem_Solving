#include<iostream>
#include<string>

using namespace std;
int main()
{
    string balance,weight,L,R;
    cin>>balance;
    cin>>weight;
    int cross = balance.find('|');
    L = balance.substr(0,cross);
    R = balance.substr(cross+1,balance.size());
    for (auto &c : weight)
    {
        if (L.size() < R.size())
        {
            L += c;
        }
        else
        {
            R += c;
        }  
    }
    if (L.size() == R.size())
    {
        cout<<L + "|" + R <<endl;
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
    
    
    

}