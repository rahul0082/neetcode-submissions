func countBits(n int) []int {
	var result []int

	for i := 0; i <= n; i++ {
		b := bit(i)
		result = append(result, b)
	}

	return result
}

func bit(n int) int {
	var ans int 
	for i := 0; i < 32; i++ {
		if (n & (1 << i)) > 0 {
			ans++
		}
	}
	return ans
}
