package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

func nextInt() (res int) {
	sc.Scan()
	text := sc.Text()
	v, _ := strconv.Atoi(text)
	return v
}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()

	T := nextInt()
	for i := 0; i < T; i++ {
		N := nextInt()
		M := nextInt()
		var A, B []int
		for j := 0; j < N; j++ {
			tmp := nextInt()
			A = append(A, tmp)
		}
		for j := 0; j < M; j++ {
			tmp := nextInt()
			B = append(B, tmp)
		}

		sort.Ints(A)
		sort.Ints(B)

		sum := 0
		ptrA := 0
		ptrB := 0
		for ; ptrA < N; ptrA++ {
			for ; ptrB < M && A[ptrA] > B[ptrB]; ptrB++ {
			}
			sum += ptrB
		}
		fmt.Println(sum)
	}
}
