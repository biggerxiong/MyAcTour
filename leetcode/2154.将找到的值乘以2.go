func findFinalValue(nums []int, original int) int {
    m := make(map[int]struct{}, len(nums)) 
    
    for _, v := range nums {
        m[v] = struct{}{}
    }
    
    for true {
        if _, ok := m[original]; ok {
            original *= 2
        } else {
            break
        }
    }
    return original
}

