#include <format>
#include <iostream>
#include <vector>

std::vector<int64_t> sieve(int64_t limit) {
    if (limit < 2) {
        return {};
    }
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (std::size_t i = 2; i * i < is_prime.size(); i++) {
        if (is_prime[i]) {
            for (std::size_t j = i * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }
    std::vector<int64_t> primes;
    for (std::size_t i = 0; i < is_prime.size(); i++) {
        if (is_prime[i]) {

            primes.push_back(static_cast<int64_t>(i));
        }
    }
    return primes;
}

int main(int argc, char **argv) {
    std::vector<int64_t> primes = sieve(1000LL);
    std::string acc;
    for (std::size_t i = 0; i < primes.size(); i++) {
        acc +=
            std::format("{}{}", primes[i], i == primes.size() - 1 ? '\n' : ' ');
    }
    std::cout << acc << std::endl;

    return 0;
}
