#include<bits/stdc++.h>
using namespace std;
 
int main(){
     long long int i,d=0,k,a,b=0,n;
     cin>>n>>k;
     for(i=0;i<n;i++)
     {
          cin>>a;
          b+=a;
          if(k>0)
          {
               if(b>=8)
               {
                    b-=8;
                    k-=8;
               }
               else
               {
                    k-=b;
                    b=0;
               }
               d++;
          }
     }
     if(k>0)
     {
          cout<<"-1";
     }
     else{
          cout<<d;
     }
     return 0;
}
