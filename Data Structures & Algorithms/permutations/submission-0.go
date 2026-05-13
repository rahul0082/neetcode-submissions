func permute(nums []int) [][]int {
	var result [][]int
	var pick []int
	pickSet := make(map[int]struct{})

	var generate func()

	generate = func() {

		if len(pickSet) == len(nums) {
			tmp := make([]int, len(nums))
			copy(tmp, pick)
			result = append(result, tmp)
			return
		}

		for i := range nums {
			if _, ok := pickSet[nums[i]]; !ok {
				pick = append(pick, nums[i])
				pickSet[nums[i]] = struct{}{}
			
				generate()
				
				pick = pick[:len(pick)-1]
				delete(pickSet, nums[i])
			}
		}
	}

	generate()
	return result
}