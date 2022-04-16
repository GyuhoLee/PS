package main

import (
	"fmt"
	"math"
)

var N, answer int

type thing struct {
	sour, bitter int
}

var things [10]thing

func main() {
	answer = math.MaxInt32
	fmt.Scanln(&N)
	for i := 0; i < N; i++ {
		fmt.Scanln(&things[i].sour, &things[i].bitter)
	}
	solve(0, 1, 0)
	fmt.Print(answer)
}

func solve(idx int, S int, B int) {
	if idx == N {
		if S+B == 1 {
			return
		}
		diff := math.Abs(float64(S - B))
		answer = int(math.Min(diff, float64(answer)))

		return
	}
	solve(idx+1, S, B)
	solve(idx+1, S*things[idx].sour, B+things[idx].bitter)
}
