class Solution {
private:
    struct cmp
    {
        bool operator()(const vector<int> &a, const vector<int> &b) const
        {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        }
    };
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(auto a : points)
        {
            pq.push(a);
        }
        while(K > 0 && !pq.empty())
        {
            res.push_back(pq.top());pq.pop();
            --K;
        }
        return res;
    }
};