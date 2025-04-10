fn sieve_of_eratosthenes(limit: usize) -> Vec<usize> {
    if limit < 2 {
        return Vec::new();
    }
    let mut is_prime = vec![true; limit + 1];
    is_prime[0] = false;
    is_prime[1] = false;
    for num in 2..=((limit as f64).sqrt() as usize) {
        if is_prime[num] {
            for multiple in (num * num..=limit).step_by(num) {
                is_prime[multiple] = false;
            }
        }
    }
    is_prime
        .iter()
        .enumerate()
        .filter_map(|(i, &prime)| if prime { Some(i) } else { None })
        .collect()
}
fn main() {
    let limit = 100;
    let primes = sieve_of_eratosthenes(limit);
    println!("Primes up to: {}: {:?}", limit, primes);
}
