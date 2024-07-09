package main

import (
	"fmt"
)

func sieve(n int) []int {
	array := make([]bool, n+1)
	for i := range array {
		array[i] = true
	}
	array[0] = false
	array[1] = false
	num := 0
	for i := 2; i*i <= n; i++ {
		if array[i] {
			num += 1
			for j := i * i; j <= n; j += i {
				array[j] = false
			}
		}
	}
	dops := make([]int, 0)
	for i := 0; i < len(array); i++ {
		if array[i] {
			dops = append(dops, i)
		}
	}
	return dops
}

func main() {
	r := sieve(1_000_000)

	fmt.Println(r)
}
