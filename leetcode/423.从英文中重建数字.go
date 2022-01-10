package main

/*
 * @lc app=leetcode.cn id=423 lang=golang
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
func originalDigits(s string) string {
	var dict [126]int
	for i := range s {
		dict[s[i]]++
	}

	var ans [10]int

	ans[0] = dict['z']
	ans[2] = dict['w']
	ans[8] = dict['g']
	ans[6] = dict['x']
	ans[3] = dict['t'] - ans[2] - ans[8]
	ans[4] = dict['r'] - ans[3] - ans[0]
	ans[7] = dict['s'] - ans[6]
	ans[1] = dict['o'] - ans[4] - ans[2] - ans[0]
	ans[5] = dict['v'] - ans[7]
	ans[9] = dict['i'] - ans[8] - ans[6] - ans[5]

	count := 0
	for i := 0; i < 10; i++ {
		count += ans[i]
	}

	str := make([]byte, 0, count)
	for i := 0; i < 10; i++ {
		for j := 0; j < ans[i]; j++ {
			str = append(str, '0'+byte(i))
		}
	}
	return string(str)
}

// @lc code=end
