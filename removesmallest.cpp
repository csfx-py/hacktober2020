#include <bits/stdc++.h>
using namespace std;
 
int main() {
     int t,a[50],n,i,j,d;
     cin>>t;
     for(i=0;i<t;i++) {
          cin>>n;
          for(j=0;j<n;j++) {
               cin>>a[j];
          }
          sort(a,a+n);
          d=0;
          while(abs(a[d]-a[d+1])<=1 && d<n-1){
               d++;
          }
          if(d==n-1)
          {
               cout<<"YES\n";
          }
          else {
               cout<<"NO\n";
          }
     }
     return 0;
}
