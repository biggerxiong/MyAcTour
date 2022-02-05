var ans int
var n, m int
var vis map[int]map[int]struct{}
var g [][]int
var dir [4][2]int

func getMaximumGold(grid [][]int) int {
    ans = 0
    n = len(grid)
    m = len(grid[0])
    g = grid
    dir = [4][2]int{
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    }
    vis = make(map[int]map[int]struct{}, n)
    for i := 0; i < n; i++ {
        vis[i] = make(map[int]struct{}, m)
    }

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] == 0 {
                continue
            }
            if _, ok := vis[i][j]; !ok {
                vis[i][j] = struct{}{}
                dfs(i, j, g[i][j])
                delete(vis[i], j)
            }
        }
    }
    return ans
}

func dfs(x, y, sum int) {
    // fmt.Printf("x:%v, y:%v, sum:%v\n", x, y, sum)
    if sum > ans {
        ans = sum
    }

    for i := 0; i < 4; i++ {
        nx := x + dir[i][0]
        ny := y + dir[i][1]
        if (check(nx, ny)) {
            vis[nx][ny] = struct{}{}
            dfs(nx, ny, sum + g[nx][ny])
            delete(vis[nx], ny)
        }
    }
}

func check(x, y int) bool {
    if x < 0 || y < 0 || x >= n || y >= m {
        return false
    }
    if _, ok := vis[x][y]; ok {
        return false
    }
    if g[x][y] == 0 {
        return false
    }
    return true
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

