/* Sequential Prime Number Calculation without Sieve of Eratosthenes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 100  // Upper limit for prime calculation

// Function to check if a number is prime
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find all prime numbers up to N
void find_primes_sequential() {
    clock_t start = clock();
    
    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            // Uncomment the next line to print primes
            printf("%d ", i);
        }
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n Sequential Execution Time: %.6f sec\n", time_taken);
}

int main() {
    printf("Finding Prime Numbers Sequentially:\n");
    find_primes_sequential();
    return 0;
}
