func countKDifference(nums []int, k int) int {
    n := len(nums)
    ans := 0
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            if abs(nums[i] - nums[j]) == k {
                ans++
            }
        }
    }
    return ans
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

