package main

import (
	"fmt"
	"strconv"
)

/*
 * @lc app=leetcode.cn id=539 lang=golang
 *
 * [539] 最小时间差
 */

// @lc code=start
func findMinDifference(timePoints []string) int {
	m := make(map[int]struct{}, 1440)
	for i := 0; i < len(timePoints); i++ {
		hour, _ := strconv.Atoi(timePoints[i][0:2])
		min, _ := strconv.Atoi(timePoints[i][3:])
		s := hour*60 + min
		if _, ok := m[s]; ok {
			return 0
		}
		m[s] = struct{}{}
	}

	last := -1
	ans := 9999
	r := 1440
	for i := 0; i <= r; i++ {
		if _, ok := m[i]; ok {
			fmt.Printf("get i:%v, last:%v\n", i, last)
			if last == -1 {
				last = i
				m[1440+i] = struct{}{}
				r += i
			} else {
				fmt.Printf("get i:%v, a:%v, b:%v\n", i, 1440-(i-last), i-last)
				ans = min(ans, i-last)
			}
			last = i

		}
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// @lc code=end
