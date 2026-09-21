# 3524. Find X Value of Array

**Difficulty:** Medium  
**Topics:** Array, Dynamic Programming, Prefix Product, Modular Arithmetic

## Problem Statement

You are given an array of positive integers `nums` and a positive integer `k`.

You may perform the following operation exactly once:

- Remove a prefix and a suffix from `nums`.
- The removed prefix and suffix must not overlap.
- The remaining array must be non-empty.
- Either the prefix or the suffix may be empty.

After the operation, let the remaining elements form a contiguous subarray. The **x-value** of `nums` is the number of valid operations for which the product of the remaining elements has a remainder of `x` when divided by `k`.

Return an array `result` of size `k`, where:

```text
result[x] = the number of valid operations whose remaining product % k == x
```

for every `0 <= x < k`.

## Definitions

- A **prefix** is a subarray that starts at the beginning of the array.
- A **suffix** is a subarray that ends at the end of the array.
- Removing a prefix and a suffix leaves one non-empty contiguous subarray.

## Examples

### Example 1

```text
Input:  nums = [1, 2, 3, 4, 5], k = 3
Output: [9, 2, 4]
```

Explanation:

- For `x = 0`, the valid remaining subarrays are those whose product is divisible by `3`. There are `9` such operations.
- For `x = 1`, the possible remaining arrays are `[1]` and `[4]`, so there are `2` operations.
- For `x = 2`, the possible remaining arrays are `[1, 2]`, `[2]`, `[4, 5]`, and `[5]`, so there are `4` operations.

### Example 2

```text
Input:  nums = [1, 2, 4, 8, 16, 32], k = 4
Output: [18, 1, 2, 0]
```

Explanation:

- For `x = 0`, there are `18` valid operations.
- For `x = 1`, the only possible remaining array is `[1]`.
- For `x = 2`, the possible remaining arrays are `[1, 2]` and `[2]`.
- For `x = 3`, no remaining subarray has a product with remainder `3` modulo `4`.

### Example 3

```text
Input:  nums = [1, 1, 2, 1, 1], k = 2
Output: [9, 6]
```

## Constraints

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 5`

## Notes

Every valid operation corresponds to choosing one non-empty contiguous subarray of `nums` to keep. Therefore, the task is equivalent to counting all non-empty subarrays by the remainder of their product modulo `k`.
