type Node struct {
    index int
    dir byte
    step int
}

func pushDominoes(dominoes string) string {
    n := len(dominoes)
    visStep := make([]int, n)
    ans := []byte(dominoes)

    q := make([]Node, n)
    head, tail := 0, 0

    for i := 0; i < n; i++ {
        if dominoes[i] != '.' {
            q[tail] = Node{i, dominoes[i], 1}
            tail++
            visStep[i] = 1
        }
    }

    var front Node
    var nextIndex int
    for head < tail {
        front = q[head]
        head++

        if front.dir == '.' {
            continue
        }

        nextIndex = front.index - 1
        if front.dir == 'L' && nextIndex >= 0 {
            if ans[nextIndex] == '.' {
                ans[nextIndex] = front.dir
                visStep[nextIndex] = front.step + 1

                q[tail] = Node{nextIndex, ans[nextIndex], front.step+1}
                tail++
            } else if visStep[nextIndex] == front.step + 1 && ans[nextIndex] != front.dir {
                ans[nextIndex] = '.'
            }
        }

        nextIndex = front.index + 1 
        if front.dir == 'R' && nextIndex < n {
            if ans[nextIndex] == '.' {
                ans[nextIndex] = front.dir
                visStep[nextIndex] = front.step + 1

                q[tail] = Node{nextIndex, ans[nextIndex], front.step+1}
                tail++
            } else if visStep[nextIndex] == front.step + 1 && ans[nextIndex] != front.dir {
                ans[nextIndex] = '.'
            }
        }
    }

    return string(ans)
}

