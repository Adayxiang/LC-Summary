##53. Maximum Subarray
```
1. Analysis
Subarray Dp; 
prev = max(prev_old + nums[i], 0);
res = max(res_old, prev_old + num[i]);

2. Time/Space Complexity:
Space: O(1)
Time: O(n)

3. Similar Problems:
```