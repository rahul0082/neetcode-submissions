func rob(nums []int) int {
	n := len(nums)

    money := make([]int, n+1)
	money[1] = nums[0]
	
	for i := 2; i < n+1; i++ {
		money[i] = max(money[i-1], money[i-2] + nums[i-1])
	}

	return money[n]
}
