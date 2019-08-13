##K Closest Points to Origin
###Method 1: Priority_Queue
```
1. Analysis
Intuitive question: inspect rewriting the compare function:
struct cmp
{
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
    }
};

2. Time/Space Complexity:
Space: O(n)
Time: O(max(Klogn, n))

3. Similar Problems:
```
