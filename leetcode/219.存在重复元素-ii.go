package main

/*
 * @lc app=leetcode.cn id=219 lang=golang
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
func containsNearbyDuplicate(nums []int, k int) bool {

	m := make(map[int]struct{}, k)
	n := len(nums)
	for i := 0; i < k && i < n; i++ {
		if _, ok := m[nums[i]]; ok {
			return true
		}
		m[nums[i]] = struct{}{}
	}

	for i := k; i < n; i++ {
		if _, ok := m[nums[i]]; ok {
			return true
		}
		m[nums[i]] = struct{}{}
		delete(m, nums[i-k])
	}

	return false
}

// @lc code=end
