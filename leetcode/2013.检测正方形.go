type DetectSquares struct {
    points [][]int
    m [1005][1005]int
}


func Constructor() DetectSquares {
    d := DetectSquares{
        points: make([][]int, 0, 3000),
    }
    return d
}


func (d *DetectSquares) Add(point []int)  {
    d.points = append(d.points, point)
    d.m[point[0]][point[1]]++
}


func (d *DetectSquares) Count(point []int) int {
    count := 0
    x := 0
    y := 0
    for i := 0; i < len(d.points); i++ {
        x = d.points[i][0]
        y = d.points[i][1]
        if point[1] - y != 0 && abs(point[1] - y) == abs(point[0] - x) {
            count += d.m[x][point[1]] * d.m[point[0]][y]
        }
    }
    return count
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}



/**
 * Your DetectSquares object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(point);
 * param_2 := obj.Count(point);
 */

