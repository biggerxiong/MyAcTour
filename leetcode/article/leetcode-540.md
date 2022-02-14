# leetcode 540 有序数组中的单一元素

[https://leetcode-cn.com/problems/single-element-in-a-sorted-array/](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/)

### 题目大意

在一个有序数组里，每个元素都会出现两次，唯有一个数只会出现一次，请把这个元素找出来

题目要求算法时间复杂度必须满足 `O(log n)` ，空间复杂度 `O(1)` 

### 思路

当给的数组不是有序，让你求出这个唯一出现一次的元素时，关注算法的人应该都知道可以用位运算求解，时间复杂度 `O(n)` ，空间复杂度 `O(1)` 

这道题也可以用位运算求解，不过就不满足题目要求的时间复杂度了

首先通过时间复杂度猜算法，在数组中常见的 `O(log n)` 算法有：二分查找、归并思想

其实这两个算法很像，都是每次把整个数组分成两部分，然后往更接近答案的部分求解，我也是从这个思想上得到了启发

首先，这个数组的长度必定是奇数，而且是有序的，这就说明相同的数必定相邻

对数组中间的那个元素进行分析，如果这个元素和前后两个都不相同，那么当前这个元素就唯一出现的元素；如果和前面或者后面的元素相同，就需要根据左右两个区间的长度进行区分了：如果跟左边的元素相同，并且左边的元素个数是奇数，那答案就在右边；如果左边元素个数是偶数，答案就在左边（因为答案所在的区间个数一定是奇数）

```go
    mid := n / 2
    if mid % 2 == 1 {
        if nums[mid] == nums[mid - 1] {
            return singleNonDuplicate(nums[mid+1:])
        } else if nums[mid] == nums[mid +1] {
            return singleNonDuplicate(nums[:mid])
        } else {
            return nums[mid]
        }
    } else {
        if nums[mid] == nums[mid - 1] {
            return singleNonDuplicate(nums[:mid-1])
        } else if nums[mid] == nums[mid +1] {
            return singleNonDuplicate(nums[mid+2:])
        } else {
            return nums[mid]
        }
    }
```



### 点评

这道题的思维还是很巧妙的

但最有意思的还不是题目，而是题目下的评论：

> Carl_Czerny  : 2022情人节置顶打卡题，难度不高，侮辱性极强
> 
> 杜琦拓 : 这波属于是情人节爆杀，其它数都是一对，只有你一个人夹在中间🐕
> 
> 龅牙叔 : 确实佩服选题人，几千题中偏偏找到这题作为情人节特供。


