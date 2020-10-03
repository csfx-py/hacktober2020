#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){


   ll n;
   ll q;
cin>>n;
cin>>q;
   vector<ll>h(n);
   vector<ll>a(n);

   for(int i=0;i<n;i++){

      cin>>h[i];
   }

   for(int i=0;i<n;i++){
      cin>>a[i];
   }
// map<int,vector<ll>>mp;
   while(q--){

      ll b,c,k;

      cin>>b>>c>>k;

ll m= max(b,c);
ll mn= min(b,c);
int sum=0;


if(b==1){

  
   h[c-1]=k;
   a[c-1]=k;
   continue;
}

if(k>c){
   int cd=k;
   k=c;
   c=cd;
   
}
else{
if(c>k){
   for(int i=m-1;i>=mn-1;i--){

         if(h[i]>h[i-1]){

            sum+=a[i];

         }

      }}

       

if(sum>0){

   cout<<sum+a[b-1]<<" "<<"\n";
   cout<<a[c-1]<<" "<<endl;
}
else {

   cout<<"-1"<<"\n";
}
}
  

   }
 return 0;  
}