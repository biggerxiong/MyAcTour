func rearrangeArray(nums []int) []int {
    n := len(nums)
    v := make([]int, 0, n)
    f := make([]int, 0, n)

    for _, val := range nums {
        if val > 0 {
            v = append(v, val)
        } else {
            f = append(f, val)
        }
    }

    ans := make([]int, 0, n)
    for i := 0; i < n / 2; i++ {
        ans = append(ans, v[i])
        ans = append(ans, f[i])
    }
    return ans
}
