/*
 * @lc app=leetcode.cn id=208 lang=golang
 *
 * [208] 实现 Trie (前缀树)
 */

package main

import "runtime/debug"

// @lc code=start

func init() {
	debug.FreeOSMemory()
	debug.SetGCPercent(-1)
}

type Trie struct {
	exists bool
	childs []*Trie
}

/** Initialize your data structure here. */
func Constructor() Trie {
	trie := Trie{}
	trie.exists = false
	trie.childs = make([]*Trie, 26)
	return trie
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	if word == "" {
		this.exists = true
		return
	}
	if this.childs == nil {
		this.childs = make([]*Trie, 26)
	}
	if len(word) > 0 {
		if this.childs[word[0]-'a'] != nil {
			this.childs[word[0]-'a'].Insert(word[1:])
		} else {
			this.childs[word[0]-'a'] = &Trie{}
			this.childs[word[0]-'a'].Insert(word[1:])
		}
	}
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	if word == "" && this.exists {
		return true
	}
	if this.childs == nil {
		return false
	}
	if len(word) > 0 {
		if this.childs[word[0]-'a'] != nil {
			return this.childs[word[0]-'a'].Search(word[1:])
		} else {
			return false
		}
	}
	return false
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	if prefix == "" {
		return true
	}
	if this.childs == nil {
		return false
	}
	if len(prefix) > 0 {
		if this.childs[prefix[0]-'a'] != nil {
			return this.childs[prefix[0]-'a'].StartsWith(prefix[1:])
		} else {
			return false
		}
	}
	return false
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end
