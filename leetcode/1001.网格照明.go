func gridIllumination(n int, lamps [][]int, queries [][]int) []int {
    type Point struct {
        x int
        y int
    }
    var dir = [9][2]int {
        {0, 0},
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
    }

    m := len(lamps)
    p := make(map[Point]struct{}, m)
    h := make(map[int]int, m) // 横
    s := make(map[int]int, m) // 竖
    xzs := make(map[int]int, m) // 左上到右下
    xzx := make(map[int]int, m) // 左下到右上

    for _, v := range lamps {

        if _, ok := p[Point{v[0], v[1]}]; ok {
            continue
        }
        
        h[v[0]]++
        s[v[1]]++
        xzs[v[0]-v[1]]++
        xzx[v[0]+v[1]]++

        p[Point{v[0], v[1]}] = struct{}{}
    }

    // fmt.Printf("h:%+v\n", h)
    // fmt.Printf("s:%+v\n", s)
    // fmt.Printf("xzs:%+v\n", xzs)
    // fmt.Printf("xzx:%+v\n", xzx)

    ans := make([]int, len(queries))
    nx, ny := 0, 0
    for i, q := range queries {
        if h[q[0]]>0 || s[q[1]]>0 || xzs[q[0]-q[1]]>0 || xzx[q[0]+q[1]]>0 {
            ans[i] = 1
        } else {
            ans[i] = 0
        }

        for _, d := range dir {
            nx = q[0] + d[0]
            ny = q[1] + d[1]
            if _, ok := p[Point{nx, ny}]; ok {
                delete(p, Point{nx, ny})
                h[nx]--
                s[ny]--
                xzs[nx-ny]--
                xzx[nx+ny]--
            }
        }
    }

    return ans
}

func init() { debug.SetGCPercent(-1) }

