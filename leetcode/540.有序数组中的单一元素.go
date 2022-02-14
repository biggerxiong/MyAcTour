func singleNonDuplicate(nums []int) int {
    if len(nums) == 1 {
        return nums[0]
    }
    // fmt.Printf("nums:%v\n", nums)

    n := len(nums)
    mid := n / 2 // 5 / 2 == 2
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
}

