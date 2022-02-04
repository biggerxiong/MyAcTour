func countGoodRectangles(rectangles [][]int) int {
    maxVal := -1
    for i := 0; i < len(rectangles); i++ {
        maxVal = max(maxVal, min(rectangles[i][0], rectangles[i][1]))
    }

    ans := 0
    for i := 0; i < len(rectangles); i++ {
        if min(rectangles[i][0], rectangles[i][1]) == maxVal {
            ans++
        }
    }
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

