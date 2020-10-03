/ C++ program to check if it is 
// possible to split string or not 
#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 26; 

// function to check if we can spilt 
// string or not 
bool checkCorrectOrNot(string &s) 
{ 
	// Counter array inisialized with 0 
	int count[MAX_CHAR] = {0}; 

	// Length of the string 
	int n = s.length(); 
	if (n == 1) 
		return true; 

	// traverse till the middle element 
	// is reached 
	for (int i=0,j=n-1; i<j; i++,j--) 
	{ 
		// First half 
		count[s[i]-'a']++; 

		// Second half 
		count[s[j]-'a']--; 
	} 

	// Checking if values are different 
	// set flag to 1 
	for (int i = 0; i<MAX_CHAR; i++) 
		if (count[i] != 0) 
			return false; 

	return true; 
} 

// Driver program to test above function 
int main() 
{   
    int t;
    cin>>t;
    
    while(t--){
    string s;
   
	// String to be checked 
   
    cin>>s;
    
   
	if (checkCorrectOrNot(s)) 
		cout << "Yes\n"; 
	else
		cout << "No\n"; 
      
    }
	return 0; 
    
  
} 