package main

import "fmt"

/*
 * @lc app=leetcode.cn id=1629 lang=golang
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start
func slowestKey(releaseTimes []int, keysPressed string) byte {
	n := len(keysPressed)

	maxTime := -1
	ans := byte(0)
	startTime := 0
	for i := 0; i < n; i++ {
		t := &KeyWithTime{keysPressed[i], releaseTimes[i]}
		lastTime := t.release - startTime
		startTime = t.release
		// fmt.Printf("t:%v, release:%v, startTime:%v, lastTime:%v, maxTime:%v\n", t, t.release, startTime, lastTime, maxTime)
		if lastTime > maxTime {
			ans = t.key
			maxTime = lastTime
		} else if lastTime == maxTime && ans < t.key {
			ans = t.key
		}
	}
	return ans
}

type KeyWithTime struct {
	key     byte
	release int
}

func (k *KeyWithTime) String() string {
	return fmt.Sprintf("KeyWithTime{key:%c, release:%v}", k.key, k.release)
}

type KeyWithTimes []*KeyWithTime

func (k KeyWithTimes) Len() int { return len(k) }

func (k KeyWithTimes) Swap(i, j int) { k[i], k[j] = k[j], k[i] }

func (k KeyWithTimes) Less(i, j int) bool {
	return k[i].release < k[j].release
}

// @lc code=end
