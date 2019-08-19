class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for(auto a : nums)
        {
            sum += a;
            res = max(res, sum);
            sum = max(0, sum);
        }
        return res;
    }
};