##3Sum
###Method 1: Set
```
1. Analysis
Similar to two sum, use set to record previous answer, use hashSet to remove duplicate. It is not an optinional choice as it requires extra constant time(hashSet and sort the answer) and extra sapce.
2. Time/Space Complexity:
Space: O(n)
Time: O(n^2)

3. Similar Problems:
```

###Method 2: Two Pointer
```
1. Analysis
Keep the first element nums[i], then move left = i + 1, right = n - 1 to search all the elements between them. The method to remove duplicate is a good trick that if a result satisfy the requirement, then all duplicate is no need to search;

while(left + 1 < right && nums[left] == nums[left+1]) ++left;
while(left + 1 < right && nums[right] == nums[right-1]) --right;
++left, --right;

2. Time/Space Complexity:
Space: O(1)
Time: O(n^2)

3. Similar Problems:
18.4Sum
1.2Sum
```
