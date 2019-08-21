class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum = nums;
        for(int i = 1; i < nums.size(); ++i)
            preSum[i] += preSum[i-1];
    }
    
    void update(int i, int val) {
        int diff = preSum[i] - (i == 0 ? 0 : preSum[i - 1]) - val;
        for(int k = i; k < preSum.size(); ++k)
            preSum[k] -= diff;
    }
    
    int sumRange(int i, int j) {
        return preSum[j] - (i == 0 ? 0 : preSum[i - 1]);
    }
};