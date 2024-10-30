#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Function to calculate n! % MOD
long long factorial_mod(int n, int mod) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = result * i % mod;
    }
    return result;
}

// Function to compute the result using the recurrence relation
long long compute_result(int n) {
    // Base case
    if (n == 1) return 1;
    
    long long f = 1; // Base f(1)
    
    // Use the relation f(n) = f(n-1) * n
    for (int i = 2; i <= n; ++i) {
        f = (f * i % MOD + (i * (i - 1) / 2) % MOD) % MOD;
    }
    
    return f;
}

int main() {
    int n;
    cin >> n;

    // Calculate the result using the recurrence relation
    long long result = compute_result(n);

    // Output the result modulo 998244353
    cout << result % MOD << endl;

    return 0;
}
