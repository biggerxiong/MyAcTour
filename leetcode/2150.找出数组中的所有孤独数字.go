func findLonely(nums []int) []int {
    n := len(nums)
    m := make(map[int]int, n)

    for _, val := range nums {
        m[val]++
    }

    ans := make([]int, 0, len(m))
    for k, v := range m {
        if v == 1 && m[k-1] == 0 && m[k+1] == 0 {
            ans = append(ans, k)
        }
    }
    return ans
}

