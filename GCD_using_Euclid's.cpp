#include<iostream>
using namespace std;
int gcd(int a,int b);
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"The GCD of"<<a<<"and"<<b<<"is :";
    cout<<gcd(a,b);
    return 0;

}

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);

}
