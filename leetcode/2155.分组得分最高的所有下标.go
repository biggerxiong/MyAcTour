func maxScoreIndices(nums []int) []int {
    l0, r0, l1, r1 := 0, 0, 0, 0
    for _, v := range nums {
        if v == 0 {
            r0++
        } else {
            r1++
        }
    }
    
    ans := l0+r1
    
    v := 0
    for i := 1; i < len(nums) + 1; i++ {
        v = nums[i - 1]
        if v == 0 {
            l0++
            r0--
        } else {
            l1++
            r1--
        }
        ans = max(ans, l0+r1)
    }
    fmt.Printf("ans = %v\n", ans)
    
    l0, r0, l1, r1 = r0, l0, r1, l1
    
    s := make([]int, 0, 10)
    if ans == l0 + r1 {
        s = append(s, 0)
    }
    for i := 1; i < len(nums) + 1; i++ {
        v = nums[i - 1]
        if v == 0 {
            l0++
            r0--
        } else {
            l1++
            r1--
        }
        if ans == l0 + r1 {
            s = append(s, i)
        }
    }
    return s
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}


