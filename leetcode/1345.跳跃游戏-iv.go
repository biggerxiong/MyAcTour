package main

import "fmt"

/*
 * @lc app=leetcode.cn id=1345 lang=golang
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
func minJumps(arr []int) int {
	n := len(arr)
	if n == 1 {
		return 0
	} else if n == 2 || arr[0] == arr[n-1] {
		return 1
	}

	distCount := 0
	m := make(map[int][]int, 50000)

	for i := n - 1; i >= 0; i-- {
		if _, ok := m[arr[i]]; !ok {
			distCount++
			m[arr[i]] = make([]int, 0, 10)
		}
		m[arr[i]] = append(m[arr[i]], i)
	}

	book := make(map[int]struct{}, n)
	used := make(map[int]struct{}, distCount)
	s, e := 0, n-1
	q := NewQueue(n)
	q.Push(&Q{s, 0})
	book[s] = struct{}{}

	for !q.Empty() {
		f := q.Front()
		q.Pop()
		// fmt.Println(f)
		if f.index == e {
			return f.step
		}

		if f.index < 0 || f.index >= n {
			continue
		}

		nextIndex := f.index + 1
		if _, ok := book[nextIndex]; !ok {
			q.Push(&Q{nextIndex, f.step + 1})
			book[nextIndex] = struct{}{}
		}

		nextIndex = f.index - 1
		if _, ok := book[nextIndex]; !ok {
			q.Push(&Q{nextIndex, f.step + 1})
			book[nextIndex] = struct{}{}
		}

		if _, ok := used[arr[f.index]]; !ok {
			for _, nextIndex := range m[arr[f.index]] {
				if _, ok := book[nextIndex]; !ok {
					q.Push(&Q{nextIndex, f.step + 1})
					book[nextIndex] = struct{}{}
				}
			}
			used[arr[f.index]] = struct{}{}
		}

	}
	return 0
}

type Q struct {
	index int
	step  int
}

func (q *Q) String() string {
	return fmt.Sprintf("Q{index:%v, step:%v}", q.index, q.step)
}

type Queue struct {
	head int
	tail int
	data []*Q
}

func NewQueue(length int) *Queue {
	que := make([]*Q, 0, length)
	return &Queue{0, 0, que}
}

func (q *Queue) Push(t *Q) {
	q.data = append(q.data, t)
	q.tail++
}

func (q *Queue) Front() *Q {
	return q.data[q.head]
}

func (q *Queue) Pop() {
	q.head++
}

func (q *Queue) Empty() bool {
	return q.head >= q.tail
}

// @lc code=end
