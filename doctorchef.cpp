#include<bits/stdc++.h>
#include<iostream>
#define lli long long int 
#define ll long long
#define sq(a) (a)*(a)
#define endl "\n"
#define pb push_back
#define v vector
#define mp make_pair
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define w() lli t; cin >> t; while(t--)
using namespace std;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n, x;
        cin >> n >> x;
        lli a[n];
        for (lli &x : a) {
            cin >> x;
        }
        int m;
        sort(a, a + n);
     


        // for (int i=0;i<n;i++){

        //     if(a[i]== n){

        //         cout<<n<<endl;
        //         return 0;
        //     }
        // }
      
        auto lower = lower_bound(a, a + n, x);

        
        lli b[n];
        lli i = 0;
        for (int j = lower - a; j < n; ++j) {
            b[i] = a[j];
            i++;
        }
        for (int k = 0; k < lower - a; ++k) {
            b[i] = a[k];
            i++;
        }
    //    for(auto x: b) {
    //        cout << x << " ";
    //    }
    //    cout<<"\n hello\n ";
    int d = 0;
        for (int i = 0; i < n; ++i) {
            while (x < b[i]) {
                d++;
                b[i]=min(b[i],(b[i]-x)*2);
                if(x>b[i])
                x = x * 2;
            }
            if (x >= b[i]) {
                d++;
                x = b[i];
                x = x * 2;
            }
        }


        cout << d << endl;
        // cout<<"Next tc\n";


    }
    return 0;
}