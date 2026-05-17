func countComponents(n int, edges [][]int) int {
    g := make([][]int, n)
	for _, edge := range edges {
		u, v := edge[0], edge[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	visited := make([]bool, n)
	var numComp int

	for i := 0; i<n; i++ {
		if !visited[i] {
			numComp++
			bfs(g, visited, i)
		}
	}

	return numComp
}

func bfs(e [][]int, visited []bool, s int) {
	var q []int
	visited[s] = true
	q = append(q, s)

	for len(q) > 0 {
		idx := q[0]
		q = q[1:]

		for _, j := range e[idx] {
			if !visited[j] {
				visited[j] = true
				q = append(q,j)
			}
		}
	}

	return
} 
