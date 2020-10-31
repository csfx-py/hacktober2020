#include <iostream>

using namespace std;

int main()
{
    int n, k, ans = 0;
    int a[100];
    cin>>n;
    cin>>k;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        if((a[i] >= a[k-1]) && (a[i] > 0)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
