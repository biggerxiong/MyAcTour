func maximumGood(statements [][]int) (ans int) {
nnn:
	for i := 1; i < 1<<len(statements); i++ {
		cnt := 0
		for j, rows := range statements {
			if i>>j&1 == 1 {
				for k, st := range rows {
					if st < 2 && st != i>>k&1 {
						continue nnn
					}
				}
				cnt++
			}
		}
		if cnt > ans {
			ans = cnt
		}
	}
	return
}

