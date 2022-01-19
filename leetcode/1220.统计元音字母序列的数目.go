package main

/*
 * @lc app=leetcode.cn id=1220 lang=golang
 *
 * [1220] 统计元音字母序列的数目
 */

// @lc code=start
func countVowelPermutation(n int) int {
	m := make([][5]int, n+1)
	const MOD int = 1000000007

	m[1] = [5]int{1, 1, 1, 1, 1}
	for i := 2; i <= n; i++ {
		m[i][0] = ((m[i-1][1]+m[i-1][2])%MOD + m[i-1][4]) % MOD // a
		m[i][1] = (m[i-1][0] + m[i-1][2]) % MOD                 // e
		m[i][2] = (m[i-1][1] + m[i-1][3]) % MOD                 // i
		m[i][3] = m[i-1][2] % MOD                               // o
		m[i][4] = (m[i-1][2] + m[i-1][3]) % MOD                 // u
	}

	return ((((m[n][0]+m[n][1])%MOD+m[n][2])%MOD+m[n][3])%MOD + m[n][4]) % MOD
}

// @lc code=end
