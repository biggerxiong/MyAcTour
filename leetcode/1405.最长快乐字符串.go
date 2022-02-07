type pair struct {
    b byte
    c int
}

func longestDiverseString(a int, b int, c int) string {
    pairs := []pair{{'a', a}, {'b', b}, {'c', c}}
    ans := ""
    for {
        sort.Slice(pairs, func (i, j int) bool {
            return pairs[i].c > pairs[j].c
        })

        for i := range pairs {
            if pairs[i].c == 0 {
                return ans
            }
            if len(ans) < 2 || ans[len(ans)-1]!=ans[len(ans)-2] || ans[len(ans)-1]!= pairs[i].b {
                ans += string(pairs[i].b)
                pairs[i].c--
                break
            }
        }
    }
    return ans
}

