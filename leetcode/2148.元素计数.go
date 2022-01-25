func countElements(nums []int) int {
    min, max := 100005, -100005
    for _, val := range nums {
        if min > val {
            min = val
        }
        if max < val {
            max = val
        }
    }

    cnt := 0
    for _, val := range nums {
        if val == min || val == max {
            cnt++
        }
    }
    return len(nums) - cnt
}

