#include <iostream>
using namespace std;;

bool isPal(string str, int s, int e){
    if (s==e) return true;
    if (s>e) return true;
    if(str[s] != str[e]) return false;
    return isPal(str, s+1, e-1);
}

int main(){
    string s;
    cin >> s;
    if (isPal(s, 0, s.length()-1)){
        cout << "True";
    } else {
        cout << "False";
    }
}