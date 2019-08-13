class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if((l1 + l2) % 2)
        {
            return helper(nums1, nums2, (l1 + l2) / 2 + 1, 0, 0);
        }
        else
        {
            return (helper(nums1, nums2, (l1 + l2) / 2, 0, 0) + helper(nums1, nums2, (l1 + l2) / 2 + 1, 0, 0)) / 2.0;
        }
    }
    
    int helper(vector<int>& nums1, vector<int>& nums2, int k, int index1, int index2)
    {
        if(index1 >= nums1.size()) return nums2[index2 + k - 1];
        if(index2 >= nums2.size()) return nums1[index1 + k - 1];
        if(k == 1) return min(nums1[index1], nums2[index2]);
        int number1 = (index1 + k / 2 - 1 >= nums1.size()) ? INT_MAX : nums1[index1 + k / 2 - 1];
        int number2 = (index2 + k / 2 - 1 >= nums2.size()) ? INT_MAX : nums2[index2 + k / 2 - 1];
        if(number1 < number2)
        {
            return helper(nums1, nums2, k - k / 2, index1 + k / 2, index2);
        }
        else
        {
            return helper(nums1, nums2, k - k / 2, index1, index2 + k / 2);
        }
    }
};



/*
log -> bs





*/