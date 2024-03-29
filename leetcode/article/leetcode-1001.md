# leetcode 1001 网格照明

[https://leetcode-cn.com/problems/grid-illumination/](https://leetcode-cn.com/problems/grid-illumination/) 

### 题目大意

在一个由灯泡组成的二维表格中，已知一盏灯打开后可以照亮它自己和其所在行、列、两个写对角线的所有格子。现在给你一些打开的灯泡位置 `lamps` 和 要查询的方格位置 `queries` ，对于每一次查询，你需要判断查询的方格是否被照亮；每判断完一次，就把该位置和与它相邻的八个位置上的灯泡关闭。

### 思路

读懂题以后，可以判断出，这题不是考什么算法，而是让你自己设计出一个数据结构，这个数据结构支持查询同一行、列、以及斜对角线，并且要支持删除操作。

看数据范围，表格长宽都在 $10^9$ 以内，直接建二维数组是不现实的。给出的 `lamps` 和 `queries` 也都不超过 $2*10^4$ ，排除双重循环暴力去查。

然后我考虑是否可以用位运算去压缩这个图，但是图太大，并且后续的查询也很麻烦。所以换个思路。

既然一个灯泡影响的是所在行、列、以及两个斜对角线，那么可以用四个 `map` 来记录每一行、列、对角线是否被照亮（这里其实记录的是照亮了几次）。查询时只要在这四个 `map` 里找这个点是否被照亮就行，复杂度 `O(1)` 。删除时，对于每个要删除的位置，先判断这盏灯是否是开的，如果是开的就在四个 `map` 中将照亮的次数减一。

### 优化记录

1. 正常写，时间 208 ms，内存 16.8 MB

2. 在创建四个 map 时，提前分配好长度为 `lamps` 的空间，时间 184 ms，内存 14 MB。原理：降低了中途重新分配 map 空间的耗时

3. 设置 `debug.SetGCPercent(-1)` ，时间 160 ms，内存 63.8 MB。原理：设置不自动 GC，降低 GC 的耗时

4. 存放答案的 ans 数组，从预先分配内存 `ans := make([]int, 0, len(queries))` 改为直接初始化所有答案为 0 `ans := make([]int, len(queries))` 。时间 140 ms （超过了 100% 的答案），内存 63.8 MB。原理：append 中会对切片容量进行判断，也会占用时间



### 代码

[leetcode-1001.go](../1001.网格照明.go)




