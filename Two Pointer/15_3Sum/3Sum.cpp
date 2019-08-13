class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i)
        {
            int left = i + 1, right = n - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    vector<int> tmp = {nums[i], nums[left], nums[right]};
                    res.push_back(tmp);
                    while(left + 1 < right && nums[left] == nums[left+1]) ++left;
                    while(left + 1 < right && nums[right] == nums[right-1]) --right;
                    ++left, --right;
                }
                else if(sum > 0)
                {
                    --right;
                }
                else
                {
                    ++left;
                }
            }
            while(i + 1 < n && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
};