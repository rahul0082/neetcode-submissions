/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isBalanced(root *TreeNode) bool {
    _, ok := traverse(root)
	return ok
}

func traverse(root *TreeNode) (int, bool) {
	if root == nil {
		return 0, true
	}

	if root.Left == nil && root.Right == nil {
		return 1, true
	}

	leftH, isL := traverse(root.Left)
	rightH, isR := traverse(root.Right)

	if !isL || !isR {
		return 0, false
	}

	if abs(leftH, rightH) > 1 {
		return 0, false
	}

	h := 1 + max(leftH, rightH)
	return h, true
}

func abs(a,b int) int {
	if a > b {
		return a - b
	}
	return b - a
}

func max(a,b int) int {
	if a > b {
		return a
	}
	return b
}
