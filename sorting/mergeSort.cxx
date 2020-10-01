/*
 * mergeSort.cxx
 * 
 * Copyright 2020 rohit <rohit@DESKTOP-UQOMAVC>
 */
 
#include<iostream>
#include<vector>
using namespace std ;

void mergeSort(vector<int> &arr, int low ,int high) ;
void mergeArray(vector<int> &arr,int low , int mid, int high) ;

int cost = 0 ;

int main(int argc, char **argv) {
	vector<int> arr = {9,8,7,6,5,4,3,2,1,-1,-2,-3,-4,-6} ;
	for(int i : arr)
		cout << i << " " ;
	
	mergeSort(arr,0,arr.size()-1) ;
	cout << "\n" ;
	for(int i : arr)
		cout << i << " " ;
	cout << "\n" << cost ;
	
	return 0 ;
}

void mergeSort(vector<int> &arr, int low ,int high) {
	if( low<high ){
		cost++ ;
		int mid = low + (high-low)/2 ;
		mergeSort(arr,low,mid) ;
		mergeSort(arr,mid+1,high) ;
		mergeArray(arr,low,mid,high) ;
		
	}
}
void mergeArray(vector<int> &arr,int low , int mid, int high) {
	int i=0 ,j=0 , k;
	int n1 = mid -low +1 ;
	int n2 = high - mid ;
	int arr1[n1] ,arr2[n2] ;
	
	while(i<n1) {
		cost++ ;
		arr1[i] = arr[low + i ] ;
		i++ ;
	}
	while(j<n2){
		cost++ ;
		arr2[j] = arr[mid + j + 1] ;
		j++ ;
	}
	i = 0 ,j = 0 ;
	k = low ;
	while ( i < n1 && j < n2 ){
		cost++ ;
		if(arr1[i] <= arr2[j])
			arr[k++] = arr1[i++] ;
		
		else
			arr[k++] = arr2[j++] ;
	}
	
	while ( i < n1 ){
			arr[k++] = arr1[i++] ;
	}
	
	while ( j < n2 ){
			arr[k++] = arr2[j++] ;
	}
	 
}
	
