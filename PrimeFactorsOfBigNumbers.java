//Java program to print prime 
// factors and their powers. 

class PrimeFactorsOfBigNumbers { 

// function to calculate all the 
// prime factors and count of 
// every prime factor 
	static void factorize(long n) { 
		int count = 0; 

		// count the number of times 2 divides 
		while (!(n % 2 > 0)) { 
			// equivalent to n=n/2; 
			n >>= 1; 

			count++; 
		} 

		// if 2 divides it 
		if (count > 0) { 
			System.out.println("2" + " " + count); 
		} 

		// check for all the possible 
		// numbers that can divide it 
		for (long i = 3; i <= (long) Math.sqrt(n); i += 2) { 
			count = 0; 
			while (n % i == 0) { 
				count++; 
				n = n / i; 
			} 
			if (count > 0) { 
				System.out.println(i + " " + count); 
			} 
		} 

		// if n at the end is a prime number. 
		if (n > 2) { 
			System.out.println(n + " " + "1"); 
		} 
	} 

	public static void main(String[] args) { 
		long n = 1000000000000000000L; 
		factorize(n); 
	} 
} 

