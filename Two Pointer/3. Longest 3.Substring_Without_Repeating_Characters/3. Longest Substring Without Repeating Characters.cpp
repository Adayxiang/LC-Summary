class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> store(256,0);
        int left = 0, right = 0;
        int n = s.size();
        int res = 0;
        while(right < n)
        {
            while(store[s[right]] == 1)
            {
                store[s[left++]]--;
            }
            res = max(res, right - left + 1);
            store[s[right++]]++;
        }
        return res;
    }
};