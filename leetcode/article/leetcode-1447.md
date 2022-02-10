# leetcode 1447 最简分数

[https://leetcode-cn.com/problems/simplified-fractions/](https://leetcode-cn.com/problems/simplified-fractions/)

### 题目大意

给你一个整数 `n` ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于 `n` 的 **最简** 分数 。分数可以以 **任意** 顺序返回。

### 思路

因为 `n` 不超过 `100` ，直接双重循环暴力就行

值得玩味的是， **如何让自己程序更快**

首先是找两个数是否有公约数，这里可以用 **辗转相除法** 来求最大公约数，这种方法是非常快的

其次，如何高效地拼接字符串？后面会展示五种拼接的方式，并测试他们的性能

**最快的方法** ：直接打表，因为 `n` 很小，所以可以把 `100` 以内所有的最简分数求出来并排好序，再直接算出 `n` 从 `1` 到 `100` 的答案。

### 五种拼接字符串的方法

##### Buffer

```go
func SimplifiedFractionsWithBuffer(n int) []string {
    ans := make([]string, 0, n*n)

    for i := 2; i <= n; i++ {
        for j := 1; j < i; j++ {
            if gcd(i, j) == 1 {
                var buffer bytes.Buffer
                buffer.WriteString(strconv.Itoa(j))
                buffer.WriteString("/")
                buffer.WriteString(strconv.Itoa(i))
                ans = append(ans, buffer.String())
            }
        }
    }

    return ans
}
```

##### Builder

```go
func SimplifiedFractionsWithBuilder(n int) []string {
    ans := make([]string, 0, n*n)

    for i := 2; i <= n; i++ {
        for j := 1; j < i; j++ {
            if gcd(i, j) == 1 {
                var buffer strings.Builder
                buffer.WriteString(strconv.Itoa(j))
                buffer.WriteString("/")
                buffer.WriteString(strconv.Itoa(i))
                ans = append(ans, buffer.String())
            }
        }
    }

    return ans
}
```

##### 直接 “+“ 号

```go
func SimplifiedFractionsWithOperate(n int) []string {
    ans := make([]string, 0, n*n)

    for i := 2; i <= n; i++ {
        for j := 1; j < i; j++ {
            if gcd(i, j) == 1 {
                ans = append(ans, strconv.Itoa(j)+"/"+strconv.Itoa(i))
            }
        }
    }

    return ans
}
```

##### Sprintf

```go
func SimplifiedFractionsWithSprintf(n int) []string {
    ans := make([]string, 0, n*n)

    for i := 2; i <= n; i++ {
        for j := 1; j < i; j++ {
            if gcd(i, j) == 1 {
                ans = append(ans, fmt.Sprintf("%v/%v", j, i))
            }
        }
    }

    return ans
}
```

##### Join

```go
func SimplifiedFractionsWithJoin(n int) []string {
    ans := make([]string, 0, n*n)

    for i := 2; i <= n; i++ {
        for j := 1; j < i; j++ {
            if gcd(i, j) == 1 {
                ans = append(ans, strings.Join([]string{strconv.Itoa(j), strconv.Itoa(i)}, "/"))
            }
        }
    }

    return ans
}
```

#### Benchmark

在 `n` 为 `100` 时

```shell
goos: darwin
goarch: amd64
pkg: gotest/leetcode
cpu: Intel(R) Core(TM) i5-7360U CPU @ 2.30GHz
BenchmarkSimplifiedFractionsWithBuffer
BenchmarkSimplifiedFractionsWithBuffer-4          146335          8973 ns/op
BenchmarkSimplifiedFractionsWithJoin
BenchmarkSimplifiedFractionsWithJoin-4            305752          3391 ns/op
BenchmarkSimplifiedFractionsWithOperate
BenchmarkSimplifiedFractionsWithOperate-4         362542          3409 ns/op
BenchmarkSimplifiedFractionsWithSprintf
BenchmarkSimplifiedFractionsWithSprintf-4         198366          5637 ns/op
BenchmarkSimplifiedFractionsWithBuilder
BenchmarkSimplifiedFractionsWithBuilder-4         410779          3204 ns/op
```

在 `n` 为 `100` 时

```shell
goos: darwin
goarch: amd64
pkg: gotest/leetcode
cpu: Intel(R) Core(TM) i5-7360U CPU @ 2.30GHz
BenchmarkSimplifiedFractionsWithBuffer
BenchmarkSimplifiedFractionsWithBuffer-4            1464        697176 ns/op
BenchmarkSimplifiedFractionsWithJoin
BenchmarkSimplifiedFractionsWithJoin-4              1836        564995 ns/op
BenchmarkSimplifiedFractionsWithOperate
BenchmarkSimplifiedFractionsWithOperate-4           2296        507883 ns/op
BenchmarkSimplifiedFractionsWithSprintf
BenchmarkSimplifiedFractionsWithSprintf-4           1488        726220 ns/op
BenchmarkSimplifiedFractionsWithBuilder
BenchmarkSimplifiedFractionsWithBuilder-4           2618        466607 ns/op
```

在 `n` 为 `1000` 时

```shell
goos: darwin
goarch: amd64
pkg: gotest/leetcode
cpu: Intel(R) Core(TM) i5-7360U CPU @ 2.30GHz
BenchmarkSimplifiedFractionsWithBuffer
BenchmarkSimplifiedFractionsWithBuffer-4               9     230211399 ns/op
BenchmarkSimplifiedFractionsWithJoin
BenchmarkSimplifiedFractionsWithJoin-4                 9     124364456 ns/op
BenchmarkSimplifiedFractionsWithOperate
BenchmarkSimplifiedFractionsWithOperate-4             15      74330119 ns/op
BenchmarkSimplifiedFractionsWithSprintf
BenchmarkSimplifiedFractionsWithSprintf-4             12      91627482 ns/op
BenchmarkSimplifiedFractionsWithBuilder
BenchmarkSimplifiedFractionsWithBuilder-4             16      68501003 ns/op
```

可以看出， `Builder` 的效率更高些。日常情况下，使用 `+` 直接连接两个字符串，用该种方式的效率也可得到保障。 `Sprintf` 的效率并不理想。

使用 `cpu profiler` 查看 `cpu` 时间占比，发现求解最大公约数的时间占总时间的 `40%` ，如果是实际业务，该部分可再优化一下。 



### 代码

[leetcode-1447.go](../1447.最简分数.go)
