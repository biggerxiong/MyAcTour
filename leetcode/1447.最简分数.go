func simplifiedFractions(n int) []string {
    ans := make([]string, 0, n * n)

    for i := 2; i <= n; i++ {
        for j := 1; j < i; j++ {
            if gcd(i, j) == 1 {
                ans = append(ans, fmt.Sprintf("%d/%d", j, i))
            }
        }
    }

    return ans
}

func gcd(a, b int) int {
    if a % b == 0 {
        return b
    }
    return gcd(b, a % b)
}

