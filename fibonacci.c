#include <stdio.h>

long long Fibonacci(long long n) { // Non-DP solution. O(2^n). Literally takes forever even for Fibonacci(50);
	
	if ((n==0) || (n==1)) { // Base cases
		return 1;
	}

	return Fibonacci(n-1) + Fibonacci(n-2); // Recursive non-DP solution

}

long long FibonacciDP(long long n,long long global_arr[], long long *size_arr_ptr) {
	/*
	 * DP solution. O(n). Doesn't sweat even for n=1000
	 * Fails from inputs > 90. Needs larger memory block
	 * Only first time/ when n is larger it calculates, meaning it will be O(1) for later, smaller calls.
	 * Minor memory use leads to significatly faster runtime
	 */

	/* Apparently,
	 * *size_arr_ptr++ != (*size_arr_ptr)++
	 * This is probably because we are incrementing the ptr instead of variable, which makes it point to higher numbers.
	 * This causes problems when you return it as an extra value through ptrs.
	 */

	if (*size_arr_ptr < n) {
		for (long long i=*size_arr_ptr+1;i<n+1;i++) {
			if ((i==0) || (i==1)) {// Base case
				global_arr[i] = 1;
				(*size_arr_ptr)++;
				continue;
			}
			global_arr[i] = global_arr[i-1] + global_arr[i-2]; // Storing solution in global array if we need to call it the next time
			(*size_arr_ptr)++;
		}
	}

	if (n<0) {
		return -1; // Invalid Request. (for now). Maybe a future algorithm can be done
	}

	return global_arr[n];

}

int main(void) {

	long long n;
	scanf("%lld", &n);

	long long globalarr[10000];
	long long calc_size = -1;

	long long nth_fib = FibonacciDP(n, globalarr, &calc_size); // Seperated from printf for readability

	printf("%lld\n",nth_fib);

}