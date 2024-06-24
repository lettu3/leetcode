# Division and Array Subsets
### Explanation

in the `solution` function, a different number of integer array `nums` and integer value `target` were given as arguments. Please write a program to return the maximum value of the subset as the return value of the solution function in
integer that satisfies the conditions where the elements of `nums` array are combined and the sum of any two numbers is not divisible by target. However, a subset consisting of a single element must satisfy the above condition.


## Examples
---
### Example 1:
```
Input: nums = [1, 7, 2, 4], target = 3
Output: 3
Explanation: Since the subset '[1, 7, 4]' satisfies the condition where none of '1 + 7', '1 + 4', '7 + 4' are divisible by 3 and as there is no larger subset than itself, the answer is '3'
```

### Example 2:
```
Input: nums = [1], target = 3
Output: 1
Explanation: Since the only subset '[1]' cannot form a combination of two numbers, it automatically satisfies the condition that the sum of any two numbers is not divisible by 'target'
```

### Constraints
- 1 <= `len(nums)` <= 10000
- `nums[i]` is any satisfying 1 <= `nums[i]` <= inf
- Each element of `nums` is a different `int`.
