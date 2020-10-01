/*
 * selectionSort.cxx
 * 
 * Copyright 2020 rohit <rohit@DESKTOP-UQOMAVC>
 */


#include <iostream>
#include <vector>

using namespace std ;

void selectionSort(vector<int> &arr) ;

int main(int argc, char **argv)
{
	
	vector<int> arr = {9,8,7,6,5,0,10,15,13,12,10,2,2,2,2,4,3,2,1,1} ;
	
	selectionSort(arr) ;
	
	for(int k: arr) {
				cout << k << " " ;
	}
	
	return 0;
}

void selectionSort(vector<int> &arr) {
	
	int n = arr.size() ;
	
	for(int i = 0 ; i < n ; i++ ) {
		int min = i ;
		for(int j = i ; j < n ; j++) {
			if(arr[j]<=arr[min]){
		//		swap(arr[i],arr[j]) ; 								//	Way ONE	;
				
				min = j ;												// Way TWO ;
				
			}
			
				
		}
		
		std:: swap(arr[i],arr[min]) ;									// Way TWO ;
	}
	
}

