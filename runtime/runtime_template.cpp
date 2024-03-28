// Credits given to Dr. Tillquist.
#include <chrono>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isPrimeA(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int sumPrimesA(int n) {
    if (n < 2) {
        return 0;
    }
    int sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrimeA(i)) {
            sum += i;
        }
    }
    return sum;
}

bool isPrimeB(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int sumPrimesB(int n) {
    if (n < 2) {
        return 0;
    }
    int sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrimeB(i)) {
            sum += i;
        }
    }
    return sum;
}

long sieveOfEratosthenes(int n) {
    vector<int> primes(n - 2);
    for (int i = 2; i < n; i++) {
        primes[i - 2] = i;
    }
    for (int i = 2; i < sqrt(n); i++) {
        if (primes[i - 2] > 0) {
            for (int j = i * i; j < n; j += i) {
                primes[j - 2] = 0;
            }
        }
    }
    long sum = 0;
    for (int i = 0; i < primes.size(); i++) {
        sum += primes[i];
    }
    return sum;
}

void timePrimes();

int main() {
    int question = -1;
    cout << "Question: ";
    cin >> question;

    int n = 100;
    cout << "Sum: " << sumPrimesA(n) << endl;
    cout << "Sum: " << sumPrimesB(n) << endl;
    cout << "Sum: " << sieveOfEratosthenes(n) << endl;
    cout << "Time Primes" << endl;
    timePrimes();
    return 0;
}

void timePrimes() {
    int sum = -1;
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;
    double elapsed = -1;
    vector<int> x = {10, 100, 1000, 10000, 100000, 500000};
    for (int i = 0; i < x.size(); i++) {
        cout << "Value: " << x[i] << endl;

        start = chrono::high_resolution_clock::now();
        sum = sumPrimesA(x[i]);
        end = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << "A ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

        start = chrono::high_resolution_clock::now();
        sum = sumPrimesB(x[i]);
        end = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << "B ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

        start = chrono::high_resolution_clock::now();
        sum = sieveOfEratosthenes(x[i]);
        end = chrono::high_resolution_clock::now();
        elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << "C ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;
        cout << endl
             << endl;
    }

    cout << "Sieve of Eratosthenes on primes below 1 million" << endl;
    start = chrono::high_resolution_clock::now();
    long sum2 = sieveOfEratosthenes(1000000);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "Sum: " << sum2 << ", Time elapsed: " << elapsed << endl;
    cout << endl
         << endl;
}