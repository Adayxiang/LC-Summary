class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        vector<int> res(n, INT_MAX);
        int cur = 0;
        for(int i = 0; i < n; ++i)
        {
            cur = max(cur, height[i]);
            res[i] = min(cur, res[i]);
        }
        
        cur = 0;
        for(int i = 0; i < n; ++i)
        {
            cur = max(cur, height[n - i - 1]);
            res[n - i - 1] = min(cur, res[n - i - 1]);
        }
        
        int resNum = 0;
        for(int i = 0; i < n; ++i)
        {
            resNum += res[i] - height[i];
        }
        return resNum;
    }
};