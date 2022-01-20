package main

/*
 * @lc app=leetcode.cn id=2029 lang=golang
 *
 * [2029] 石子游戏 IX
 */

// @lc code=start
func stoneGameIX(stones []int) bool {
	var cnt [3]int = [3]int{0, 0, 0}
	for _, val := range stones {
		cnt[val%3]++
	}

	if cnt[0]%2 == 0 {
		return cnt[1] >= 1 && cnt[2] >= 1
	}

	return cnt[1]-cnt[2] > 2 || cnt[2]-cnt[1] > 2
}

// @lc code=end
