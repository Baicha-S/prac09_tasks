#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1'000'000;

template <typename T>
void my_print(const vector<T>& vec)
{
    for (const T& val: vec) {
        cout << val << ", ";
    }
    cout << endl;
}

// def sieve_of_eratosthenes(limit):
vector<int> sieve_of_eratosthenes(int limit) {
    vector<bool> prime(limit + 1, true);  
    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }

    vector<int> prime_numbers;
    for (int p = 2; p <= limit; p++) {
        if (prime[p])
            prime_numbers.push_back(p);
    }
    return prime_numbers;
}


// def isCircularPrime(n):
bool isCircularPrime(int n, const set<int>& primes_set) {
    string s = to_string(n);
    int n_rolls = s.length() - 1;  
    for (int i = 0; i < n_rolls; i++) {        
        s += s[0];            
        s.erase(s.begin());  
        int new_n = stoi(s);  
        if (primes_set.find(new_n) == primes_set.end())
            return false;
    }

    return true;
}

// def main():
int main(int argc, char const *argv[])
{
    cout << "Start\n";

    auto primes = sieve_of_eratosthenes(MAX_N);
    my_print(primes);
    set<int> primes_set;
    for (const auto& val :primes) 
    {
        primes_set.insert(val);
    }
    int res = 0;
    for (int n : primes) 
    {
        if (isCircularPrime(n, primes_set)) {
            res++;
            cout << "n=" << n << ", res=" << res << endl;
        }
    }
    cout << "DONE" << endl;
    cout << "Total Circular Primes: " << res << endl;
    return 0;
}
