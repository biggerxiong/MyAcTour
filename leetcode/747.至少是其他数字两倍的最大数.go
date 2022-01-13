package main

import "fmt"

/*
 * @lc app=leetcode.cn id=747 lang=golang
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
func dominantIndex(nums []int) int {

	if len(nums) == 0 {
		return -1
	} else if len(nums) == 1 {
		return 0
	}

	max := -1
	maxIndex := 0
	for i := 0; i < len(nums); i++ {
		if max < nums[i] {
			max = nums[i]
			maxIndex = i
		}
	}

	fmt.Printf("max:%v, maxIndex:%v\n", max, maxIndex)

	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 && nums[i] != max && max/nums[i] < 2 {
			fmt.Printf("nums[i]:%v, max:%v\n", nums[i], max)
			return -1
		}
	}
	return maxIndex
}

// @lc code=end
