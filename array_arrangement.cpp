/*"Given an array of integers A, arrange them in an alternate fashion such that every non-negative number
is followed by negative and vice-versa, starting from a negative number, maintaining the order of appearance.
The number of non-negative and negative numbers need not be equal.

If there are more non-negative numbers they appear at the end of the array.
If there are more negative numbers, they too appear at the end of the array."*/

#include<iostream>
using namespace std;

void arrange(int *a, int n){
	int *temp= new int(n);
	int pos=0,neg=0;
	for(int i=0;i<n;i++){
		if(a[i]<0)
		neg++;
		else if(a[i]>0)
		pos++;
		else
		throw "Zero is not allowed";
		temp[i]=a[i];
	}
	if(pos<neg){
		int i=0,j=1;
		for(int k=0;k<n;k++){
			if(temp[k]<0){
				a[i]=temp[k];
				if(k<pos*2)
				i+=2;
				else
				i++;
			}
			else{
				a[j]=temp[k];
				j+=2;
			}
		}
	}
	else{
		int i=0,j=1;
		for(int k=0;k<n;k++){
			if(temp[k]>0){
				a[j]=temp[k];
				if(k<neg*2)
				j+=2;
				else
				j++;
			}
			else{
				a[i]=temp[k];
				i+=2;
			}
		}
	}
	
}

void printArray(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int *a;
	int n;
	cout<<"Enter Number of Elements"<<endl;
    cin>>n;
    a = new int(n);
    cout<<"Enter Elements"<<endl;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	try{
	arrange(a,n);
	printArray(a,n);
	}catch (char const* msg) {
     cout<< msg << endl;
    }
	return 0;
}
