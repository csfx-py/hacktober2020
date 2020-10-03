#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> counting(int n){

vector<int> a(n+1);

a[0]=0;
for(int i=1;i<=n;i++)
a[i]=a[i&(i-1)]+1;

return a;

}

int main(){

    int n;
    n= 5;
    counting(n);
    
}