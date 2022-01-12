package main

/*
 * @lc app=leetcode.cn id=334 lang=golang
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
func increasingTriplet(nums []int) bool {

	a := int(1<<31 - 1)
	b := a
	for i := 0; i < len(nums); i++ {
		if nums[i] <= a {
			a = nums[i]
		} else if nums[i] <= b {
			b = nums[i]
		} else if nums[i] > b {
			return true
		}
	}
	return false
}

// @lc code=end
