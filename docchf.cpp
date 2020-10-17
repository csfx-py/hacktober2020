#include <iostream>
#include<bits/stdc++.h>
#define ll long long 
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int fun(int g)
{
    return(2*g);
}

int main(){
/*
    int n;//input size
    cin >> n;
    int l=1;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    a.erase (a.begin() + l);

    for (auto x : a) {
        cout << x << " ";
    }
*/
    ll t;
    cin>>t;
    while(t-->0)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll>a(n);
        ll day = 0;
        ll h = 0;

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
       

        sort(a.begin(), a.end());
        while(!a.empty())
        {
            day++;
            if(a[h] <= x)
            {
                a.erase(a.begin());
                h++;
                
                 x=fun(x);
            }else if(a[h]>x){
                a[h]=min(a[h],(a[h]-x)*2);
                if(x>a[h])
                x=fun(x);
            }
        }

        cout << day <<endl;
    }
    return 0;
}