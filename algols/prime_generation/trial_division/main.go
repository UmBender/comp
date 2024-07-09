package main

import (
	"fmt"
)

func trivial_division(n uint64) []uint64 {
	primes := make([]uint64, n)
	if n < 1 {
		return []uint64{}
	}
	if n == 1 {
		return []uint64{2}
	}
	primes[0] = 2
	primes[1] = 3
	i := uint64(2)
	val := primes[1] + 2
	for i < n {
		find := false
		for j := 0; !find && val >= primes[j]*primes[j]; j++ {
			if val%primes[j] == 0 {
				find = true
			}
		}
		if !find {
			primes[i] = val
			i++
		}
		val += 2
	}
	return primes
}
func main() {
	p := trivial_division(1_000)
	for i := range p {
		fmt.Print(i," ")

	}

}
