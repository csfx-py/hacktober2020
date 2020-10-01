#include <iostream>
using namespace std;

int main ()
{
    int a;
    cout << "Enter the number: ";
    cin >> a;
    for (int i = 1; i <= 10; i++)
    {
        cout << (i * a) << endl;
    }
    return 0;
}
