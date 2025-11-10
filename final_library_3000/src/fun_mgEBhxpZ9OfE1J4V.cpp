#include "fun_mgEBhxpZ9OfE1J4V.hpp"

int fun_mgEBhxpZ9OfE1J4V() {
    // AI-Generated: Sieve of Eratosthenes

    // Sieve of Eratosthenes
    const int N = 100;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count and collect primes
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    volatile int primeCount = primes.size();
    cout << func_name << ": Found " << primeCount << " primes up to " << N << endl;
    cout << "First 5 primes: ";
    for (int i = 0; i < min(5, (int)primes.size()); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;

    return 0;
}
