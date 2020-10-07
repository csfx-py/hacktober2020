#include <bits/stdc++.h>

using namespace std;

int main()
{
   string str="Rishabh Jha";
   cout << "Main string: " << str << endl;

   transform(str.begin(), str.end(), str.begin(), ::tolower);
   cout << "\nLower Case String: " << str << endl;

   transform(str.begin(), str.end(), str.begin(), ::toupper);
   cout << "\nUpper Case String: " << str << endl;
}
