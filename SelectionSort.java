package sorting;

import java.util.Scanner;

public class SelectionSort {

	public static void main(String[] args) {
		
		int n;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter n: ");
		n = sc.nextInt();
		int a[] = new int[n];
		System.out.println("Enter Array: ");
		for(int i=0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		System.out.println("Array Before Sorting: ");
		for(int i:a) {
			System.out.print(i+" ");
		}
		for(int i=0;i<n-1;i++){
			boolean sort = true;
			int ind = i;
			for(int j=0;j<n;j++) {
				if(a[j]<a[ind]) {
					ind = j;
				}
			}
			int temp = a[ind];
			a[ind] = a[i];
			a[i] = temp;		
		}
		System.out.print("Array After Sorting: ");
		
		for(int i:a) {
			System.out.println(i+" ");
		}

	}

}
