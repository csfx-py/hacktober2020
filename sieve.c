//This code compute the list of primes between 2 and N - 1 using the sieve algorithm that runs in O(nlogn)
#include <stdio.h>

#define N	100010
int is_composite[N];
int sz = 0;
int primes[N];

void sieve(){
	for(int i = 2 ; i * i < N ; i++){//Run until square root of N
		if(!is_composite[i]){//if 'i' is a prime number then mark all multiples of 'i' as a composite number
			for(int j = i + i ; j < N ; j += i){
				is_composite[j] = 1;
			}
		}
	}

	for(int i = 2 ; i < N ; i++){
		if(!is_composite[i]){
			primes[sz++] = i;
		}
	}
}

int main(){
	sieve();

	printf("we have %d primes between(2..%d)\n", sz, N - 1);
	printf("Showing the 40 first primes....:\n");

	for(int i = 0 ; i < 40 ; i++){
		printf("%d\n", primes[i]);
	}

	return 0;
}