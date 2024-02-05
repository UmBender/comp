#include <iostream>
#include <list>
#include <string>
#include <vector>

long long compute_hash(std::string &s) {
  const long long p = 31;
  const long long m = 1e9 + 9;

  long long hash_value = 0;
  long long p_pow = 1;

  for (auto c : s) {
    hash_value = (hash_value + (c - 'A' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

int main(int argc, char **argv) {
  std::string s = "Hello";
  std::cout << compute_hash(s) << std::endl;

  return 0;
}
