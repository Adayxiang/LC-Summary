class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int left = 0, right = n - 1;
        int leftNum = height[left], rightNum = height[right];
        int res = 0;
        while(left < right)
        {
            if(leftNum > rightNum)
            {
                res += max(0, rightNum - height[right - 1]);
                --right;
                rightNum = max(rightNum, height[right]);                
            }
            else
            {
                res += max(0, leftNum - height[left + 1]);
                ++left;
                leftNum = max(leftNum, height[left]);  
            }
        }
        return res;
    }
};