var n, m int
var vis [][]bool
var g [][]int
var dir [4][2]int = [4][2]int {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
}

func numEnclaves(grid [][]int) int {
    n = len(grid)
    m = len(grid[0])
    vis = make([][]bool, n)
    for i := 0; i < n; i++ {
        vis[i] = make([]bool, m)
    }
    g = grid

    for i := 0; i < m; i++ {
        if check(0, i) {
            vis[0][i] = true
            dfs(0, i)
        }
        if (check(n - 1, i)) {
            vis[n - 1][i] = true
            dfs(n - 1, i)
        }
    }
    for i := 0; i < n; i++ {
        if check(i, 0) {
            vis[i][0] = true
            dfs(i, 0)
        }
        if check(i, m - 1) {
            vis[i][m - 1] = true
            dfs(i, m - 1)
        }
    }

    ans := 0
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] == 1 && !vis[i][j] {
                ans++
            }
        }
    }
    return ans
}

func dfs(x, y int) {
    // fmt.Printf("dfs: x:%v, y:%v\n", x, y)
    nx, ny := 0, 0
    for i := 0; i < 4; i++ {
        nx = x + dir[i][0]
        ny = y + dir[i][1]
        if check(nx, ny) {
            vis[nx][ny] = true
            dfs(nx, ny)
        }
    }
}

func check(x, y int) bool {
    if x < 0 || y < 0 || x >= n || y >= m {
        return false
    }
    if vis[x][y] || g[x][y] == 0 {
        return false
    }
    return true
}


