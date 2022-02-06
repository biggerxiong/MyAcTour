func sumOfUnique(nums []int) int {
    m := make(map[int]int, len(nums))
    for _, val := range nums {
        m[val]++
    }

    sum := 0
    for k, v := range m {
        if v == 1 {
            sum += k
        }
    }
    return sum
}

