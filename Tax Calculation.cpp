#include <iostream>
using namespace std;
int main()
{
 int pay;
 int sum;
 cout<<"please enter your income"<<endl;
 cin>>pay;
 
 
 if(pay<=180000)
 {
 sum=pay*0.05;
 }
 else if(pay>180000 && pay<=300000)
 {
 sum=pay*0.07;
 }
 else if(pay>300000 && pay<=500000)
 {
 sum=pay*0.1;
 }
 else if(pay>500000 && pay<=750000)
 {
 sum=pay*0.12;
 }
 else if(pay<750000)
 {
 sum=pay*0.15;
 }
 cout<<"your imcome tax is "<<sum<<endl;
}
