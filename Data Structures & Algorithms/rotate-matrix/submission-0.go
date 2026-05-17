func rotate(matrix [][]int)  {
    transpose(matrix)
	swapColumns(matrix)
}

func transpose(m [][]int) {
	n := len(m)

	for i := 0; i<n; i++ {
		for j := i+1; j<n; j++ {
			m[i][j], m[j][i] = m[j][i], m[i][j]
		}
	}
	return
}

func swapColumns(m [][]int) {
	n := len(m)

	for j := 0; j < n/2; j++ {
		for i := 0; i<n; i++ {
			m[i][j], m[i][n-1-j] = m[i][n-1-j], m[i][j]
		}
	}
	return
}