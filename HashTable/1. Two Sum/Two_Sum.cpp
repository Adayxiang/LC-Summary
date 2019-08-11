class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> store;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(store.count(target - nums[i]))
            {
                res.push_back(store[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            store[nums[i]] = i;
        }
        return res;
    }
};