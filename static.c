#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define LIMIT 100  // Define upper limit for prime calculation

// Function to check if a number is prime
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void find_primes_parallel(int num_threads) {
    int prime_count = 0;

    // Set the number of threads
    omp_set_num_threads(num_threads);

    double start_time = omp_get_wtime();  // Start time

    #pragma omp parallel for schedule(static) shared(prime_count)
    for (int i = 2; i <= LIMIT; i++) {
        if (is_prime(i)) {
            #pragma omp critical  // Ensure safe printing in parallel execution
            printf("%d ", i);  // Print prime number

            // Atomic operation to safely increment the counter
            #pragma omp atomic
            prime_count++;
        }
    }

    double end_time = omp_get_wtime();  // End time

    printf("\nExecution Time with %d threads: %.6f seconds\n\n", num_threads, end_time - start_time);
}

int main() {
    int thread_counts[] = {1, 2, 4, 8};  // Test with different thread numbers

    for (int t = 0; t < 4; t++) {
        printf("Running with %d threads:\n", thread_counts[t]);
        find_primes_parallel(thread_counts[t]);
    }

    return 0;
}
