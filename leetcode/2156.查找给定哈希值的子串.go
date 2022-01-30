var ps []int64

func subStrHash(s string, power int, modulo int, k int, hashValue int) string {
    ps = make([]int64, k)
    ps[0] = 1
    m := int64(modulo)
    p := int64(power)
    for i := 1; i < k; i++ {
        ps[i] = (ps[i - 1] * p) % m
    }
    
    for i := 0; i + k - 1 < len(s); i++ {
        if hash(s[i:i+k], m) == hashValue {
            return s[i:i+k]
        }
    }
    return s[:k]
}

func hash(s string, m int64) int {
    // fmt.Printf("hash:%v, m:%v, ps:%v", s, m, ps)
    ans := int64(0)
    for i := 0; i < len(s); i++ {
        ans += (ps[i] * int64(s[i]-'a'+1)) % m
        ans = ans % m
    }
    // fmt.Printf(" val:%v\n", ans)
    return int(ans)
}


