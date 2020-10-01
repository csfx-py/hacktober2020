/*
 * bubbleSort.cxx
 * 
 * Copyright 2020 rohit <rohit@DESKTOP-UQOMAVC>
 */


#include <iostream>
#include <vector>

using namespace std ;

void bubbleSort(vector<int> &arr) ;

int main(int argc, char **argv)
{
	
	vector<int> arr = {9,8,7,6,5,0,10,15,13,12,10,2,2,2,2,4,3,2,1,1} ;
	
	bubbleSort(arr) ;
	
	for(int k: arr) {
				cout << k << " " ;
	}
	
	return 0;
}

void bubbleSort(vector<int> &arr) {
	int n = arr.size() ;
	for(int i = 0 ; i < n ; i++) {
		bool isSorted = true ;
		for(int j = 0 ; j < n - i - 1 ; j++) {
			if(arr[j]>arr[j+1]){
				std::swap(arr[j],arr[j+1]) ;
				isSorted = false ;
			}
		}
		
		if(isSorted)
			break ;
		
	}
}

