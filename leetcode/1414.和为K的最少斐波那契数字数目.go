func findMinFibonacciNumbers(k int) int {
    fibs := make([]int64, 0, 45)
    fibs = append(fibs, 1)
    fibs = append(fibs, 1)
    for i := 2; fibs[i - 1] < int64(1000000000); i++ {
        fibs = append(fibs, fibs[i - 1] + fibs[i - 2])
    }
    // fmt.Printf("len:%v, vals:%v\n", len(fibs), fibs)

    cnt := 0
    n := int64(k)
    for i := 44; i >= 0 && n > 0; i-- {
        for n >= fibs[i] {
            n -= fibs[i]
            cnt++
        }
    }

    return cnt
}

// func bs(arr []int, val int) index int {
//     l, r := 0, len(arr)

//     for l < 
// }



