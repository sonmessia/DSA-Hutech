#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Calculate GCD of two numbers
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Calculate LCM of two numbers
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long M;
    cin >> N >> M;
    
    // Count remainders when divided by M
    vector<int> remainder_count(M);
    
    // Read numbers and process them
    for(int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        remainder_count[x % M]++;
    }
    
    // Calculate result using remainder counts
    long long result = 0;
    
    // Case 1: Process triplets (i,j,k) where (i*j*k) % M = 0
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            // Calculate required k
            long long prod = (1LL * i * j) % M;
            int k = 0;
            
            // Find k such that (prod * k) % M = 0
            if(prod == 0) {
                k = 0;
            } else {
                // For each remaining position k, we need (prod * k) % M = 0
                // Therefore, k must make prod * k divisible by M
                for(int possible_k = 0; possible_k < M; possible_k++) {
                    if((prod * possible_k) % M == 0) {
                        k = possible_k;
                        break;
                    }
                }
            }
            
            // Add contribution of this combination
            if(remainder_count[i] > 0 && remainder_count[j] > 0 && remainder_count[k] > 0) {
                // Handle cases when i, j, k are same or different
                if(i == j && j == k) {
                    // All three positions same
                    result += 1LL * remainder_count[i] * (remainder_count[i] - 1) * 
                             (remainder_count[i] - 2);
                }
                else if(i == j) {
                    // First two positions same
                    result += 1LL * remainder_count[i] * (remainder_count[i] - 1) * 
                             remainder_count[k] * 2;  // *2 for different orderings
                }
                else if(j == k) {
                    // Last two positions same
                    result += 1LL * remainder_count[i] * remainder_count[j] * 
                             (remainder_count[j] - 1);
                }
                else if(i == k) {
                    // First and last positions same
                    result += 1LL * remainder_count[i] * (remainder_count[i] - 1) * 
                             remainder_count[j];
                }
                else {
                    // All positions different
                    result += 1LL * remainder_count[i] * remainder_count[j] * 
                             remainder_count[k] * 6;  // *6 for all permutations
                }
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}