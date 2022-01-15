package leetcode

/*
 * @lc app=leetcode.cn id=1716 lang=golang
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
func totalMoney(n int) int {
	ans := 0
	k := n / 7
	ans += ((1+k)*k/2 + k*3) * 7
	// fmt.Printf("k:%v, ans:%v\n", k, ans)
	t := n % 7
	ans += k*t + (1+t)*t/2
	// fmt.Printf("t:%v, ans:%v\n", t, ans)
	return ans
}

// @lc code=end
