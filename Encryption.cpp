#include<bits/stdc++.h>
using namespace std;
string encrypt(string s)
{
    int n = s.length();
    string res = "";
    for(int i=0;i<n;i++)
    {
        int ascii = ((s[i] - 'v') + (i*i*i)%256)%256;
        res += char(ascii);
    }
    return res;
}

string decode(string  s)
{
    int n = s.length();
    string res = "";
    for(int i=0;i<n;i++)
    {
        int ascii =  ((s[i] - (i*i*i))%256 + 'v') % 256;
        res += char(ascii);
    }
    return res;
}
int main()
{
    string s;
    cout<<"Enter plain text : ";
    cin>>s;
    s = encrypt(s);
    cout<<"Encoded : "<<s<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Decoded : "<<decode(s)<<endl;
    return 0;
}