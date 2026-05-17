import "slices"
func permuteUnique(nums []int) [][]int {
	permSet := make(map[string][]int)
	var backtrack func()
	var perm []int
	backtrack = func() {
		if len(perm) == len(nums) {
			tmp := slices.Clone(perm)
			key := fmt.Sprint(tmp)
			permSet[key] = tmp
			return
		}

		for i := 0; i < len(nums); i++ {
			if nums[i] != 999 {
				perm = append(perm, nums[i])
				tmp := nums[i]
				nums[i] = 999
				backtrack()

				perm = perm[:len(perm) - 1]
				nums[i] = tmp
			}
		}
		return
	}

	backtrack()
	var result [][]int
	for _, val := range permSet {
		result = append(result, val)
	}

	return result
}
